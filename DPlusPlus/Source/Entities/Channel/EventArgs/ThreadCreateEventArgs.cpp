#include "Entities/Channel/EventArgs/ThreadCreateEventArgs.h"

#include "Discord/DiscordClient.h"
#include "Entities/Channel/DiscordChannel.h"
#include "Entities/Guild/DiscordGuild.h"

namespace DPlusPlus {

	void ThreadCreateEventArgs::Execute(DiscordClient* client, const nJson& json) {
		Channel = std::make_shared<DiscordChannel>(client, json);
		Guild = client->Guilds.Get(Channel->GuildId);

		auto args = std::make_unique<const ThreadCreateEventArgs>(*this);
		std::thread(&DiscordClient::OnThreadCreate, client, std::move(args)).detach();
	}

}