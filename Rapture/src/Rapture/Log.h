#pragma once
#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Rapture {
	class RAPTURE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLog() { return s_CoreLogger; };
		inline static std::shared_ptr<spdlog::logger>& GetClientLog() { return s_ClientLogger; };
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

#define RP_CORE_TRACE(...) ::Rapture::Log::GetCoreLog()->trace(__VA_ARGS__);
#define RP_CORE_INFO(...) ::Rapture::Log::GetCoreLog()->info(__VA_ARGS__);
#define RP_CORE_WARN(...) ::Rapture::Log::GetCoreLog()->warn(__VA_ARGS__);
#define RP_CORE_ERROR(...) ::Rapture::Log::GetCoreLog()->error(__VA_ARGS__);
#define RP_CORE_FATAL(...) ::Rapture::Log::GetCoreLog()->fatal(__VA_ARGS__);

#define RP_TRACE(...) ::Rapture::Log::GetClientLog()->trace(__VA_ARGS__);
#define RP_INFO(...) ::Rapture::Log::GetClientLog()->info(__VA_ARGS__);
#define RP_WARN(...) ::Rapture::Log::GetClientLog()->warn(__VA_ARGS__);
#define RP_ERROR(...) ::Rapture::Log::GetClientLog()->error(__VA_ARGS__);
#define RP_FATAL(...) ::Rapture::Log::GetClientLog()->fatal(__VA_ARGS__);