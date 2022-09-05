#if defined(_WIN64)

extern "C" const unsigned char _guard_dispatch_icall_nop;

#pragma section(".00cfg", read)
__declspec(allocate(".00cfg"))
extern "C" void* __guard_dispatch_icall_fptr = (void*)&_guard_dispatch_icall_nop;

#endif