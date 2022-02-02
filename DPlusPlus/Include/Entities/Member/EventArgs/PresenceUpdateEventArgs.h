#pragma once

#include "Utils/Utility.h"
#include "Discord/Event.h"

namespace DPlusPlus {

	class DiscordUser;
	class DiscordGuild;

	class PresenceUpdateEventArgs : public Event {

	public:
		void Execute(DiscordClient* client, const nJson& json);

	public:
		std::string Status;
		std::shared_ptr<DiscordUser> User;
		std::shared_ptr<DiscordGuild> Guild;

	};

}
