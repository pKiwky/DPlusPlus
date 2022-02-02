#include "Entities/Member/EventArgs/PresenceUpdateEventArgs.h"

#include "Discord/DiscordClient.h"
#include "Entities/Member/DiscordUser.h"

namespace DPlusPlus {

	void PresenceUpdateEventArgs::Execute(DiscordClient* client, const nJson& json) {
		Status = json["status"];
		User = std::make_shared<DiscordUser>(client, json["user"]);
		Guild = client->Guilds.Get(json["guild_id"]);

		auto args = std::make_unique<const PresenceUpdateEventArgs>(*this);
		std::thread(&DiscordClient::OnPresenceUpdate, client, std::move(args)).detach();
	}

}