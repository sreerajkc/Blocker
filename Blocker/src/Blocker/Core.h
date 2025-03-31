#pragma once

#ifdef BLCKR_PLATFORM_WINDOWS
	#ifdef BLCKR_BUILD_DLL  
		#define	BLOCKER_API __declspec(dllexport)
	#else
		#define	BLOCKER_API __declspec(dllimport)
	#endif
#else
	#error Blocker only supports Windows!
#endif

#define BIT(x) (1 << x)