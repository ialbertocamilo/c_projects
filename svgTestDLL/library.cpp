#include "library.h"

#include <Windows.h>
#include <iostream>
#undef _UNICODE_

bool __stdcall DllMain(DWORD inst, DWORD reason, DWORD reserved) {
    if (reason==DLL_PROCESS_ATTACH){
        MessageBox(0,"Hola mundo","GAAA",MB_OK);
    }
    return true;
}