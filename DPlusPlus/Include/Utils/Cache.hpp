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
		/**
		 * Get value from cache or return nullptr.
		 *
		 * @id		Id of object.
		 * @return	Object refference or nullptr.
		 */
		std::unique_ptr<T> Get(const Snowflake &id);

		/**
		 * Add new object or replace old if already exists.
		 *
		 * @id		Id of object.
		 * object	Object to add in cache.
		 */
		void Add(const Snowflake &id, T object);

		/**
		 * Try to delete object if exists.
		 *
		 * @id		Id of object.
		 */
		void Delete(const Snowflake &id);

	private:
		std::mutex m_Mutex;
		std::unordered_map<Snowflake, T> m_Objects;

	};

	template<typename T>
	class CacheRing {

	public:
		CacheRing(int size);

	public:
		/**
		 * Get value from cache or return nullptr.
		 *
		 * @id		Id of object.
		 * @return	Object refference or nullptr.
		 */
		std::unique_ptr<T> Get(const Snowflake &id);

		/**
		 * Add new object in cache.
		 * You can cache multiple objects with same id.
		 *
		 * @id		Id of object.
		 * object	Object to add in cache.
		 */
		void Add(const Snowflake &id, T object);

		/**
		 * Try to delete object if exists.
		 *
		 * @id		Id of object.
		 */
		void Delete(const Snowflake &id);

	public:
		std::mutex m_Mutex;
		boost::circular_buffer<T> m_Objects;

	};

}