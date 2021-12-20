#pragma once

#include "Discord/DiscordEntity.h"
#include "Utils/Utility.h"

namespace DPlusPlus {

	enum class ChannelType: int8_t {
		kGuildText			/**/ = 0,
		kDm					/**/ = 1,
		kGuildVoice			/**/ = 2,
		kGroupDm			/**/ = 3,
		kGuildCategory		/**/ = 4,
		kGuildNews			/**/ = 5,
		kGuildStore			/**/ = 6,
		kGuildNewsThread	/**/ = 10,
		kGuildPublicThread  /**/ = 11,
		kGuildPrivateThread /**/ = 12,
		kGuildStageVoice	/**/ = 13
	};

	class DiscordChannel: public DiscordEntity {

	public:
		DiscordChannel();
		DiscordChannel(DiscordClient *client, const nJson &json);

	public:
		Snowflake Id;
		Snowflake GuildId;
		Snowflake LastMessageId;
		int8_t Position;
		bool Nsfw;
		std::string Name;
		std::string Topic;
		ChannelType Type;

	};

}

