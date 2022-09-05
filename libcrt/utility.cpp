//
// utility.cpp
//
//      Copyright (c) Microsoft Corporation. All rights reserved.
//
// Common functionality shared by both the EXE and DLL startup code.
//
#include "vcstartup_internal.h"


extern "C" bool __cdecl __vcrt_initialize_ptd();

extern "C" bool __cdecl __scrt_dllmain_crt_thread_attach()
{
    return __vcrt_initialize_ptd();
}

extern "C" void __cdecl __vcrt_freeptd(_Inout_opt_ void* const ptd);

extern "C" bool __cdecl __scrt_dllmain_crt_thread_detach()
{
    __vcrt_freeptd(nullptr);
    return true;
}
