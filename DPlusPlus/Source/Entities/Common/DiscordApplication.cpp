#include "Entities/Common/DiscordApplication.h"

#include "Entities/Member/DiscordUser.h"

namespace DPlusPlus {

	DiscordApplication::DiscordApplication() {}

	DiscordApplication::DiscordApplication(DiscordClient *client, const nJson &json): DiscordEntity(client) {
		GetJson(json, "id",						/**/ Id);
		GetJson(json, "name",					/**/ Name);
		GetJson(json, "icon",					/**/ Icon);
		GetJson(json, "description",			/**/ Description);
		GetJson(json, "bot_public",				/**/ BotPublic);
		GetJson(json, "summary",				/**/ Summary);
		GetJson(json, "verify_key",				/**/ VerifyKey);
		GetJson(json, "guild_id",				/**/ GuildId);
		GetJson(json, "flags",					/**/ Flags);
		GetJson(json, "terms_of_service_url",	/**/ TermsOfServiceUrl);
		GetJson(json, "privacy_policy_url",		/**/ PrivacyPolicyUrl);

		if(json.contains("owner")) {
			Owner = std::make_shared<DiscordUser>(client, json["owner"]);
		}
	}

}