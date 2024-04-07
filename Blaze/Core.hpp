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

#ifdef BLZ_ENABLE_ASSERTIONS
	#define BLZ_CLIENT_ASSERT(x, ...) { if(!(x)) { BLZ_CLIENT_ERROR("assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define BLZ_CORE_ASSERT(x, ...) { if(!(x)) { BLZ_CORE_ERROR("assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define BLZ_CLIENT_ASSERT(x, ...)
	#define BLZ_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define BLZ_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)
