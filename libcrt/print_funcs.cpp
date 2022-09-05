#include <stdio.h>

extern "C"
{

    _Success_(return >= 0)
        int __cdecl __stdio_common_vsprintf_s(
            _In_                                    unsigned __int64 _Options,
            _Out_writes_opt_z_(_BufferCount)        char* _Buffer,
            _In_                                    size_t           _BufferCount,
            _In_z_ _Printf_format_string_params_(2) char const* _Format,
            _In_opt_                                _locale_t        _Locale,
            va_list          _ArgList
        )
    {
        if (_Buffer && _BufferCount > 0)
        {
            _Buffer[0] = 0;
            return vsprintf(_Buffer, _Format, _ArgList);
        }
        return 0;
    }

    _Success_(return >= 0)
        _ACRTIMP int __cdecl __stdio_common_vsprintf(
            _In_                                    unsigned __int64 _Options,
            _Out_writes_z_(_BufferCount)            char* _Buffer,
            _In_                                    size_t           _BufferCount,
            _In_z_ _Printf_format_string_params_(2) char const* _Format,
            _In_opt_                                _locale_t        _Locale,
            va_list          _ArgList
        )
    {
        if (_Buffer == 0)
            return 255;
        return __stdio_common_vsprintf_s(_Options, _Buffer, _BufferCount, _Format, _Locale, _ArgList);
    }

    _ACRTIMP int __cdecl __stdio_common_vfprintf(
        _In_                                    unsigned __int64 _Options,
        _Inout_                                 FILE* _Stream,
        _In_z_ _Printf_format_string_params_(2) char const* _Format,
        _In_opt_                                _locale_t        _Locale,
        va_list          _ArgList
    )
    {
        return vfprintf(_Stream, _Format, _ArgList);
    }
}