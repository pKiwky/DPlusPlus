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
