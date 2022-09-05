#define _NCRT_STARTUP_MAIN
#include "exe_common.inl"

extern "C" int mainCRTStartup()
{
	return __ncrt_common_main();
}