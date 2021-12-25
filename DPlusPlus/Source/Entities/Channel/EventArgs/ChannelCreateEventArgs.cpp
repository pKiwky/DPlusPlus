#include "Entities/Channel/EventArgs/ChannelCreateEventArgs.h"

#include "Discord/DiscordClient.h"
#include "Entities/Guild/DiscordGuild.h"
#include "Entities/Channel/DiscordChannel.h"

namespace DPlusPlus {

	void ChannelCreateEventArgs::Execute(DiscordClient *client, const nJson &json) {
		Channel = std::make_shared<DiscordChannel>(client, json);
		Guild = client->Guilds.Get(Channel->GuildId);

		auto args = std::make_unique<const ChannelCreateEventArgs>(*this);
		std::thread(&DiscordClient::OnChannelCreate, client, std::move(args)).detach();
	}

}