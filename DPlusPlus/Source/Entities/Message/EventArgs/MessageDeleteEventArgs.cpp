#include "Entities/Message/EventArgs/MessageDeleteEventArgs.h"

#include "Discord/DiscordClient.h"
#include "Entities/Guild/DiscordGuild.h"
#include "Entities/Channel/DiscordChannel.h"
#include "Entities/Message/DiscordMessage.h"

namespace DPlusPlus {

	void MessageDeleteEventArgs::Execute(DiscordClient *client, const nJson &json) {
		if(json.contains("guild_id")) {
			Guild = std::move(client->Guilds.Get(json["guild_id"]));

			if(Guild != nullptr) {
				Message = Guild->Messages->Get(json["id"]);
				Channel = Guild->Channels->Get(json["channel_id"]);

				Guild->Messages->Delete(Message->Id);
			}
		}

		auto args = std::make_unique<const MessageDeleteEventArgs>(*this);
		std::thread(&DiscordClient::OnMessageDelete, client, std::move(args)).detach();
	}

}