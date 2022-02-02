#include "Entities/Guild/EventArgs/GuildEmojiUpdateEventArgs.h"

#include "Discord/DiscordClient.h"
#include "Entities/Message/DiscordEmoji.h"

namespace DPlusPlus {

	void GuildEmojiUpdateEventArgs::Execute(DiscordClient* client, const nJson& json) {
		Guild = client->Guilds.Get(json["guild_id"]);

		for (nJson emoji : json["emojis"]) {
			Emojis.push_back(std::make_unique<DiscordEmoji>(client, emoji));
		}

		auto args = std::make_unique<const GuildEmojiUpdateEventArgs>(*this);
		std::thread(&DiscordClient::OnGuildEmojiUpdate, client, std::move(args)).detach();
	}

}