#include "Entities/Guild/EventArgs/GuildRoleCreateEventArgs.h"

#include "Discord/DiscordClient.h"
#include "Entities/Guild/DiscordGuild.h"
#include "Entities/Guild/DiscordRole.h"

namespace DPlusPlus {

	void GuildRoleCreateEventArgs::Execute(DiscordClient *client, const nJson &json) {
		Role = std::make_shared<DiscordRole>(client, json);
		Guild = client->Guilds.Get(json["guild_id"]);

		auto args = std::make_unique<const GuildRoleCreateEventArgs>(*this);
		std::thread(&DiscordClient::OnGuildRoleCreate, client, std::move(args)).detach();
	}

}