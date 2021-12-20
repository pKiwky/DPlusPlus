#pragma once

#include <mutex>
#include <iostream>

namespace DPlusPlus {

	template<typename T>
	class Singleton {

	public:
		static T *Inst() {
			if(s_Instance == nullptr) {
				std::unique_lock<std::mutex> lock(m_Mutex);
				if(s_Instance == nullptr) {
					s_Instance = new T();
				}
			}

			return s_Instance;
		}

	public:
		virtual void Init() = 0;

	private:
		static T *s_Instance;
		static std::mutex m_Mutex;

	};

	template<typename T>
	std::mutex Singleton<T>::m_Mutex;

	template<typename T>
	T *Singleton<T>::s_Instance = nullptr;

}

