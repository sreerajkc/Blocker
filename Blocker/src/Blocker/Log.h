#pragma once

#include<memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
//#include "spdlog/fmt/ostr.h"

namespace Blocker {
	class BLOCKER_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
 		static std::shared_ptr<spdlog::logger> s_ClientLogger;
 
	};
}

//Core log macros
#define BLCKR_CORE_TRACE(...)      Blocker::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define BLCKR_CORE_INFO(...)       Blocker::Log::GetCoreLogger()->info(__VA_ARGS__)
#define BLCKR_CORE_WARN(...)       Blocker::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define BLCKR_CORE_ERROR(...)      Blocker::Log::GetCoreLogger()->error(__VA_ARGS__)
#define BLCKR_CORE_FATAL(...)      Blocker::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define BLCKR_TRACE(...)           Blocker::Log::GetClientLogger()->trace(__VA_ARGS__)
#define BLCKR_INFO(...)            Blocker::Log::GetClientLogger()->info(__VA_ARGS__)
#define BLCKR_WARN(...)            Blocker::Log::GetClientLogger()->warn(__VA_ARGS__)
#define BLCKR_ERROR(...)           Blocker::Log::GetClientLogger()->error(__VA_ARGS__)
#define BLCKR_FATAL(...)	       Blocker::Log::GetClientLogger()->fatal(__VA_ARGS__)
