#include <functional>
#include <stdexcept>

_STD_BEGIN
[[noreturn]] _CRTIMP2_PURE void __CLRCALL_PURE_OR_CDECL _Xbad_alloc() {
    _THROW(bad_alloc{});
}

[[noreturn]] _CRTIMP2_PURE void __CLRCALL_PURE_OR_CDECL _Xinvalid_argument(_In_z_ const char* const _Message) {
    _THROW(invalid_argument(_Message));
}

[[noreturn]] _CRTIMP2_PURE void __CLRCALL_PURE_OR_CDECL _Xlength_error(_In_z_ const char* const _Message) {
    _THROW(length_error(_Message));
}

[[noreturn]] _CRTIMP2_PURE void __CLRCALL_PURE_OR_CDECL _Xout_of_range(_In_z_ const char* const _Message) {
    _THROW(out_of_range(_Message));
}

[[noreturn]] _CRTIMP2_PURE void __CLRCALL_PURE_OR_CDECL _Xoverflow_error(_In_z_ const char* const _Message) {
    _THROW(overflow_error(_Message));
}

[[noreturn]] _CRTIMP2_PURE void __CLRCALL_PURE_OR_CDECL _Xruntime_error(_In_z_ const char* const _Message) {
    _THROW(runtime_error(_Message));
}

[[noreturn]] _CRTIMP2_PURE void __CLRCALL_PURE_OR_CDECL _Xbad_function_call() {
    _THROW(bad_function_call{});
}

_STD_END