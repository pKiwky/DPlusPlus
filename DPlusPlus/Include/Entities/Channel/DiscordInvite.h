#pragma once

#include "Discord/DiscordEntity.h"
#include "Utils/Utility.h"

namespace DPlusPlus {

	class DiscordUser;

	class DiscordInvite: public DiscordEntity {

	public:
		DiscordInvite();
		DiscordInvite(DiscordClient *client, const nJson &json);

	public:
		Snowflake Id;
		Snowflake GuildId;
		int32_t MaxAge;
		int32_t MaxUses;
		int32_t TargetType;
		int32_t Uses;
		bool Temporary;
		std::string Code;
		std::string CreatedAt;
		std::shared_ptr<DiscordUser> Inviter;
		std::shared_ptr<DiscordUser> Target;

	};

}
