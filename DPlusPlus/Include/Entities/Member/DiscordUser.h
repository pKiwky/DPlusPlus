#pragma once

#include "Discord/DiscordEntity.h"
#include "Utils/Utility.h"

namespace DPlusPlus {

	enum class UserFlags {
		kNone					/**/ = 0,
		kStaff					/**/ = 1 << 0,
		kPartner				/**/ = 1 << 1,
		kHypesquad				/**/ = 1 << 2,
		kBugHunderLevel1		/**/ = 1 << 3,
		kHypesqudOnlineHouse1	/**/ = 1 << 6,
		kHypesqudOnlineHouse2	/**/ = 1 << 7,
		kHypesqudOnlineHouse3	/**/ = 1 << 8,
		kPremiumEarlySupporter	/**/ = 1 << 9,
		kTeamPseudoUser			/**/ = 1 << 10,
		kBugHunderLevel2		/**/ = 1 << 14,
		kVerifiedBot			/**/ = 1 << 16,
		kVerifiedDeveloper		/**/ = 1 << 17,
		kCertifiedModerator		/**/ = 1 << 18,
		kBotHttpInteractions	/**/ = 1 << 19
	};

	enum class PremiumType {
		kNone			/**/ = 0,
		kNitroClassic	/**/ = 1,
		kNitro			/**/ = 2
	};

	class DiscordUser: public DiscordEntity {

	public:
		DiscordUser();
		DiscordUser(DiscordClient *client, const nJson &json);

	public:
		Snowflake Id;
		int32_t AccentColor;
		bool IsBot;
		bool IsSystem;
		bool MfaEnabled;
		bool Verified;
		std::string Username;
		std::string Locale;
		std::string Discriminator;
		std::string Avatar;
		std::string Banner;
		std::string Email;
		UserFlags PublicFlags;
		UserFlags Flags;
		PremiumType Premium;

	};

}
