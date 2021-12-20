#include "Bot.h"

void Bot::OnHello(int32_t interval) {
	DPP_LOG_INFO("[Bot::OnHello] Interval {0}ms", interval);
}

void Bot::OnHeartbeat(int32_t timestamp) {
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
	}
}

void Bot::OnGuildCreate(std::unique_ptr<const DPlusPlus::GuildCreateEventArgs> args) {
	DPP_LOG_INFO("[Bot::OnGuildCreate]");
}
