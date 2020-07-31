#include <windows.h>
#include <stdio.h>
#include <tchar.h>

int main() {
	HINSTANCE lib;
	PROC ProcAdd;
	lib = LoadLibraryA("Wininet.dll");
	if (lib == NULL) {
		printf("Problem w/LoadLibrary\n");
	}	
	ProcAdd = (PROC)GetProcAddress(lib, "InternetConnectA");
	if (ProcAdd == NULL) {
		printf("Problem w/GetProcAddress\n");
		//getting the last error message
		//stolen from stackoverflow (;
		DWORD errorMessageID = GetLastError();
		LPSTR messageBuffer;
		size_t size = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, NULL, errorMessageID, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&messageBuffer, 0, NULL);
		printf("%s\n", messageBuffer);
	}
	//you can call a function in 2 diff ways:
		//1. (ProcAdd)(0,"M","M",MB_OKCANCEL);
		//2. or you can do this: ProcAdd(0,"M","M",MB_OKCANCEL); 



}
