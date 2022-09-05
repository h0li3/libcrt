extern "C" void strcpy_s(char* dst, size_t len, const char* src)
{
	size_t n = 0;
	while (n + 1 < len && src[n])
		dst[n] = src[n++];
	dst[n] = 0;
}
