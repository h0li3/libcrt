#define _NCRT_STARTUP_WINMAIN
#include "exe_common.inl"

extern "C" int WinMainCRTStartup()
{
	return __ncrt_common_main();
}