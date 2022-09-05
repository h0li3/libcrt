typedef int(__cdecl* _PIFV)();

extern "C" int __cdecl _initterm_e(_PIFV * First, _PIFV * Last)
{
    int result;
    _PIFV* func;

    result = 0;
    for (func = First; func < Last; ++func)
    {
        if (result)
            break;
        if (*func)
            result = (*func)();
    }
    return result;
}