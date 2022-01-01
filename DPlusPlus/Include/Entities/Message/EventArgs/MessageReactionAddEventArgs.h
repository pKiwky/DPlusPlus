#pragma once

#include "Discord/Event.h"
#include "Utils/Utility.h"

namespace DPlusPlus {

	class DiscordGuild;
	class DiscordChannel;
	class DiscordMessage;
	class DiscordMember;
	class DiscordEmoji;

	class MessageReactionAddEventArgs: public Event {

	public:
		void Execute(DiscordClient *client, const nJson &json);

	public:
		std::shared_ptr<DiscordGuild> Guild;
		std::shared_ptr<DiscordChannel> Channel;
		std::shared_ptr<DiscordMessage> Message;
		std::shared_ptr<DiscordMember> Member;
		std::shared_ptr<DiscordEmoji> Emoji;

	};

}
