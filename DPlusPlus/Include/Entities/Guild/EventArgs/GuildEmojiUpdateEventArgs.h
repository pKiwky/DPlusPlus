#pragma once

#include "Utils/Utility.h"
#include "Discord/Event.h"

namespace DPlusPlus {

	class DiscordGuild;
	class DiscordEmoji;

	class GuildEmojiUpdateEventArgs : public Event {

	public:
		void Execute(DiscordClient* client, const nJson& json);

	public:
		std::shared_ptr<DiscordGuild> Guild;
		std::vector<std::shared_ptr<DiscordEmoji>> Emojis;

	};

}
