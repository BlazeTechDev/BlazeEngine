#pragma once

#ifdef BLZ_PLATFORM_WINDOWS
	#ifdef BLZ_BUILD_DLL
		#define BLAZE_API __declspec(dllexport)
	#else
		#define BLAZE_API __declspec(dllimport)
	#endif
#else
	#error Blaze only supports windows
#endif

#define BIT(x) (1 << x)