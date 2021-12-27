#pragma once

#include "Utils/Utility.h"

namespace DPlusPlus {

	enum class IntentsType {
		kGuilds					/**/ = 1 << 0,
		kGuildMembers			/**/ = 1 << 1,
		kGuildBans				/**/ = 1 << 2,
		kGuildEmojiAndStickers	/**/ = 1 << 3,
		kGuildIntegrations		/**/ = 1 << 4,
		kGuildWebhook			/**/ = 1 << 5,
		kGuildInvites			/**/ = 1 << 6,
		kGuildVoiceStates		/**/ = 1 << 7,
		kGuildPresences			/**/ = 1 << 8,
		kGuildMessages			/**/ = 1 << 9,
		kGuildMessageReactions	/**/ = 1 << 10,
		kGuildMessageTyping		/**/ = 1 << 11,
		kDirectMessage			/**/ = 1 << 12,
		kDirectMessageReactions	/**/ = 1 << 13,
		kDirectMessageTyping	/**/ = 1 << 14,
		kGuildScheduledEvents	/**/ = 1 << 16
	};

	class DiscordIntents {

	public:
		/**
		 * Initialize new object wiht default kGuilds intents.
		 */
		DiscordIntents();

	public:
		/**
		 * Add specific intent to this object.
		 *
		 * @value		Value from IntentsEnum.
		 */
		void Add(IntentsType value);

		/*
		 * Return all intents value as int.
		 */
		static uint32_t All();

	public:
		uint32_t m_Value;

	};

}
