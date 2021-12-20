#pragma once

#include "Discord/DiscordEntity.h"
#include "Utils/Utility.h"

namespace DPlusPlus {

	class DiscordUser;

	class DiscordApplication: public DiscordEntity {

	public:
		DiscordApplication();
		DiscordApplication(DiscordClient *client, const nJson &json);

	public:
		int32_t Flags;
		Snowflake Id;
		Snowflake GuildId;
		bool BotPublic;
		std::string Name;
		std::string Icon;
		std::string Description;
		std::string TermsOfServiceUrl;
		std::string PrivacyPolicyUrl;
		std::string Summary;
		std::string VerifyKey;
		std::shared_ptr<DiscordUser> Owner;

	};

}

