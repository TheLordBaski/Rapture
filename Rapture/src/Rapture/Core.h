#pragma once

#ifdef RP_PLATFORM_WINDOWS

	#ifdef  RP_BUILD_DLL
		#define RAPTURE_API __declspec(dllexport)
	#else
		#define RAPTURE_API __declspec(dllimport)
	#endif

#else

	#error Rapture only supports Windows!

#endif

#ifdef RP_ENABLE_ASSERTS
	#define RP_ASSERT(x, ...) { if(!(x)) { RP_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define RP_CORE_ASSERT(x, ...) { if(!(x)) { RP_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define RP_ASSERT(x, ...)
	#define RP_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)