#pragma once

#include <Discord/DiscordClient.h>

#include <Entities/Common/DiscordApplication.h>
#include <Entities/Member/DiscordUser.h>
#include <Entities/Message/DiscordMessage.h>
#include <Entities/Guild/DiscordGuild.h>
#include <Entities/Channel/DiscordChannel.h>

class Bot: public DPlusPlus::DiscordClient {

public:
	void OnHello(int32_t interval) override;
	void OnHeartbeat(int32_t timestamp) override;
	void OnReady(std::unique_ptr<const DPlusPlus::ReadyEventArgs> args) override;
	void OnMessageCreate(std::unique_ptr<const DPlusPlus::MessageCreateEventArgs> args) override;
	void OnMessageDelete(std::unique_ptr<const DPlusPlus::MessageDeleteEventArgs> args) override {
		DPP_LOG_INFO("[Bot::OnMessageDelete] Content {0}", args->Message->Content);
	}
	void OnGuildCreate(std::unique_ptr<const DPlusPlus::GuildCreateEventArgs> args) override;

};