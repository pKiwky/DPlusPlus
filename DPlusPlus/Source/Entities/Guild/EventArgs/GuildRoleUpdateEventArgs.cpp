#include "Entities/Guild/EventArgs/GuildRoleUpdateEventArgs.h"

#include "Discord/DiscordClient.h"
#include "Entities/Guild/DiscordGuild.h"
#include "Entities/Guild/DiscordRole.h"

namespace DPlusPlus {

	void GuildRoleUpdateEventArgs::Execute(DiscordClient *client, const nJson &json) {
		Role = std::make_shared<DiscordRole>(client, json);
		Guild = client->Guilds.Get(json["guild_id"]);

		auto args = std::make_unique<const GuildRoleUpdateEventArgs>(*this);
		std::thread(&DiscordClient::OnGuildRoleUpdate, client, std::move(args)).detach();
	}

}