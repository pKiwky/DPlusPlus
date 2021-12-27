#include "Entities/Channel/EventArgs/ChannelPinUpdateEventArgs.h"

#include "Discord/DiscordClient.h"
#include "Entities/Guild/DiscordGuild.h"
#include "Entities/Channel/DiscordChannel.h"

namespace DPlusPlus {

	void ChannelPinUpdateEventArgs::Execute(DiscordClient *client, const nJson &json) {
		if(json.contains("guild_id")) {
			Guild = client->Guilds.Get(json["guild_id"]);

			if(Guild != nullptr) {
				Channel = Guild->Channels->Get(json["channel_id"]);
			}
		}

		auto args = std::make_unique<const ChannelPinUpdateEventArgs>(*this);
		std::thread(&DiscordClient::OnChannelPinUpdate, client, std::move(args)).detach();
	}

}