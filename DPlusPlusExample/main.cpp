#include <iostream>

#include "Bot.h"
#include "Sensitive.h"

int main() {
	std::thread([] {
		Bot myBot;
		myBot.Run(TOKEN);

		int x;
		std::cin >> x;
	}).detach();

	while(true) {
		DPP_LOG_DEBUG("[Main] Active threads: {0}", GetCurrentThreadCount());
		Sleep(1000);
	}
}