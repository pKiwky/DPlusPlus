#pragma once

#include "Discord/DiscordEntity.h"
#include "Utils/Utility.h"

namespace DPlusPlus {

	class DiscordUser;

	class DiscordMessage: public DiscordEntity {

	public:
		DiscordMessage();
		DiscordMessage(DiscordClient *client, const nJson &json);

	public:
		Snowflake Id;
		Snowflake ChannelId;
		Snowflake GuildId;
		Snowflake WebhookId;
		int8_t Type; // TODO Enum type
		int8_t Flags; // TODO Enum type
		bool Tts;
		bool MentionEveryone;
		bool Pinned;
		std::string Content;
		std::string Timestamp;
		std::string EditedTimestamp;
		std::shared_ptr<DiscordUser> User;
		//std::vector<std::shared_ptr<User>> m_MentionUsers;
		//std::vector<std::shared_ptr<Role>> m_MentionRoles;
		//std::vector<std::shared_ptr<Channel>> m_MentionChannels;
		//std::vector<std::shared_ptr<Attachments>> m_Attachments;
		//std::vector<std::shared_ptr<Embeds>> m_Embeds;
		//std::vector<std::shared_ptr<Reaction>> m_Reactions;

	};

}
