#include <iostream>
#include <Windows.h>
void main() {
	HINSTANCE load;
	load = LoadLibrary(L"client_dll.dll");
	typedef int (*main)();
	main main_dll;
	main_dll = (main)GetProcAddress(load, "mai");
	main_dll();
	FreeLibrary(load);
}
