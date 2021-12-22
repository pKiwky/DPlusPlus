#include "Entities/Guild/DiscordGuild.h"

#include "Discord/DiscordClient.h"
#include "Entities/Channel/DiscordChannel.h"

namespace DPlusPlus {

	DiscordGuild::DiscordGuild() {}

	DiscordGuild::DiscordGuild(DiscordClient *client, const nJson &json): DiscordEntity(client) {
		GetJson(json, "id",								/**/ Id);
		GetJson(json, "owner_id",						/**/ OwnerId);
		GetJson(json, "afk_channel_id",					/**/ AfkChannelId);
		GetJson(json, "widget_channel_id",				/**/ WidgetChannelId);
		GetJson(json, "system_channel_id",				/**/ SystemChannelId);
		GetJson(json, "rules_channel_id",				/**/ RulesChannelId);
		GetJson(json, "public_updates_channel_id",		/**/ PublicUpdatesChannelId);
		GetJson(json, "afk_timeout",					/**/ AfkTimeout);
		GetJson(json, "premium_subscription_count",		/**/ PremiumSubscriptionCount);
		GetJson(json, "max_video_channel_users",		/**/ MaxVideoChannelUser);
		GetJson(json, "max_presences",					/**/ MaxPresences);
		GetJson(json, "max_members",					/**/ MaxMembers);
		GetJson(json, "member_count",					/**/ MemberCount);
		GetJson(json, "approximate_member_count",		/**/ ApproximateMemberCount);
		GetJson(json, "approximate_presence_count",		/**/ ApproximatePresenceCount);
		GetJson(json, "owner",							/**/ Owner);
		GetJson(json, "widget_enabled",					/**/ WidgetEnabled);
		GetJson(json, "large",							/**/ Large);
		GetJson(json, "unavailable",					/**/ Unavailable);
		GetJson(json, "name",							/**/ Name);
		GetJson(json, "Icon",							/**/ Icon);
		GetJson(json, "icon_hash",						/**/ IconHash);
		GetJson(json, "splash",							/**/ Spalsh);
		GetJson(json, "discovery_splash",				/**/ DiscoverySplash);
		GetJson(json, "permissions",					/**/ Permissions);
		GetJson(json, "region",							/**/ Region);
		GetJson(json, "joined_at",						/**/ JoinedAt);
		GetJson(json, "vanity_url_code",				/**/ VanityUrlCode);
		GetJson(json, "description",					/**/ Description);
		GetJson(json, "banner",							/**/ Banner);
		GetJson(json, "preferred_locale",				/**/ PreferredLocale);
		GetJson(json, "verification_level",				/**/ GuildVerificationLevel);
		GetJson(json, "default_message_notifications",	/**/ GuildMessageNotification);
		GetJson(json, "explicit_content_filter",		/**/ GuildExplicitContentFilter);
		GetJson(json, "mfa_level",						/**/ GuildMFALevel);
		GetJson(json, "premium_tier",					/**/ GuildPremiumTier);
		GetJson(json, "nsfw_level",						/**/ GuildNSFWLevel);

		// LEAK MEMORY ON UPDATE OLD GUILD.
		Channels = new Cache<DiscordChannel>();
		Members = new Cache<DiscordMember>();
		Messages = new CacheRing<DiscordMessage>(DISCORD_MESSAGE_CACHE_SIZE);

		if(json.contains("channels")) {
			for(nJson channel : json["channels"]) {
				Channels->Add(channel["id"], DiscordChannel(client, channel));
			}
		}

		client->Guilds.Add(Id, *this);
	}

}