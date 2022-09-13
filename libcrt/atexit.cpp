#include <stdlib.h>

typedef void (__cdecl* onexit_func_t)();

static onexit_func_t* __onexit_table;
static int __onexit_funcs_cnt;
static int __onexit_funcs_cap;

extern "C" int __cdecl __init_onexit_table()
{
    __onexit_table = (onexit_func_t*)malloc(sizeof(void*) * 16);
    __onexit_funcs_cnt = 0;
    __onexit_funcs_cap = 16;
    return ((__onexit_table)? 0 : 255);
}

// TODO: add lock
extern "C" int __cdecl atexit(void (__cdecl*Func)())
{
    if (__onexit_funcs_cnt == __onexit_funcs_cap) {
        __onexit_table = (onexit_func_t*)realloc(__onexit_table, __onexit_funcs_cap + 16);
        if (!__onexit_table) return 255;
        __onexit_funcs_cap += 16;
    }
    __onexit_table[__onexit_funcs_cnt++] = Func;
    return 0;
}

int __ncrt_onexit()
{
    if (__onexit_table) {
        for (int i = 0; i < __onexit_funcs_cnt; ++i) {
            __onexit_table[i]();
        }
    }
    return 0;
}
