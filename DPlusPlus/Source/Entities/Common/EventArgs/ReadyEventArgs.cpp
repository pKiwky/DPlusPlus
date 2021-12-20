#include "Entities/Common/EventArgs/ReadyEventArgs.h"

#include "Discord/DiscordClient.h"
#include "Entities/Member/DiscordUser.h"
#include "Entities/Common/DiscordApplication.h"

namespace DPlusPlus {

	void ReadyEventArgs::Execute(DiscordClient *client, const nJson &json) {
		GatewayVersion = json["v"];

		SessionId = json["session_id"];
		// Cache session id in client object.
		client->SetSession(SessionId);

		for(nJson guild : json["guilds"]) {
			Guilds.push_back(guild["id"]);
		}

		User = std::make_shared<DiscordUser>(client, json["user"]);
		Application = std::make_shared<DiscordApplication>(client, json["application"]);

		auto args = std::make_unique<const ReadyEventArgs>(*this);
		std::thread(&DiscordClient::OnReady, client, std::move(args)).detach();
	}

}