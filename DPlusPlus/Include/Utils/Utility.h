#pragma once

#include <nlohmann/json.hpp>

#include "Utils/Logger.h"

#define DISCORD_GATEWAY_URL			"wss://gateway.discord.gg/?v=8&encoding=json"
#define DISCOR_API_URL				"https://discord.com/api/v8"
#define DISCORD_MESSAGE_CACHE_SIZE	10

#define DPP_MEASURE_EXECUTION_START(a) \
	uint64_t start##a = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

#define DPP_MEASURE_EXECUTION_END(a) \
	uint64_t stop##a = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); \
	std::cout << ##a << " - " <<  __FUNCTION__ << " executed in: " << stop##a - start##a << "ms \n";


namespace DPlusPlus {

	using nJson = nlohmann::json;
	using Snowflake = std::string;

	/**
	 * Get int value of this string hashed.
	 *
	 * @str			String to hash.
	 * @h			Position of char in string.
	 */
	constexpr unsigned int hash_string(const char *str, int32_t h = 0) {
		return !str[h] ? 5381 : (hash_string(str, h + 1) * 33) ^ str[h];
	}

	/**
	 * Get value from json or return default through ref if not exists.
	 *
	 * @j			Json object.
	 * @key			Key to search.
	 * @val			Returned value.
	 * @defaultVal	Default value if key not exist in json object.
	 */
	template <typename T>
	void GetJson(const nJson &j, const std::string &key, T &val, T defaultVal = {}) {
		if(j.contains(key) == false || j.at(key).is_null()) {
			//val = T{};
			val = defaultVal;
		}
		else {
			val = j.value(key, T{});
		}
	}

}
