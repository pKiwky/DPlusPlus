#pragma once

#include <Discord/DiscordClient.h>

#include <Entities/Common/DiscordApplication.h>
#include <Entities/Member/DiscordUser.h>
#include <Entities/Member/DiscordMember.h>
#include <Entities/Message/DiscordMessage.h>
#include <Entities/Guild/DiscordGuild.h>
#include <Entities/Channel/DiscordChannel.h>

class Bot: public DPlusPlus::DiscordClient {

public:
	void OnHello(int32_t interval) override;
	void OnHeartbeat(time_t timestamp) override;
	void OnReady(std::unique_ptr<const DPlusPlus::ReadyEventArgs> args) override;
	
	void OnMessageCreate(std::unique_ptr<const DPlusPlus::MessageCreateEventArgs> args) override;
	void OnMessageUpdate(std::unique_ptr<const DPlusPlus::MessageUpdateEventArgs> args) override;
	void OnMessageDelete(std::unique_ptr<const DPlusPlus::MessageDeleteEventArgs> args) override;
	
	void OnGuildCreate(std::unique_ptr<const DPlusPlus::GuildCreateEventArgs> args) override;
	void OnGuildUpdate(std::unique_ptr<const DPlusPlus::GuildUpdateEventArgs> args) override;

	void OnChannelCreate(std::unique_ptr<const DPlusPlus::ChannelCreateEventArgs> args) override;
	void OnChannelUpdate(std::unique_ptr<const DPlusPlus::ChannelUpdateEventArgs> args) override;
	void OnChannelDelete(std::unique_ptr<const DPlusPlus::ChannelDeleteEventArgs> args) override;
};