#pragma once

#include "Discord/DiscordEntity.h"
#include "Utils/Utility.h"

namespace DPlusPlus {

	class DiscordUser;

	class DiscordEmoji: public DiscordEntity {

	public:
		DiscordEmoji();
		DiscordEmoji(DiscordClient *client, const nJson &json);

	public:
		Snowflake Id;
		std::string Name;
		std::shared_ptr<DiscordUser> User;
		bool RequireColons;
		bool Managed;
		bool Animated;
		bool Available;
		// std::vector<Role> Roles;

	};

}
