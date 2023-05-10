#pragma warning(disable : 28252)

// Disable stdio inline temporarily.
#define _NO_CRT_STDIO_INLINE
#include <stdio.h>
#undef _NO_CRT_STDIO_INLINE
#include <stdlib.h>

extern "C"
{
    _Success_(return >= 0)
        _ACRTIMP int __cdecl __stdio_common_vsprintf_s(
            _In_                                    unsigned __int64 _Options,
            _Out_writes_z_(_BufferCount)            char* _Buffer,
            _In_                                    size_t           _BufferCount,
            _In_z_ _Printf_format_string_params_(2) char const* _Format,
            _In_opt_                                _locale_t        _Locale,
            va_list          _ArgList
        )
    {
        int len = -1;

        if (_Buffer && _BufferCount != 0) {
            len = _vsnprintf(_Buffer, _BufferCount, _Format, _ArgList);
            if (len > _BufferCount - 1) {
                _Buffer[0] = 0;
                len = -1;
            }
        }

#ifdef _LIBCRT_ABORT_WHEN_FAILURE
        abort();
#endif
        return len;
    }

    _Success_(return >= 0)
        _ACRTIMP int __cdecl __stdio_common_vsnprintf_s(
            _In_                                    unsigned __int64 _Options,
            _Out_writes_opt_z_(_BufferCount)        char* _Buffer,
            _In_                                    size_t           _BufferCount,
            _In_                                    size_t           _MaxCount,
            _In_z_ _Printf_format_string_params_(2) char const* _Format,
            _In_opt_                                _locale_t        _Locale,
            va_list          _ArgList
        )
    {
        int len = -1;

        if (_Buffer && _MaxCount != 0 && _MaxCount <= _BufferCount) {
            len = _vsnprintf(_Buffer, _BufferCount, _Format, _ArgList);
            if (len > _MaxCount - 1) {
                _Buffer[0] = 0;
                len = -1;
            }
        }

#ifdef _LIBCRT_ABORT_WHEN_FAILURE
        abort();
#endif
        return len;
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