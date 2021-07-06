#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>

#undef UNICOD

//#pragma comment(lib,"tlhelp32")

using namespace std;


void getprocess() {
    DWORD th32id = 0;
    PROCESSENTRY32 pe32 = {};
    THREADENTRY32 te = {};
    pe32.dwSize = sizeof(PROCESSENTRY32);
    auto toolHelp = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (!Process32First(toolHelp, &pe32)) {
        cout << GetLastError(); // show cause of failure
        CloseHandle(toolHelp);          // clean the snapshot object
    }
    cout << pe32.th32ProcessID << endl;
    do {
        cout << pe32.szExeFile << " " << pe32.th32ProcessID << endl;
    } while (Process32Next(toolHelp, &pe32));

}

void inject(string dllpath, int pid) {

    try{
    auto hprocess = OpenProcess(PROCESS_ALL_ACCESS, false, pid);
    if (hprocess) {
        cout << "process "<<hprocess<<endl;
        auto kernel = GetModuleHandleA("kernel32");
        auto address = (GetProcAddress(kernel, "LoadLibraryA"));
        if (address) {
            cout <<"loadlibrary: "<<address<<endl;
            auto addypath = VirtualAllocEx(hprocess, 0, dllpath.length(), MEM_COMMIT | MEM_RESERVE,
                                           PAGE_EXECUTE_READWRITE);
            cout <<" Alloc: "<<addypath<<endl;
            WriteProcessMemory(hprocess,addypath,(LPVOID)dllpath.c_str(),dllpath.length()+1,NULL);
            if (CreateRemoteThread(hprocess, nullptr, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(address), addypath, 0,
                                   nullptr) != NULL) {
                cout << "injected." << endl;
            }
        }
    }else cout << GetLastError(); // show cause of failure
    } catch (exception e) {
        cout <<e.what();
    }
}

int main(int argc, char *argv[]) {
    getprocess();

    cout << "injecting " << argv[1] << " into pid: "<< argv[2] << endl;

    inject(argv[1],atoi(argv[2]));

    return 0;
}