#define _HAS_EXCEPTIONS 0
#include <exception>
using _Prhand = void(__cdecl*)(const stdext::exception&);
namespace std
{
	_Prhand _Raise_handler = nullptr; // define raise handler pointer
}