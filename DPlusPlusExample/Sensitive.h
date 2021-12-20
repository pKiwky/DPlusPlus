// SECRET BOT TOKEN
#define TOKEN "Nzk1NzU1ODUxOTgxMzg5ODY0.X_N_Yw.Mh4Vw3WeyNsqzIs3qxjAUk0Ct1s"

#include <tlhelp32.h>
#include <Windows.h>

int GetCurrentThreadCount() {
	DWORD const  id = GetCurrentProcessId();
	HANDLE const  snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, 0);

	PROCESSENTRY32 entry = {0};
	entry.dwSize = sizeof(entry);

	BOOL  ret = true;
	ret = Process32First(snapshot, &entry);
	while(ret && entry.th32ProcessID != id) {
		ret = Process32Next(snapshot, &entry);
	}

	CloseHandle(snapshot);
	return ret ? entry.cntThreads : -1;
}
