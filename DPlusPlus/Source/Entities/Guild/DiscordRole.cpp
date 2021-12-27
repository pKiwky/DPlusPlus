#include "Entities/Guild/DiscordRole.h"

namespace DPlusPlus {

	DiscordRole::DiscordRole() {}

	DiscordRole::DiscordRole(DiscordClient *client, const nJson &json): DiscordEntity(client) {
		GetJson(json, "id",				/**/ Id);
		GetJson(json, "name",			/**/ Name);
		GetJson(json, "color",			/**/ Color);
		GetJson(json, "hoist",			/**/ Hoist);
		GetJson(json, "icon",			/**/ Icon);
		GetJson(json, "unicode_emoji",	/**/ UnicodeEmoji);
		GetJson(json, "position",		/**/ Position);
		GetJson(json, "permissions",	/**/ Permissions);
		GetJson(json, "managed",		/**/ Managed);
		GetJson(json, "mentionable",	/**/ Mentionable);
	}

}