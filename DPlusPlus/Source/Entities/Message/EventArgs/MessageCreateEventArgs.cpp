#include "Entities/Message/EventArgs/MessageCreateEventArgs.h"

#include "Discord/DiscordClient.h"
#include "Entities/Guild/DiscordGuild.h"
#include "Entities/Channel/DiscordChannel.h"
#include "Entities/Message/DiscordMessage.h"

namespace DPlusPlus {

	void MessageCreateEventArgs::Execute(DiscordClient *client, const nJson &json) {
		Message = std::make_shared<DiscordMessage>(client, json);

		// Message may be in dm, so there will no guild / channel.
		if(Message->GuildId != "") {
			Guild = std::move(client->Guilds.Get(Message->GuildId));

			if(Guild != nullptr) {
				Channel = std::move(Guild->Channels->Get(Message->ChannelId));
			}
		}

		auto args = std::make_unique<const MessageCreateEventArgs>(*this);
		std::thread(&DiscordClient::OnMessageCreate, client, std::move(args)).detach();
	}

}