#pragma once

#include "Utils/Utility.h"
#include "Discord/Event.h"

namespace DPlusPlus {

	class DiscordUser;
	class DiscordApplication;

	class ReadyEventArgs: public Event {

	public:
		void Execute(DiscordClient *client, const nJson &json);

	public:
		int32_t GatewayVersion;
		std::string SessionId;
		std::vector<Snowflake> Guilds;
		std::shared_ptr<DiscordUser> User;
		std::shared_ptr<DiscordApplication> Application;

	};

}
