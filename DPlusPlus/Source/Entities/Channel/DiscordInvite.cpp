#include "Entities/Channel/DiscordInvite.h"

#include "Entities/Member/DiscordUser.h"

namespace DPlusPlus {

	DiscordInvite::DiscordInvite() {}

	DiscordInvite::DiscordInvite(DiscordClient *client, const nJson &json): DiscordEntity(client) {
		GetJson(json, "channel_id",		/**/ Id);
		GetJson(json, "guild_id",		/**/ GuildId);
		GetJson(json, "max_age",		/**/ MaxAge);
		GetJson(json, "max_uses",		/**/ MaxUses);
		GetJson(json, "target_type",	/**/ TargetType);
		GetJson(json, "uses",			/**/ Uses);
		GetJson(json, "temporary",		/**/ Temporary);
		GetJson(json, "code",			/**/ Code);
		GetJson(json, "created_at",		/**/ CreatedAt);

		if(json.contains("inviter")) {
			Inviter = std::make_shared<DiscordUser>(client, json["inviter"]);
		}

		if(json.contains("target_user")) {
			Target = std::make_shared<DiscordUser>(client, json["target_user"]);
		}
	}

}