#include "Bot.h"

void Bot::OnHello(int32_t interval) {
	DPP_LOG_INFO("[Bot::OnHello] Interval {0}ms", interval);
}

void Bot::OnHeartbeat(time_t timestamp) {
	DPP_LOG_INFO("[Bot::OnHeartbeat] Method executed on {0}", timestamp);
}

void Bot::OnReady(std::unique_ptr<const DPlusPlus::ReadyEventArgs> args) {
	DPP_LOG_INFO("[Bot::OnReady] Bot name {0}", args->User->Username);
	DPP_LOG_INFO("[Bot::OnReady] Session id {0}", args->SessionId);
	DPP_LOG_INFO("[Bot::OnReady] Gateway version {0}", args->GatewayVersion);
	DPP_LOG_INFO("[Bot::OnReady] Application id {0}", args->Application->Id);
}

void Bot::OnMessageCreate(std::unique_ptr<const DPlusPlus::MessageCreateEventArgs> args) {
	DPP_LOG_INFO("[Bot::OnMessageCreate] User {0}", args->Message->User->Username);
	DPP_LOG_INFO("[Bot::OnMessageCreate] Content {0}", args->Message->Content);

	if(args->Guild != nullptr) {
		DPP_LOG_INFO("[Bot::OnMessageCreate] Guild {0}", args->Guild->Name);
		DPP_LOG_INFO("[Bot::OnMessageCreate] Channel {0}", args->Channel->Name);
		DPP_LOG_INFO("[Bot::OnMessageCreate] Member {0}", args->Member->Nick);
	}
}

void Bot::OnMessageUpdate(std::unique_ptr<const DPlusPlus::MessageUpdateEventArgs> args) {
	if(args->OldMessage != nullptr) {
		DPP_LOG_INFO("[Bot::OnMessageUpdate] Old content {0}", args->OldMessage->Content);
	}
	DPP_LOG_INFO("[Bot::OnMessageUpdate] Content {0}", args->Message->Content);
}

void Bot::OnMessageDelete(std::unique_ptr<const DPlusPlus::MessageDeleteEventArgs> args) {
	if(args->Message != nullptr) {
		DPP_LOG_INFO("[Bot::OnMessageDelete] Content {0}", args->Message->Content);
	}
}

void Bot::OnGuildCreate(std::unique_ptr<const DPlusPlus::GuildCreateEventArgs> args) {
	DPP_LOG_INFO("[Bot::OnGuildCreate]");
}

void Bot::OnGuildUpdate(std::unique_ptr<const DPlusPlus::GuildUpdateEventArgs> args) {
	DPP_LOG_INFO("[Bot::OnGuildUpdate] Name {0}", args->Guild->Name);
}

void Bot::OnChannelCreate(std::unique_ptr<const DPlusPlus::ChannelCreateEventArgs> args) {
	DPP_LOG_INFO("[Bot::OnChannelCreate] Guild {0}", args->Guild->Name);
	DPP_LOG_INFO("[Bot::OnChannelCreate] Channel {0}", args->Channel->Name);
}

void Bot::OnChannelUpdate(std::unique_ptr<const DPlusPlus::ChannelUpdateEventArgs> args) {
	DPP_LOG_INFO("[Bot::OnChannelDelete] Guild {0}", args->Guild->Name);
	DPP_LOG_INFO("[Bot::OnChannelDelete] Channel {0}", args->Channel->Name);
}

void Bot::OnChannelDelete(std::unique_ptr<const DPlusPlus::ChannelDeleteEventArgs> args) {
	DPP_LOG_INFO("[Bot::OnChannelDelete] Guild {0}", args->Guild->Name);
	DPP_LOG_INFO("[Bot::OnChannelDelete] Channel {0}", args->Channel->Name);
}
