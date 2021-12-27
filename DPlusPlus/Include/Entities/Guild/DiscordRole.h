#pragma once

#include "Discord/DiscordEntity.h"
#include "Utils/Utility.h"

namespace DPlusPlus {

	class DiscordRole: public DiscordEntity {

	public:
		DiscordRole();
		DiscordRole(DiscordClient *client, const nJson &json);

	public:
		Snowflake Id;
		int32_t Color;
		int32_t Position;
		std::string Name;
		std::string Icon;
		std::string Permissions;
		std::string UnicodeEmoji;
		bool Hoist;
		bool Managed;
		bool Mentionable;
		// TOOD: RoleTagObjects

	};

}
