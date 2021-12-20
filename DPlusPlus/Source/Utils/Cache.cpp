#include "Utils/Cache.hpp"

#include "Entities/Guild/DiscordGuild.h"
#include "Entities/Channel/DiscordChannel.h"

namespace DPlusPlus {

	template class Cache<DiscordGuild>;
	template class Cache<DiscordChannel>;

	template <typename T>
	Cache<T>::Cache(): m_Mutex(new std::mutex()) {}

	template<typename T>
	std::unique_ptr<T> Cache<T>::Get(const Snowflake &id) {
		DPP_LOG_DEBUG("[Cache::Get] {0}", typeid(T).name());

		std::lock_guard<std::mutex>(*m_Mutex);
		{
			auto it = m_Objects.find(id);
			if(it != m_Objects.end()) {
				return std::make_unique<T>((it->second));
			}
		}

		return nullptr;
	}

	template<typename T>
	void Cache<T>::Add(const Snowflake &id, T object) {
		DPP_LOG_DEBUG("[Cache::Add] {0}", typeid(T).name());

		std::lock_guard<std::mutex>(*m_Mutex);
		{
			m_Objects.insert(std::make_pair(id, object));
		}
	}
}