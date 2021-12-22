#include "Entities/Member/DiscordMember.h"

#include "Entities/Member/DiscordUser.h"

namespace DPlusPlus {

	DiscordMember::DiscordMember() {}

	DiscordMember::DiscordMember(DiscordClient *client, const nJson &json): DiscordEntity(client) {
		GetJson(json, "deaf",			/**/ Deaf);
		GetJson(json, "mute",			/**/ Mute);
		GetJson(json, "nick",			/**/ Nick);
		GetJson(json, "avatar",			/**/ Avatar);
		GetJson(json, "joined_at",		/**/ JoinedAt);
		GetJson(json, "premium_since",	/**/ PremiumSince);
		GetJson(json, "permissions",	/**/ Permissions);

		if(json.contains("user")) {
			User = std::make_shared<DiscordUser>(client, json["user"]);
		}
	}

}