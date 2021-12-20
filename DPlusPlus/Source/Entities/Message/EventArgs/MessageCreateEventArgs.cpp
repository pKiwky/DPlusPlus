#include "Entities/Message/EventArgs/MessageCreateEventArgs.h"

#include "Discord/DiscordClient.h"
#include "Entities/Message/DiscordMessage.h"

namespace DPlusPlus {

	void MessageCreateEventArgs::Execute(DiscordClient *discordClient, const nJson &json) {
		Message = std::make_shared<DiscordMessage>(discordClient, json);

		auto args = std::make_unique<const MessageCreateEventArgs>(*this);
		std::thread(&DiscordClient::OnMessageCreate, discordClient, std::move(args)).detach();
	}

}