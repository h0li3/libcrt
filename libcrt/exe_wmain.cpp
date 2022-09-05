#define _NCRT_STARTUP_WMAIN
#include "exe_common.inl"

extern "C" int wmainCRTStartup()
{
	return __ncrt_common_main();
}