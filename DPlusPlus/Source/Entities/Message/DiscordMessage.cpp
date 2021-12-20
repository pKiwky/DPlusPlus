#include "Entities/Message/DiscordMessage.h"

#include "Discord/DiscordClient.h"
#include "Entities/Member/DiscordUser.h"

namespace DPlusPlus {

	DiscordMessage::DiscordMessage() {}

	DiscordMessage::DiscordMessage(DiscordClient *client, const nJson &json) {
		GetJson(json, "id",			/**/ Id);
		GetJson(json, "channel_id",	/**/ ChannelId);
		GetJson(json, "guild_id",	/**/ GuildId);
		GetJson(json, "content",	/**/ Content);

		if(json.contains("author")) {
			User = std::make_shared<DiscordUser>(client, json["author"]);
		}

		std::unique_ptr<DiscordGuild> guild = client->Guilds.Get(GuildId);
		if(guild != nullptr) {
			guild->Messages->Add(Id, *this);
		}
	}

}