#include "Discord/DiscordEntity.h"

namespace DPlusPlus {

	DiscordEntity::DiscordEntity(): Client(nullptr) {}

	DiscordEntity::DiscordEntity(DiscordClient *client): Client(client) {}

}