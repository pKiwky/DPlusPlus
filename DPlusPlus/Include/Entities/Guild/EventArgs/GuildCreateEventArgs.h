#pragma once

#include "Utils/Utility.h"
#include "Discord/Event.h"

namespace DPlusPlus {

	class DiscordGuild;

	class GuildCreateEventArgs: public Event {

	public:
		void Execute(DiscordClient *client, const nJson &json);

	public:
		std::shared_ptr<DiscordGuild> Guild;

	};

}