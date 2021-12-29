#include "Entities/Guild/EventArgs/GuildRoleDeleteEventArgs.h"

#include "Discord/DiscordClient.h"
#include "Entities/Guild/DiscordGuild.h"
#include "Entities/Guild/DiscordRole.h"

namespace DPlusPlus {

	void GuildRoleDeleteEventArgs::Execute(DiscordClient *client, const nJson &json) {
		Guild = client->Guilds.Get(json["guild_id"]);

		if(Guild != nullptr) {
			Role = Guild->Roles->Get(json["role_id"]);
			Guild->Roles->Delete(Role->Id);
		}

		auto args = std::make_unique<const GuildRoleDeleteEventArgs>(*this);
		std::thread(&DiscordClient::OnGuildRoleDelete, client, std::move(args)).detach();
	}

}