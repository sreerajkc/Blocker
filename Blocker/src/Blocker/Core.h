#pragma once

#ifdef BLCKR_PLATFORM_WINDOWS
#ifdef BLCKR_DYNAMIC_LINK
	#ifdef BLCKR_BUILD_DLL  
		#define	BLOCKER_API __declspec(dllexport)
	#else
		#define	BLOCKER_API __declspec(dllimport)
	#endif
#else
	#define BLOCKER_API
#endif
#else
	#error Blocker only supports Windows!
#endif

#ifdef BLCKR_DEBUG
	define BLCKR_ENABLE_ASSERTS
#endif

#if BLCKR_ENABLE_ASSERTS
	#define BLCKR_ASSERT(x,...) { if(!(x)) {BLCKR_ERROR("Assertion Failed:{0}",__VA_ARGS___); ___debugbreak();} }
	#define BLCKR_CORE_ASSERT(x,...) { if(!(x)) {BLCKR_ERROR("Assertion Failed:{0}",__VA_ARGS___); ___debugbreak();} }
#else
	#define BLCKR_ASSERT(x,...)
	#define BLCKR_CORE_ASSERT(x,...)
#endif
#define BIT(x) (1 << x)
#define BIND_EVENT_FN(x) std::bind(&x,this,std::placeholders::_1)
