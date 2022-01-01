#include "Entities/Message/EventArgs/MessageReactionAddEventArgs.h"

#include "Discord/DiscordClient.h"
#include "Entities/Guild/DiscordGuild.h"
#include "Entities/Message/DiscordMessage.h"
#include "Entities/Member/DiscordMember.h"

namespace DPlusPlus {

	void MessageReactionAddEventArgs::Execute(DiscordClient *client, const nJson &json) {
		//TODO: emoji	a partial emoji object	the emoji used to react - example*/

		Guild = client->Guilds.Get(json["guild_id"]);
		if(Guild != nullptr) {
			Message = Guild->Messages->Get(json["message_id"]);
			Channel = Guild->Channels->Get(json["channel_id"]);
			Member = std::make_shared<DiscordMember>(client, json["member"]);
		}

		auto args = std::make_unique<const MessageReactionAddEventArgs>(*this);
		std::thread(&DiscordClient::OnMessageReactionAdd, client, std::move(args)).detach();
	}

}