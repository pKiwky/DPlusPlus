#pragma once

#include "Utils/Utility.h"
#include "Discord/Event.h"

namespace DPlusPlus {

	class DiscordGuild;
	class DiscordChannel;
	class DiscordInvite;

	class InviteCreateEventArgs: public Event {

	public:
		void Execute(DiscordClient *client, const nJson &json);

	public:
		std::shared_ptr<DiscordGuild> Guild;
		std::shared_ptr<DiscordChannel> Channel;
		std::shared_ptr<DiscordInvite> Invite;

	};

}
