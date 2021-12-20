#include "Entities/Guild/EventArgs/GuildCreateEventArgs.h"

#include "Discord/DiscordClient.h"
#include "Entities/Guild/DiscordGuild.h"

namespace DPlusPlus {

	void GuildCreateEventArgs::Execute(DiscordClient *client, const nJson &json) {
		Guild = std::make_shared<DiscordGuild>(client, json);

		auto args = std::make_unique<const GuildCreateEventArgs>(*this);
		std::thread(&DiscordClient::OnGuildCreate, client, std::move(args)).detach();
	}

}