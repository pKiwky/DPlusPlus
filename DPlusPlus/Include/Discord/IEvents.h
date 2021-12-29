#pragma once

#include <iostream>

#include "Entities/Common/EventArgs/ReadyEventArgs.h"

#include "Entities/Message/EventArgs/MessageCreateEventArgs.h"
#include "Entities/Message/EventArgs/MessageUpdateEventArgs.h"
#include "Entities/Message/EventArgs/MessageDeleteEventArgs.h"

#include "Entities/Guild/EventArgs/GuildCreateEventArgs.h"
#include "Entities/Guild/EventArgs/GuildUpdateEventArgs.h"
#include "Entities/Guild/EventArgs/GuildRoleCreateEventArgs.h"
#include "Entities/Guild/EventArgs/GuildRoleUpdateEventArgs.h"
#include "Entities/Guild/EventArgs/GuildRoleDeleteEventArgs.h"

#include "Entities/Channel/EventArgs/ChannelCreateEventArgs.h"
#include "Entities/Channel/EventArgs/ChannelUpdateEventArgs.h"
#include "Entities/Channel/EventArgs/ChannelDeleteEventArgs.h"
#include "Entities/Channel/EventArgs/ChannelPinUpdateEventArgs.h"

namespace DPlusPlus {

	class IEvents {

	public:
		/**
		 * Sent on connection to the websocket. Defines the heartbeat interval that the client should heartbeat to.
		 *
		 * Note: There is no reason to use this but you can do.
		 */
		virtual void OnHello(int32_t interval);

		/**
		 * Sent when heartbeat method is called.
		 *
		 * @Note: timestamp is the time when method is executed.
		 */
		virtual void OnHeartbeat(time_t timestamp);

		/**
		 * The ready event is dispatched when a client has completed the initial handshake with the gateway (for new sessions).
		 * The ready event can be the largest and most complex event the gateway will send.
		 * The ready event contains all the state required for a client to begin interacting with the rest of the platform.
		 *
		 * Note: Guilds are the guilds of which your bot is a member. They start out as unavailable when you connect to the gateway. As they become available, your bot will be notified via Guild Create events.
		 * Note: Application contains only id and flags.
		 */
		virtual void OnReady(std::unique_ptr<const ReadyEventArgs> args);

		/**
		 * The resumed event is dispatched when a client has sent a resume payload to the gateway (for resuming existing sessions).
		 */
		virtual void OnResume();

		/**
		 * The reconnect event is dispatched when a client should reconnect to the gateway (and resume their existing session, if they have one). This event usually occurs during deploys to migrate sessions gracefully off old hosts.
		 */
		virtual void OnReconnect();

		/**
		 * Sent to indicate one of at least three different situations:
		 *
		 *	1. The gateway could not initialize a session after receiving an Opcode 2 Identify
		 *	2. The gateway could not resume a previous session after receiving an Opcode 6 Resume
		 *	3. The gateway has invalidated an active session and is requesting client action
		 *
		 * The inner d key is a boolean that indicates whether the session may be resumable. See Connecting and Resuming for more information.
		 */
		virtual void OnInvalidSession();

		/**
		 * This event can be sent in three different scenarios:
		 *
		 *  1. When a user is initially connecting, to lazily load and backfill information for all unavailable guilds sent in the Ready event. Guilds that are unavailable due to an outage will send a Guild Delete event.
		 *	2. When a Guild becomes available again to the client.
		 *	3. When the current user joins a new Guild.
		 *
		 * The inner payload is a guild object, with all the extra fields specified.
		 */
		virtual void OnGuildCreate(std::unique_ptr<const GuildCreateEventArgs> args);

		/**
		 * Sent when a guild is updated. The inner payload is a guild object.
		 */
		virtual void OnGuildUpdate(std::unique_ptr<const GuildUpdateEventArgs> args);

		/**
		 * Sent when a guild becomes or was already unavailable due to an outage, or when the user leaves or is removed from a guild.
		 * The inner payload is an unavailable guild object. If the unavailable field is not set, the user was removed from the guild.
		 */
		virtual void OnGuildDelete();

		/**
		 * Sent when a guild's emojis have been updated.
		 */
		virtual void OnGuildEmojiUpdate();

		/**
		 * Sent when a guild's stickers have been updated.
		 */
		virtual void OnGuildStickersUpdate();

		/**
		 * Sent when a guild integration is updated.
		 */
		virtual void OnGuildIntegrationsUpdate();

		/**
		 * Sent when a user is banned from a guild.
		 */
		virtual void OnGuildMemberBan();

		/**
		 * Sent when a user is unbanned from a guild.
		 */
		virtual void OnGuildMemberUnban();

		/**
		 * Sent when a new user joins a guild. The inner payload is a guild member object with an extra guild_id key:
		 */
		virtual void OnGuildMemberAdd();

		/**
		 * Sent when a guild member is updated. This will also fire when the user object of a guild member changes.
		 */
		virtual void OnGuildMemberUpdate();

		/**
		 * Sent when a user is removed from a guild (leave/kick/ban).
		 */
		virtual void OnGuildMemberDelete();

