#pragma once

namespace DPlusPlus {

	class DiscordClient;

	class DiscordEntity {

	public:
		DiscordEntity();
		DiscordEntity(DiscordClient *client);

	public:
		DiscordClient *Client;

	};

}
