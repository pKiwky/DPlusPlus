#include "Entities/Message/EventArgs/MessageUpdateEventArgs.h"

#include "Discord/DiscordClient.h"
#include "Entities/Guild/DiscordGuild.h"
#include "Entities/Channel/DiscordChannel.h"
#include "Entities/Message/DiscordMessage.h"

namespace DPlusPlus {

	void MessageUpdateEventArgs::Execute(DiscordClient *client, const nJson &json) {
		Message = std::make_shared<DiscordMessage>(client, json);

		if(json.contains("guild_id")) {
			Guild = std::move(client->Guilds.Get(json["guild_id"]));

			if(Guild != nullptr) {
				Channel = Guild->Channels->Get(json["channel_id"]);

				Guild->Messages->Delete(Message->Id);
				Guild->Messages->Add(Message->Id, *Message);
			}
		}

		auto args = std::make_unique<const MessageUpdateEventArgs>(*this);
		std::thread(&DiscordClient::OnMessageUpdate, client, std::move(args)).detach();
	}

}