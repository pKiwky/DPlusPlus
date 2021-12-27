#include "Discord/DiscordIntents.h"

namespace DPlusPlus {

	DiscordIntents::DiscordIntents() {
		m_Value = (uint32_t)IntentsType::kGuilds;
	}

	void DiscordIntents::Add(IntentsType value) {
		m_Value |= (uint32_t)value;
	}

	uint32_t DiscordIntents::All() {
		return ((uint32_t)IntentsType::kGuilds
				| (uint32_t)IntentsType::kGuildMembers
				| (uint32_t)IntentsType::kGuildBans
				| (uint32_t)IntentsType::kGuildEmojiAndStickers
				| (uint32_t)IntentsType::kGuildIntegrations
				| (uint32_t)IntentsType::kGuildWebhook
				| (uint32_t)IntentsType::kGuildInvites
				| (uint32_t)IntentsType::kGuildVoiceStates
				| (uint32_t)IntentsType::kGuildPresences
				| (uint32_t)IntentsType::kGuildMessages
				| (uint32_t)IntentsType::kGuildMessageReactions
				| (uint32_t)IntentsType::kGuildMessageTyping
				| (uint32_t)IntentsType::kDirectMessage
				| (uint32_t)IntentsType::kDirectMessageReactions
				| (uint32_t)IntentsType::kDirectMessageTyping
				| (uint32_t)IntentsType::kGuildScheduledEvents);
	}

}