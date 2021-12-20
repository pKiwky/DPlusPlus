#pragma once

#include <Discord/DiscordClient.h>

#include <Entities/Common/DiscordApplication.h>
#include <Entities/Member/DiscordUser.h>
#include <Entities/Message/DiscordMessage.h>
#include <Entities/Guild/DiscordGuild.h>
#include <Entities/Channel/DiscordChannel.h>

#include <Entities/Common/EventArgs/ReadyEventArgs.h>
#include <Entities/Message/EventArgs/MessageCreateEventArgs.h>
#include <Entities/Guild/EventArgs/GuildCreateEventArgs.h>

class Bot: public DPlusPlus::DiscordClient {

public:
	void OnHello(int32_t interval) override;
	void OnHeartbeat(int32_t timestamp) override;
	void OnReady(std::unique_ptr<const DPlusPlus::ReadyEventArgs> args) override;
	void OnMessageCreate(std::unique_ptr<const DPlusPlus::MessageCreateEventArgs> args) override;
	void OnGuildCreate(std::unique_ptr<const DPlusPlus::GuildCreateEventArgs> args) override;

};