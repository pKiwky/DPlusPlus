#include "Entities/Channel/DiscordChannel.h"

namespace DPlusPlus {

	DiscordChannel::DiscordChannel() {}

	DiscordChannel::DiscordChannel(DiscordClient *client, const nJson &json): DiscordEntity(client) {
		GetJson(json, "id",					/**/ Id);
		GetJson(json, "guild_id",			/**/ GuildId);
		GetJson(json, "last_message_id",	/**/ LastMessageId);
		GetJson(json, "position",			/**/ Position);
		GetJson(json, "nsfw",				/**/ Nsfw);
		GetJson(json, "name",				/**/ Name);
		GetJson(json, "topic",				/**/ Topic);
		GetJson(json, "type",				/**/ Type);
	}

}