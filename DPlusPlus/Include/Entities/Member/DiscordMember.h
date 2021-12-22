#pragma once

#include "Discord/DiscordEntity.h"
#include "Utils/Utility.h"

namespace DPlusPlus {

	class DiscordUser;

	class DiscordMember: public DiscordEntity {

	public:
		DiscordMember();
		DiscordMember(DiscordClient *client, const nJson &json);

	public:
		bool Deaf;
		bool Mute;
		std::string Nick;
		std::string Avatar;
		std::string JoinedAt;
		std::string PremiumSince;
		std::string Permissions;
		std::shared_ptr<DiscordUser> User;
	};

}

