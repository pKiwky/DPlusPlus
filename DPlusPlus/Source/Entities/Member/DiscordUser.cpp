#include "Entities/Member/DiscordUser.h"

namespace DPlusPlus {

	DiscordUser::DiscordUser() {}

	DiscordUser::DiscordUser(DiscordClient *client, const nJson &json): DiscordEntity(client) {
		GetJson(json, "id",				/**/ Id);
		GetJson(json, "username",		/**/ Username);
		GetJson(json, "discriminator",	/**/ Discriminator);
		GetJson(json, "avatar",			/**/ Avatar);
		GetJson(json, "bot",			/**/ IsBot);
		GetJson(json, "system",			/**/ IsSystem);
		GetJson(json, "mfa_enabled",	/**/ MfaEnabled);
		GetJson(json, "banner",			/**/ Banner);
		GetJson(json, "accent_color",	/**/ AccentColor);
		GetJson(json, "locale",			/**/ Locale);
		GetJson(json, "verified",		/**/ Verified);
		GetJson(json, "email",			/**/ Email);
		GetJson(json, "premium_type",	/**/ Premium);
		GetJson(json, "flags",			/**/ Flags);
		GetJson(json, "public_flags",	/**/ PublicFlags);
	}

}