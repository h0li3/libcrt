#include <stdio.h>
#include <Windows.h>
#include <io.h>
#include <fcntl.h>

static FILE* s_iob[3] = { nullptr };

extern "C" FILE* __cdecl __acrt_iob_func(unsigned fd)
{
	return s_iob[fd];
}

FILE* __ncrt_get_file(int fd, int flags)
{
	FILE* fp = nullptr;
	const char* mode = "r";

	if (flags == O_WRONLY)
		mode = "w";
	else if (flags == O_RDWR)
		mode = "rw";

	fp = _fdopen(fd, mode);
	return fp;
}

int __cdecl __ncrt_init_iob()
{
	s_iob[0] = __ncrt_get_file(0, O_RDONLY);
	s_iob[1] = __ncrt_get_file(1, O_WRONLY);
	s_iob[2] = __ncrt_get_file(2, O_WRONLY);
	return (s_iob[0] && s_iob[1] && s_iob[2]) ? 0 : 255;
}