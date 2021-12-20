#pragma once

#include "Utils/Utility.h"
#include "Discord/Event.h"

namespace DPlusPlus {

	class DiscordMessage;

	class MessageCreateEventArgs: public Event {

	public:
		void Execute(DiscordClient *discordClient, const nJson &json);

	public:
		std::shared_ptr<DiscordMessage> Message;
		//std::shared_ptr<DiscordMember> Member;
		//std::shared_ptr<DiscordGuil> Guild;

	};

}
