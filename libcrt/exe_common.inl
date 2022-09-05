#include "vcstartup_internal.h"
#include "internal_shared.h"

typedef void(__cdecl* _PVFV)(void);
typedef int(__cdecl* _PIFV)(void);
typedef void(__cdecl* _PVFI)(int);

extern "C" char** __cdecl _get_environ(char***);
extern "C" char** __cdecl _get_wenviron(wchar_t***);
extern "C" void __cdecl _c_exit();
extern "C" bool __cdecl __vcrt_initialize_ptd();

#undef __argc
#undef __argv
#undef __wargv

#if defined _NCRT_STARTUP_MAIN

extern "C" int __getmainargs(int* argc, char*** argv, char*** envp, int flag, int* newmode);

static int __cdecl invoke_main()
{
    int argc = 0;
    char** argv = nullptr;
    char** env = nullptr;
    int mode = 0;
    __getmainargs(&argc, &argv, &env, 0, &mode);
    return main(argc, argv, env);
}

#elif defined _NCRT_STARTUP_WMAIN

extern "C" int __wgetmainargs(int* argc, wchar_t*** argv, wchar_t*** envp, int flag, int* newmode);

static int __cdecl invoke_main()
{
    int argc = 0;
    wchar_t** argv = nullptr;
    wchar_t** env = nullptr;
    int mode = 1;
    __wgetmainargs(&argc, &argv, &env, 1, &mode);
    return wmain(argc, argv, env);
}

#elif defined _NCRT_STARTUP_WINMAIN

static int __cdecl invoke_main()
{
    return WinMain(
        reinterpret_cast<HINSTANCE>(GetModuleHandleA(nullptr)),
        nullptr,
        GetCommandLineA(),
        0);
}

#elif defined _NCRT_STARTUP_WWINMAIN

static int __cdecl invoke_main()
{
    return wWinMain(
        reinterpret_cast<HINSTANCE>(GetModuleHandleW(nullptr)),
        nullptr,
        GetCommandLineW(),
        0);
}

#endif

static int __cdecl post_pgo_initialization()
{
    return 0;
}

static int __cdecl pre_c_initialization()
{
    return 0;
}

static void __cdecl pre_cpp_initialization()
{
    //_set_new_mode(_get_startup_new_mode());
}

_CRTALLOC(".CRT$XIAA") static _PIFV pre_c_initializer = pre_c_initialization;
_CRTALLOC(".CRT$XIAC") static _PIFV post_pgo_initializer = post_pgo_initialization;
_CRTALLOC(".CRT$XCAA") static _PVFV pre_cpp_initializer = pre_cpp_initialization;

extern "C" void __cdecl _initterm(
    _In_reads_(_Last - _First) _In_ _PVFV* _First,
    _In_                            _PVFV* _Last
);

extern "C" int  __cdecl _initterm_e(
    _In_reads_(_Last - _First)      _PIFV* _First,
    _In_                            _PIFV* _Last
);

extern int __cdecl __ncrt_init_iob();

static __declspec(noinline) int __cdecl __ncrt_common_main_seh()
{
    bool has_cctor = false;

    __ncrt_init_iob();

    if (!__vcrt_initialize_ptd())
        abort();

    //__try
    {
        if (_initterm_e(__xi_a, __xi_z) != 0)
            return 255;
        _initterm(__xc_a, __xc_z);
        return invoke_main();
    }
    //__except (1)
    {
        //int const main_result = GetExceptionCode();

        if (!has_cctor)
            _c_exit();

        //return main_result;
    }
}

static __forceinline int __cdecl __ncrt_common_main()
{
    return __ncrt_common_main_seh();
}
