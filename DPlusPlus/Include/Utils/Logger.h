#pragma once

#include <memory>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include "Singleton.hpp"

#define DPP_LOG_ERROR(...)		DPlusPlus::Logger::Inst()->m_Logger->error(__VA_ARGS__)
#define DPP_LOG_CRITICAL(...)	DPlusPlus::Logger::Inst()->m_Logger->critical(__VA_ARGS__)
#define DPP_LOG_INFO(...)		DPlusPlus::Logger::Inst()->m_Logger->info(__VA_ARGS__)
#define DPP_LOG_WARN(...)		DPlusPlus::Logger::Inst()->m_Logger->warn(__VA_ARGS__)
#define DPP_LOG_TRACE(...)		DPlusPlus::Logger::Inst()->m_Logger->trace(__VA_ARGS__)

#ifdef _DEBUG
#define DPP_LOG_DEBUG(...)		DPlusPlus::Logger::Inst()->m_Logger->debug(__VA_ARGS__)
#else
#define DPP_LOG_DEBUG(...)
#endif

namespace DPlusPlus {

	class Logger: public Singleton<Logger> {

	public:
		void Init() {
			spdlog::set_pattern("%^[%T] %n: %v%$");
			m_Logger = spdlog::stdout_color_mt("DPlusPlus");
			m_Logger->set_level(spdlog::level::trace);
		}

	public:
		std::shared_ptr<spdlog::logger> m_Logger;

	};

}