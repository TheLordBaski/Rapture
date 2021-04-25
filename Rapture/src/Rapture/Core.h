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

#define BIT(x) (1 << x)