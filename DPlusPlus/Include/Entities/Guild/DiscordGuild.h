#pragma once

#include "Discord/DiscordEntity.h"
#include "Utils/Utility.h"
#include "Utils/Cache.hpp"

namespace DPlusPlus {

	enum class VerificationLevel: int8_t {
		kNone = 0,
		kLow,
		kMedium,
		kHigh,
		kVeryHigh
	};

	enum class MessageNotification: int8_t {
		kAllMessages = 0,
		kOnlyMentions
	};

	enum class ExplicitContentFilter: int8_t {
		kDisabled = 0,
		kMembersWithoutRoles,
		kAllMembers
	};

	enum class MFALevel: int8_t {
		kNone = 0,
		kElevated
	};

	enum class PremiumTier: int8_t {
		kNone = 0,
		kTier1,
		kTier2,
		kTier3
	};

	enum class NSFWLevel: int8_t {
		kDefault = 0,
		kExplicit,
		kSafe,
		kAgeRestricted
	};

	class DiscordChannel;
	class DiscordMessage;
	class DiscordMember;

	class DiscordGuild: public DiscordEntity {

	public:
		DiscordGuild();
		DiscordGuild(DiscordClient *client, const nJson &json);

	public:
		Cache<DiscordChannel> *Channels = nullptr;
		Cache<DiscordMember> *Members = nullptr;

		CacheRing<DiscordMessage> *Messages = nullptr;

		Snowflake Id;
		Snowflake OwnerId;
		Snowflake AfkChannelId;
		Snowflake WidgetChannelId;
		Snowflake SystemChannelId;
		Snowflake RulesChannelId;
		Snowflake PublicUpdatesChannelId;
		int8_t AfkTimeout;
		int8_t PremiumSubscriptionCount;
		int8_t MaxVideoChannelUser;
		int8_t MaxPresences;
		int32_t MaxMembers;
		int32_t MemberCount;
		int32_t ApproximateMemberCount;
		int32_t ApproximatePresenceCount;
		bool Owner;
		bool WidgetEnabled;
		bool Large;
		bool Unavailable;
		std::string Name;
		std::string Icon;
		std::string IconHash;
		std::string Spalsh;
		std::string DiscoverySplash;
		std::string Permissions;
		std::string Region;
		std::string JoinedAt;
		std::string VanityUrlCode;
		std::string Description;
		std::string Banner;
		std::string PreferredLocale;
		VerificationLevel GuildVerificationLevel;
		MessageNotification GuildMessageNotification;
		ExplicitContentFilter GuildExplicitContentFilter;
		MFALevel GuildMFALevel;
		PremiumTier GuildPremiumTier;
		NSFWLevel GuildNSFWLevel;
		//DiscordWelcomeScreen WelcomeSecreen;
		//std::vector<std::shared_ptr<DiscordRole>> Roles;
		//std::vector<std::shared_ptr<DiscordEmoji>> Emojis;
		//std::vector<std::shared_ptr<DiscordFeature>> Features;
		//std::vector<std::shared_ptr<DiscordVoiceState>> VoiceStates;
		//std::vector<std::shared_ptr<DiscordMember>> Members;
		//std::vector<std::shared_ptr<DiscordChannel>> Channels; // MAP
		//std::vector<std::shared_ptr<DiscordThread>> Threads;
		//std::vector<std::shared_ptr<DiscordPresence>> Presences;
		//std::vector<std::shared_ptr<DiscordSticker>> Stickers;
		//std::vector<std::shared_ptr<DiscordStage>> StageInstances;

	};

}