		/**
		 * Sent in response to Guild Request Members. You can use the chunk_index and chunk_count to calculate how many chunks are left for your request.
		 */
		virtual void OnGuildMembersChunck();

		/**
		 * Sent when a guild role is created.
		 */
		virtual void OnGuildRoleCreate(std::unique_ptr<const GuildRoleCreateEventArgs> args);

		/**
		 * Sent when a guild role is updated.
		 */
		virtual void OnGuildRoleUpdate(std::unique_ptr<const GuildRoleUpdateEventArgs> args);

		/**
		 * Sent when a guild role is deleted.
		 */
		virtual void OnGuildRoleDelete(std::unique_ptr<const GuildRoleDeleteEventArgs> args);

		/**
		 * Sent when a new guild channel is created, relevant to the current user. The inner payload is a channel object.
		 */
		virtual void OnChannelCreate(std::unique_ptr<const ChannelCreateEventArgs> args);

		/**
		 * Sent when a channel is updated. The inner payload is a channel object.
		 */
		virtual void OnChannelUpdate(std::unique_ptr<const ChannelUpdateEventArgs> args);

		/**
		 * Sent when a message is pinned or unpinned in a text channel. This is not sent when a pinned message is deleted.
		 */
		virtual void OnChannelPinUpdate(std::unique_ptr<const ChannelPinUpdateEventArgs> args);

		/**
		 * Sent when a channel relevant to the current user is deleted. The inner payload is a channel object.
		 */
		virtual void OnChannelDelete(std::unique_ptr<const ChannelDeleteEventArgs> args);

		/**
		 * Sent when a thread is created, relevant to the current user, or when the current user is added to a thread.
		 * The inner payload is a channel object.
		 * When being added to an existing private thread, includes a thread member object.
		 */
		virtual void OnThreadCreate();

		/**
		 * Sent when a thread is updated. The inner payload is a channel object.
		 */
		virtual void OnThreadUpdate();

		/**
		 * Sent when a thread relevant to the current user is deleted.
		 * The inner payload is a subset of the channel object, containing just the id, guild_id, parent_id, and type fields.
		 */
		virtual void OnThreadDelete();

		/**
		 * Sent when the current user gains access to a channel.
		 */
		virtual void OnThreadSync();

		/**
		 * Sent when anyone is added to or removed from a thread.
		 * If the current user does not have the GUILD_MEMBERS Gateway Intent, then this event will only be sent if the current user was added to or removed from the thread.
		 */
		virtual void OnThreadMembersUpdate();

		/**
		 * Sent when a message is created. The inner payload is a message object.
		 *
		 * Note: Guild / Channel / Member may be null if message is dm.
		 */
		virtual void OnMessageCreate(std::unique_ptr<const MessageCreateEventArgs> args);

		/**
		 * Sent when a message is updated. The inner payload is a message object.
		 */
		virtual void OnMessageUpdate(std::unique_ptr<const MessageUpdateEventArgs> args);

		/**
		 * Sent when a message is deleted.
		 */
		virtual void OnMessageDelete(std::unique_ptr<const MessageDeleteEventArgs> args);

		/**
		 * Sent when multiple messages are deleted at once.
		 */
		virtual void OnMessageBulkDelete();

		/**
		 * Sent when a user adds a reaction to a message.
		 */
		virtual void OnMessageReactionAdd();

		/**
		 * Sent when a user removes a reaction from a message.
		 */
		virtual void OnMessageReactionDelete();

		/**
		 * Sent when a user explicitly removes all reactions from a message.
		 */
		virtual void OnMessageReactionDeleteAll();

		/**
		 * Sent when a bot removes all instances of a given emoji from the reactions of a message.
		 */
		virtual void OnMessageReactionDeleteEmoji();

		/**
		 * A user's presence is their current state on a guild. This event is sent when a user's presence or info, such as name or avatar, is updated.
		 */
		virtual void OnPresenceUpdate();

		/**
		 * Sent when properties about the user change. Inner payload is a user object.
		 */
		virtual void OnUserUpdate();

		/**
		 * Sent when someone joins/leaves/moves voice channels. Inner payload is a voice state object.
		 */
		virtual void OnVoiceStateUpdate();

		/**
		 * Sent when a guild's voice server is updated. This is sent when initially connecting to voice, and when the current voice instance fails over to a new server.
		 */
		virtual void OnVoiceServerUpdate();

		/**
		 * Sent when a guild channel's webhook is created, updated, or deleted.
		 */
		virtual void OnWebhooksUpdate();

		/**
		 * Sent when a user in a guild uses an Application Command. Inner payload is an Interaction.
		 */
		virtual void OnInteractionCreate();

		/**
		 * Sent when a Stage instance is created (i.e. the Stage is now "live"). Inner payload is a Stage instance
		 */
		virtual void OnStageInstanceCreate();

		/**
		 * Sent when a Stage instance has been updated. Inner payload is a Stage instance
		 */
		virtual void OnStageInstanceUpdate();

		/**
		 * Sent when a Stage instance has been deleted (i.e. the Stage has been closed). Inner payload is a Stage instance
		 */
		virtual void OnStageInstanceDelete();

	};

}
