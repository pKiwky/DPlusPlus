#include "Entities/Message/EventArgs/MessageCreateEventArgs.h"

#include "Discord/DiscordClient.h"
#include "Entities/Guild/DiscordGuild.h"
#include "Entities/Channel/DiscordChannel.h"
#include "Entities/Message/DiscordMessage.h"
#include "Entities/Member/DiscordMember.h"
#include "Entities/Member/DiscordUser.h"

namespace DPlusPlus {

	void MessageCreateEventArgs::Execute(DiscordClient *client, const nJson &json) {
		Message = std::make_shared<DiscordMessage>(client, json);

		// Message may be dm, so there will no guild / channel.
		if(Message->GuildId != "") {
			Guild = std::move(client->Guilds.Get(Message->GuildId));

			if(Guild != nullptr) {
				Channel = std::move(Guild->Channels->Get(Message->ChannelId));

				if(json.contains("member")) {
					Member = std::make_shared<DiscordMember>(client, json["member"]);
					
					// Fill member prop with user from message.
					Member->User = Member->User;

					Guild->Members->Add(Message->User->Id, *Member);
				}
			}
		}

		auto args = std::make_unique<const MessageCreateEventArgs>(*this);
		std::thread(&DiscordClient::OnMessageCreate, client, std::move(args)).detach();
	}

}