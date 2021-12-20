#include "Utils/Cache.hpp"

#include "Entities/Guild/DiscordGuild.h"
#include "Entities/Channel/DiscordChannel.h"
#include "Entities/Message/DiscordMessage.h"

namespace DPlusPlus {

	template class Cache<DiscordGuild>;
	template class Cache<DiscordChannel>;

	template class CacheRing<DiscordMessage>;

	template <typename T>
	Cache<T>::Cache():
		m_Mutex(new std::mutex()) {
	}

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

	template<typename T>
	CacheRing<T>::CacheRing(int size):
		m_Mutex(new std::mutex()), m_Objects(boost::circular_buffer<T>(size)) {
	}

	template<typename T>
	std::unique_ptr<T> CacheRing<T>::Get(const Snowflake &id) {
		DPP_LOG_DEBUG("[CacheRing::Get] {0}", typeid(T).name());

		std::lock_guard<std::mutex>(*m_Mutex);
		{
			for(int i = 0; i < m_Objects.size(); i++) {
				if(m_Objects.at(i).Id == id) {
					return std::make_unique<T>(m_Objects.at(i));
				}
			}
		}

		return nullptr;
	}

	template<typename T>
	void CacheRing<T>::Add(const Snowflake &id, T object) {
		DPP_LOG_DEBUG("[CacheRing::Add] {0}", typeid(T).name());

		for(int i = 0; i < m_Objects.size(); i++) {
			if(m_Objects.at(i).Id == object.Id) {
				m_Objects.at(i) = object;
				return;
			}
		}

		std::lock_guard<std::mutex>(*m_Mutex);
		{
			m_Objects.push_back(object);
		}
	}
}