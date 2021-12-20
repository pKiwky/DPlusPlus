#pragma once

#include <Discord/DiscordClient.h>

#include <Entities/Member/DiscordUser.h>
#include <Entities/Common/DiscordApplication.h>
#include <Entities/Message/DiscordMessage.h>

#include <Entities/Common/EventArgs/ReadyEventArgs.h>
#include <Entities/Message/EventArgs/MessageCreateEventArgs.h>

class Bot: public DPlusPlus::DiscordClient {

public:
	void OnHello(int32_t interval) override;

	void OnHeartbeat(int32_t timestamp) override;

	void OnReady(std::unique_ptr<const DPlusPlus::ReadyEventArgs> args) override;

	void OnMessageCreate(std::unique_ptr<const DPlusPlus::MessageCreateEventArgs> args) override;

};