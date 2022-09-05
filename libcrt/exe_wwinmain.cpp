#define _NCRT_STARTUP_WWINMAIN
#include "exe_common.inl"

extern "C" int wWinMainCRTStartup()
{
	return __ncrt_common_main();
}