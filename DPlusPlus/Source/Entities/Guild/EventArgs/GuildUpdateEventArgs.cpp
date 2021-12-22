#include "Entities/Guild/EventArgs/GuildUpdateEventArgs.h"

#include "Discord/DiscordClient.h"
#include "Entities/Guild/DiscordGuild.h"

namespace DPlusPlus {

	void GuildUpdateEventArgs::Execute(DiscordClient *client, const nJson &json) {
		Guild = std::make_shared<DiscordGuild>(client, json);

		auto args = std::make_unique<const GuildUpdateEventArgs>(*this);
		std::thread(&DiscordClient::OnGuildUpdate, client, std::move(args)).detach();
	}

}