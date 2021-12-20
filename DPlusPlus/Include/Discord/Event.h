#pragma once

#include "Utils/Utility.h"

namespace DPlusPlus {

	class DiscordClient;

	class Event {

	public:
		/**
		 * Method that will be execute when this event type is executed.
		 *
		 * @discordClient		Active client instance.
		 */
		virtual void Execute(DiscordClient *client, const nJson &json) = 0;

	};

}