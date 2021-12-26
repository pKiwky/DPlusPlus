#include "Entities/Channel/EventArgs/ChannelCreateEventArgs.h"

#include "Discord/DiscordClient.h"
#include "Entities/Guild/DiscordGuild.h"
#include "Entities/Channel/DiscordChannel.h"

namespace DPlusPlus {

	void ChannelDeleteEventArgs::Execute(DiscordClient *client, const nJson &json) {
		Channel = std::make_shared<DiscordChannel>(client, json);
		Guild = client->Guilds.Get(Channel->GuildId);

		Guild->Channels->Delete(Channel->Id);

		auto args = std::make_unique<const ChannelDeleteEventArgs>(*this);
		std::thread(&DiscordClient::OnChannelDelete, client, std::move(args)).detach();
	}

}