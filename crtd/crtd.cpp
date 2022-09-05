#include <stdio.h>
#include <vector>
#include <map>
#include <list>
#include <functional>
#include <string>
#include <stdexcept>

//stream is not available...
#include <iostream>

static std::map<std::string, const char*> gmap{ {"key", "static map initializer"} };

struct Hello
{
    Hello() noexcept
    {
        printf("Hello::Hello()\n");
    }

    ~Hello() noexcept
    {
        printf("Hello::~Hello()\n");
    }
};
static Hello hello;

void expt()
{
    // Set _HAS_EXCEPTIONS to 1 and enable c++ "Code Generation" flag exception(/EHsc) if you are going to use C++ exception.
#if _HAS_EXCEPTIONS == 1
    std::string s1("fasdfasdf");
    auto p = s1.find("df");
    try
    {
        s1.replace(1000, 2000, "hello!");
    }
    catch (std::out_of_range& e)
    {
        printf("[-] %s\n", e.what());
    }
#endif
}

void test()
{
    std::vector<char> a;
    printf("%s => %s\n", "key", gmap["key"]);
    std::list<int> b;
    b.push_back(24);
    b.push_front(23);
    b.push_back(25);
    for (auto& i : b) {
        printf("* %d\n", i);
    }

    std::map<int, std::string> m1;
    m1[222] = "222";
    printf("%s = %d\n", m1[222].c_str(), 222);

    std::function<void()> func = expt;
    func();

    printf("%p %p %p\n", stdin, stdout, stderr);

    std::list<std::string> sst;
    sst.push_back("Alice");
    sst.push_back("Bob");
    sst.push_back("Foo");
    sst.push_back("Bar");

    for (const auto& s : sst)
    {
        printf("%s\n", s.c_str());
    }
}

int main_xx(int argc, char** argv)
{
	printf("Hello %s\n", argv[0]);
    test();
}


int wmain(int argc, wchar_t** argv)
{
    printf("Hello %ls\n", argv[0]);
    test();
}

//#include <Windows.h>
//int WINAPI WinMain(
//    _In_     HINSTANCE hInstance,
//    _In_opt_ HINSTANCE hPrevInstance,
//    _In_     LPSTR     lpCmdLine,
//    _In_     int       nShowCmd
//)
//{
//    MessageBoxA(0, "winmain", "winmain", MB_OK);
//}

/*
// This is a bad idea...
int WINAPI DllMain(
    HINSTANCE const instance,
    DWORD     const reason,
    LPVOID    const reserved)
{
    if (reason == DLL_PROCESS_ATTACH)
    {
        MessageBoxA(0, "dllmain", "dllmain", MB_OK);
    }
    return TRUE;
}
*/