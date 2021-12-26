#include "Entities/Channel/EventArgs/ChannelUpdateEventArgs.h"

#include "Discord/DiscordClient.h"
#include "Entities/Guild/DiscordGuild.h"
#include "Entities/Channel/DiscordChannel.h"

namespace DPlusPlus {

	void ChannelUpdateEventArgs::Execute(DiscordClient *client, const nJson &json) {
		Channel = std::make_shared<DiscordChannel>(client, json);
		Guild = client->Guilds.Get(Channel->GuildId);

		Guild->Channels->Add(Channel->Id, *Channel);

		auto args = std::make_unique<const ChannelUpdateEventArgs>(*this);
		std::thread(&DiscordClient::OnChannelUpdate, client, std::move(args)).detach();
	}

}