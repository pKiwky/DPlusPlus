#include "Entities/Channel/EventArgs/InviteCreateEventArgs.h"

#include "Discord/DiscordClient.h"
#include "Entities/Guild/DiscordGuild.h"
#include "Entities/Channel/DiscordChannel.h"
#include "Entities/Channel/DiscordInvite.h"

namespace DPlusPlus {

	void InviteCreateEventArgs::Execute(DiscordClient *client, const nJson &json) {
		Invite = std::make_shared<DiscordInvite>(client, json);
		Channel = std::make_shared<DiscordChannel>(client, json["channel_id"]);

		if(json.contains("guild_id")) {
			Guild = client->Guilds.Get(json["guild_id"]);
		}

		auto args = std::make_unique<const InviteCreateEventArgs>(*this);
		std::thread(&DiscordClient::OnInviteCreate, client, std::move(args)).detach();
	}

}