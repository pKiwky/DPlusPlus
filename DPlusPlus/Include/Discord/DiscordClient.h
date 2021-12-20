#pragma once

#include <iostream>
#include <cpprest/ws_client.h>

#include "Discord/IEvents.h"
#include "Discord/Event.h"
#include "Utils/Utility.h"

namespace DPlusPlus {

	using namespace web;
	using namespace web::http;
	using namespace web::websockets::client;

	enum class OPType {
		kDispatch			/**/ = 0,
		kHeartbeat			/**/ = 1,
		kIdentify			/**/ = 2,
		kStatusUpdate		/**/ = 3,
		kVoiceStateUpdate	/**/ = 4,
		kVoiceServerPing	/**/ = 5,
		kResume				/**/ = 6,
		kReconect			/**/ = 7,
		kRequestGuildMember	/**/ = 8,
		kInvalidSession		/**/ = 9,
		kHello				/**/ = 10,
		kHeartbeatAck		/**/ = 11
	};

	class DiscordClient: public IEvents {

	public:
		DiscordClient();

	public:
		/**
		 * Run new instance of this bot.
		 *
		 * @token		Your private bot token.
		 * @TODO: Intents
		 */
		void Run(const std::string &token);

		/**
		 * Set session string value from outside this object.
		 * Used in ReadyEventArgs to cache session to current client.
		 */
		void SetSession(const std::string &session);

	private:
		/**
		 * Intercepts and processes the payload
		 *
		 * @message		WebSocket message received.
		 */
		void ProccesResponse(websocket_incoming_message message);

		/**
		 * Format identity json and send through WebSocket.
		 */
		void ProcessIdentity();

		/**
		 * Process the main discord event: OnGuildCreate, OnMessageCreate ... all events.
		 *
		 * @json		Payload result as json.
		 */
		void ProcessTypeDispatch(const nJson &json);

		/**
		 * Process bot hello event.
		 *
		 * @json		Payload result as json.
		 */
		void ProcessTypeHello(const nJson &json);

		/**
		 * Used to replay missed events when a disconnected client resumes.
		 */
		void ProcessTypeResume();

	private:
		websocket_callback_client m_Client;
		uint32_t m_LastSignal;
		uint32_t m_HeartbeatInterval;
		bool m_IsReady;
		std::string m_Token;
		std::string m_SessionId;
		std::thread *m_HeartbeatThreat;

	};

}
