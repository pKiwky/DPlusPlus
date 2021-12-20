#include "Discord/IEvents.h"

namespace DPlusPlus {

	void IEvents::OnHello(int32_t interval) {

	}

	void IEvents::OnHeartbeat(int32_t timestamp) {

	}

	void IEvents::OnReady(std::unique_ptr<const ReadyEventArgs> args) {

	}

	void IEvents::OnResume() {

	}

	void IEvents::OnReconnect() {

	}

	void IEvents::OnInvalidSession() {

	}

	void IEvents::OnGuildCreate(std::unique_ptr<const GuildCreateEventArgs> args) {

	}

	void IEvents::OnGuildUpdate() {

	}

	void IEvents::OnGuildDelete() {

	}

	void IEvents::OnGuildEmojiUpdate() {

	}

	void IEvents::OnGuildStickersUpdate() {

	}

	void IEvents::OnGuildIntegrationsUpdate() {

	}

	void IEvents::OnGuildMemberBan() {

	}

	void IEvents::OnGuildMemberUnban() {

	}

	void IEvents::OnGuildMemberAdd() {

	}

	void IEvents::OnGuildMemberUpdate() {

	}

	void IEvents::OnGuildMemberDelete() {

	}

	void IEvents::OnGuildMembersChunck() {

	}

	void IEvents::OnGuildRoleCreate() {

	}

	void IEvents::OnGuildRoleUpdate() {

	}

	void IEvents::OnGuildRoleDelete() {

	}

	void IEvents::OnChannelCreate() {

	}

	void IEvents::OnChannelUpdate() {

	}

	void IEvents::OnChannelUpdatePin() {

	}

	void IEvents::OnChannelDelete() {

	}

	void IEvents::OnThreadCreate() {

	}

	void IEvents::OnThreadUpdate() {

	}

	void IEvents::OnThreadDelete() {

	}

	void IEvents::OnThreadSync() {

	}

	void IEvents::OnThreadMembersUpdate() {

	}

	void IEvents::OnMessageCreate(std::unique_ptr<const MessageCreateEventArgs> args) {

	}

	void IEvents::OnMessageUpdate() {

	}

	void IEvents::OnMessageDelete(std::unique_ptr<const MessageDeleteEventArgs> args) {

	}

	void IEvents::OnMessageBulkDelete() {

	}

	void IEvents::OnMessagereactionAdd() {

	}

	void IEvents::OnMessageReactionDelete() {

	}

	void IEvents::OnMessageReactionDeleteAll() {

	}

	void IEvents::OnMessageReactionDeleteEmoji() {

	}

	void IEvents::OnPresenceUpdate() {

	}

	void IEvents::OnUserUpdate() {

	}

	void IEvents::OnVoiceStateUpdate() {

	}

	void IEvents::OnVoiceServerUpdate() {

	}

	void IEvents::OnWebhooksUpdate() {

	}

	void IEvents::OnInteractionCreate() {

	}

	void IEvents::OnStageInstanceCreate() {

	}

	void IEvents::OnStageInstanceUpdate() {

	}

	void IEvents::OnStageInstanceDelete() {

	}

}