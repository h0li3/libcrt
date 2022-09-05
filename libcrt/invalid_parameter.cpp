#include <corecrt.h>

extern "C" __declspec(noreturn)
void __cdecl _invoke_watson(
    _In_opt_z_ wchar_t const* _Expression,
    _In_opt_z_ wchar_t const* _FunctionName,
    _In_opt_z_ wchar_t const* _FileName,
    _In_       unsigned int _LineNo,
    _In_       uintptr_t _Reserved)
{
}

extern "C" [[noreturn]] void __cdecl _invalid_parameter_noinfo_noreturn()
{
    _invoke_watson(0, 0, 0, 0, 0);
}
