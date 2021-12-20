#pragma once

#include <unordered_map>
#include <mutex>

#undef U
#include <boost/circular_buffer.hpp>

#include "Utils/Singleton.hpp"
#include "Utils/Utility.h"
#include "Utils/Logger.h"

namespace DPlusPlus {

	template <typename T>
	class Cache {

	public:
		Cache();

	public:
		std::unique_ptr<T> Get(const Snowflake &id);
		void Add(const Snowflake &id, T object);

	private:
		std::mutex *m_Mutex;
		std::unordered_map<Snowflake, T> m_Objects;

	};

}