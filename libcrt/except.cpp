#include <string>
#include <stdexcept>

//namespace std
//{
//	[[noreturn]] void __cdecl _Xbad_alloc()
//	{
//		throw bad_alloc();
//	}
//
//	[[noreturn]] void __cdecl _Xinvalid_argument(_In_z_ const char* msg)
//	{
//		throw invalid_argument(msg);
//	}
//
//	[[noreturn]] void __cdecl _Xlength_error(_In_z_ const char* msg)
//	{
//		throw std::length_error(msg);
//	}
//
//	[[noreturn]] void __cdecl _Xout_of_range(_In_z_ const char* msg)
//	{
//		throw std::out_of_range(msg);
//	}
//
//	[[noreturn]] void __cdecl _Xoverflow_error(_In_z_ const char* msg)
//	{
//		throw overflow_error(msg);
//	}
//
//	[[noreturn]] void __cdecl _Xruntime_error(_In_z_ const char* msg)
//	{
//		throw runtime_error(msg);
//	}
//
//	[[noreturn]] void __cdecl _XGetLastError()
//	{
//	}
//}

// TODO
namespace stdext { class exception; }
namespace std
{
	void (*_Raise_handler1)(class stdext::exception const&) = nullptr;
}

//#ifndef _WIN64
//// TODO
//extern "C" void __std_terminate()
//{
//	abort();
//}
//#endif

// TODO
extern "C" void __cdecl terminate()
{
	abort();
}