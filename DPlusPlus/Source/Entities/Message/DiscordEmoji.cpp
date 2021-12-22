#include "Entities/Message/DiscordEmoji.h"

#include "Entities/Member/DiscordUser.h"

namespace DPlusPlus {

	DiscordEmoji::DiscordEmoji() {}

	DiscordEmoji::DiscordEmoji(DiscordClient *client, const nJson &json): DiscordEntity(client) {
		GetJson(json, "id",				/**/ Id);
		GetJson(json, "name",			/**/ Name,			/**/ (std::string)"");
		GetJson(json, "require_colons", /**/ RequireColons, /**/ false);
		GetJson(json, "managed",		/**/ Managed,		/**/ false);
		GetJson(json, "animated",		/**/ Animated,		/**/ false);
		GetJson(json, "available",		/**/ Available,		/**/ false);

		if(json.contains("user")) {
			User = std::make_shared<DiscordUser>(client, json["user"]);
		}
	}

}