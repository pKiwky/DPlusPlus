#include "Discord/DiscordClient.h"

#include <boost/regex.hpp>

namespace DPlusPlus {

	const std::map<std::string, Event *> EventsMap = {
		{ "READY"			, new ReadyEventArgs()			},
		{ "MESSAGE_CREATE"	, new MessageCreateEventArgs()	},
		{ "MESSAGE_UPDATE"	, new MessageUpdateEventArgs()	},
		{ "MESSAGE_DELETE"	, new MessageDeleteEventArgs()	},
		{ "GUILD_CREATE"	, new GuildCreateEventArgs()	},
		{ "GUILD_UPDATE"	, new GuildUpdateEventArgs()	}
	};

	DiscordClient::DiscordClient() {}

	void DiscordClient::Run(const std::string &token) {
		Logger::Inst()->Init();

		boost::regex expr{"[a-zA-Z0-9_-]{24}.[a-zA-Z0-9_-]{6}.[a-zA-Z0-9_-]{27}"};
		//boost::regex expr{"[a-zA-Z0-9_-]{24}\.[a-zA-Z0-9_-]{6}\.[a-zA-Z0-9_-]{27}"};
		if(boost::regex_match(token, expr) == false) {
			DPP_LOG_ERROR("[DiscordClient::Run] Invalid bot token");
			return;
		}

		m_LastSignal = 0;
		m_IsReady = false;
		m_Token = token;
		m_HeartbeatThreat = nullptr;

		m_Client.set_message_handler([&](websocket_incoming_message msg) {
			try {
				ProccesResponse(msg);
			} catch(const std::exception &e) {
				DPP_LOG_ERROR("[DiscordClient::Run] {0}", e.what());
			}
		});

		web::uri uri = web::uri(utility::conversions::to_string_t(DISCORD_GATEWAY_URL));
		m_Client.connect(uri).then([&]() {
			ProcessIdentity();
		});
	}

	void DiscordClient::SetSession(const std::string &session) {
		m_SessionId = session;
	}

	void DiscordClient::ProccesResponse(websocket_incoming_message message) {
		DPP_LOG_DEBUG("[DiscordClient::ProccesResponse] Received new message");

		nJson json = nJson::parse(message.extract_string().get());
		int8_t op = json["op"];

		switch(op) {
			case (int8_t)OPType::kDispatch: ProcessTypeDispatch(json); break;
			case (int8_t)OPType::kHello: ProcessTypeHello(json); break;
			case (int8_t)OPType::kResume: ProcessTypeResume(); break;
		}
	}

	void DiscordClient::ProcessIdentity() {
		DPP_LOG_DEBUG("[DiscordClient::ProcessClientIdentity] Processing identity...");
		websocket_outgoing_message message;
		nJson json;

		json["op"] = (int8_t)OPType::kIdentify;
		json["d"] = {
			{"token", m_Token},
			{"intents", 513},
			{"properties", {
				{"$os", "Windows"},
				{"$browser", "DPlusPlus"},
				{"$device", "DPlusPlus"},
			}},
			{"compress", false},
			{"large_threshold", 250},
		};

		message.set_utf8_message(to_string(json));
		m_Client.send(message);
	}

	void DiscordClient::ProcessTypeDispatch(const nJson &json) {
		const std::string type = json["t"];
		m_LastSignal = json["s"];

		auto it = EventsMap.find(type);
		if(it != EventsMap.end()) {
			Event *discordEvent = it->second;
			discordEvent->Execute(this, json["d"]);
		}
	}

	void DiscordClient::ProcessTypeHello(const nJson &json) {
		DPP_LOG_DEBUG("[DiscordClient::ProcessTypeHello] Main method");

		nJson data = json["d"];
		m_HeartbeatInterval = (int32_t)data["heartbeat_interval"];
		m_IsReady = true;

		if(m_HeartbeatThreat != nullptr) {
			delete m_HeartbeatThreat;
			m_HeartbeatThreat = nullptr;
		}

		m_HeartbeatThreat = new std::thread([&] {
			while(true) {
				try {
					std::this_thread::sleep_for(std::chrono::milliseconds(m_HeartbeatInterval));

					DPP_LOG_DEBUG("[DiscordClient::ProcessTypeHello] Process client heartbeat");

					websocket_outgoing_message msg;
					nJson json;

					json["op"] = (int)OPType::kHeartbeat;
					json["d"] = m_LastSignal;

					OnHeartbeat(time(nullptr));

					msg.set_utf8_message(to_string(json));
					m_Client.send(msg);
				} catch(std::exception &e) {
					DPP_LOG_ERROR("[DiscordClient::ProcessTypeHello] {0}", e.what());
				}
			}
		});

		(*m_HeartbeatThreat).detach();

		OnHello(m_HeartbeatInterval);
	}

	void DiscordClient::ProcessTypeResume() {
		websocket_outgoing_message message;
		nJson json;

		json["op"] = (int8_t)OPType::kResume;
		json["d"] = {
			{"token", m_Token},
			{"session_id", m_SessionId},
			{"seq", m_LastSignal}
		};
	}

}