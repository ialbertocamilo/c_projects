
#include "library.h"
#include <iostream>
#include <Windows.h>
#include <map>
#include <future>

#include "svgLibrary/SvgMemory.h"
#include "svgLibrary/XtraWin.h"

#pragma clang diagnostic push
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wwritable-strings"
#pragma clang diagnostic ignored "-Waddress-of-temporary"
#undef UNICODE


class SvgScannerEngine {
private:
    std::vector<u_long> addressOcurrences;
    XtraWin *w;
    SvgMemory *mem;
    DWORD dwProtectionMask2 = (PAGE_GUARD | PAGE_NOCACHE | PAGE_NOACCESS | PAGE_TARGETS_INVALID |
                               PAGE_TARGETS_NO_UPDATE | PAGE_WRITECOMBINE);
    DWORD dwProtectionMask = (PAGE_EXECUTE | PAGE_EXECUTE_READ | PAGE_EXECUTE_READWRITE | PAGE_EXECUTE_WRITECOPY |
                              PAGE_READONLY | PAGE_READWRITE | PAGE_WRITECOPY | PAGE_WRITECOMBINE);

    std::map<int, char *> MemProtection;
    std::map<int, char *> MemState;

//    std::cout << "decltype(i) is " << type_name<decltype(i)>() << '\n'   // decltype(i) is int
    void declareMemProtection() {

        MemProtection[0x01] = "PAGE_NOACCESS";
        MemProtection[0x02] = "PAGE_READONLY";
        MemProtection[0x04] = "PAGE_READWRITE";
        MemProtection[0x08] = "PAGE_WRITECOPY";
        MemProtection[0x10] = "PAGE_EXECUTE";
        MemProtection[0x20] = "PAGE_EXECUTE_READ";
        MemProtection[0x40] = "PAGE_EXECUTE_READWRITE";
        MemProtection[0x80] = "PAGE_EXECUTE_WRITECOPY";
        MemProtection[0x100] = "PAGE_GUARD";
        MemProtection[0x200] = "PAGE_NOCACHE";
        MemProtection[0x400] = "PAGE_WRITECOMBINE";
        MemProtection[0x0800] = "PAGE_GRAPHICS_NOACCESS";
        MemProtection[0x1000] = "PAGE_GRAPHICS_READONLY";
        MemProtection[0x2000] = "PAGE_GRAPHICS_READWRITE";
        MemProtection[0x4000] = "PAGE_GRAPHICS_EXECUTE";
        MemProtection[0x8000] = "PAGE_GRAPHICS_EXECUTE_READ";
        MemProtection[0x10000] = "PAGE_GRAPHICS_EXECUTE_READWRITE";
        MemProtection[0x20000] = "PAGE_GRAPHICS_COHERENT";
        MemProtection[0x80000000] = "PAGE_ENCLAVE_THREAD_CONTROL";
        MemProtection[0x80000000] = "PAGE_REVERT_TO_FILE_MAP";
        MemProtection[0x40000000] = "PAGE_TARGETS_NO_UPDATE";
        MemProtection[0x40000000] = "PAGE_TARGETS_INVALID";
        MemProtection[0x20000000] = "PAGE_ENCLAVE_UNVALIDATED";
        MemProtection[0x10000000] = "PAGE_ENCLAVE_DECOMMIT";
        MemProtection[0x104] = "PAGE_READWRITE | PAGE_GUARD";

        MemState[0x00001000] = "MEM_COMMIT";
        MemState[0x00002000] = "MEM_RESERVE";
        MemState[0x00004000] = "MEM_REPLACE_PLACEHOLDER";
        MemState[0x00040000] = "MEM_RESERVE_PLACEHOLDER";
        MemState[0x00080000] = "MEM_RESET";
        MemState[0x00100000] = "MEM_TOP_DOWN";
        MemState[0x00200000] = "MEM_WRITE_WATCH";
        MemState[0x00400000] = "MEM_PHYSICAL";
        MemState[0x00800000] = "MEM_ROTATE";;
        MemState[0x00800000] = "MEM_DIFFERENT_IMAGE_BASE_OK";
        MemState[0x01000000] = "MEM_RESET_UNDO";
        MemState[0x20000000] = "MEM_LARGE_PAGES";
        MemState[0x80000000] = "MEM_4MB_PAGES";
        MemState[(0x20000000 | 0x00400000)] = "MEM_64K_PAGES";
        MemState[0x00000001] = "MEM_UNMAP_WITH_TRANSIENT_BOOST";
        MemState[0x00000001] = "MEM_COALESCE_PLACEHOLDERS";
        MemState[0x00000002] = "MEM_PRESERVE_PLACEHOLDER";
        MemState[0x00004000] = "MEM_DECOMMIT";
        MemState[0x00008000] = "MEM_RELEASE";
        MemState[0x00010000] = "MEM_FREE";
    }

public:
    SvgScannerEngine() {
        w = new XtraWin();
        mem = new SvgMemory();
        this->declareMemProtection();
    }

    int editValue(u_long *lpaddress, char *value) {
        mem->mov(lpaddress, value, strlen(value)+1);
        return 1;
    }

    template <typename T>
    int editValue2(u_long *lpaddress, T value) {
//        const char* type= typeid(value).name();
//        int sztype=sizeof(decltype(value));
        byte* val=(byte*)&value;
        mem->mov(lpaddress,val,  sizeof(value));
        return 1;
    }


    int showMemDump(u_long *address) {
        editValue2(address, 4444);
        byte addy = reinterpret_cast<byte>(address);
        w->logger("[ DUMP ] :\n", nullptr);
        int bytes = 35;
        int jump = 0;
        for (int i = 0; i < 50; i++) {
            w->logger(" %X ", reinterpret_cast<void *>(addy++));
            jump++;
            if (jump >= 16) {
                w->logger("\n", nullptr);
                jump = 0;
            }
        }
        return 0;
    }

    int showAllOcurrences() {
        if (addressOcurrences.size()) {
            w->logger("[ ALL OCURRENCES :  %d ]\n", (int *) addressOcurrences.size());
            for (auto &iter : addressOcurrences) {
                w->logger("Address saved:  %X \n", (int *) iter);
            }

        }
        return addressOcurrences.size();
    }

    int replaceAllOcurrences(void *value, u_int size) {
        int count = 0;
        for (auto &iter : addressOcurrences) {
            auto mb = mem->unprotect_s((u_int *) iter, size);
            this->editValue((u_long *) iter, (char *) value);
            mem->protect_s((u_int *) iter, size, mb);
            w->logger("Value of address %X changed!\n", (int *) iter);
            count++;
        }
        addressOcurrences.clear();
        return count;
    }

    int __stdcall scan(u_long addressFrom, u_long addressTo, void *value) {
        int ocurrences = 0;
        int byteswalked = 0;

        MEMORY_BASIC_INFORMATION mb;
        long lpAddress = addressFrom;
        u_long sizeValuetoFind = lstrlen((char *) value);
        try {
            while (mem->query(reinterpret_cast<void *>(lpAddress), &mb)) {
                u_long *bytesRem = (u_long *) (lpAddress + mb.RegionSize);
                u_long *walker = (u_long *) mb.BaseAddress;
                w->logger("1 Page Allocation Address: %X\n", (int *) mb.AllocationBase);
                w->logger("2 Page Base Address: %X\n", (int *) mb.BaseAddress);
                w->logger("3 Page Size Remain: %d\n", (int *) mb.RegionSize);
                w->logger("4 address Protect: %s \n", MemProtection[reinterpret_cast<const int>((int *) mb.Protect)]);
                w->logger("5 address Protect CODE : %X \n", (int *) mb.Protect);
                w->logger("6 address State: %s\n\n", MemState[reinterpret_cast<const int>((int *) mb.State)]);
                if (mb.State & MEM_COMMIT &&
                    (mb.Protect & dwProtectionMask && !(mb.Protect & dwProtectionMask2 && mb.Protect != 104))) {
                    for (; walker < bytesRem - sizeValuetoFind; walker++) {
                        if (memcmp(walker, value, sizeValuetoFind) == 0 && walker != (u_long *) value) {
//                            mem->mov(walker, value2, lstrlen(value2) + 1);
                            w->logger("address of value: %X <-\n", (u_long *) value);
                            ocurrences++;
                            this->addressOcurrences.push_back((u_long) walker);
                            w->logger("address of object: %X <-\n", walker);
                        }
                    }

                    if (lpAddress >= addressTo) return ocurrences;
                }
                lpAddress += mb.RegionSize;
                memset(&mb, 0, 0x1c);
            }
        }
        catch (std::exception &e) {
            w->logger("exception: %s ", (char *) e.what());
        }
        return ocurrences;
    }
};

void start() {
    SvgScannerEngine *svg = new SvgScannerEngine();
    const char value[] = "DataSetup\\LevelData\\stage_0";
    long from = (long) GetModuleHandle(0);
    long to = 0x8FFFFFFF;

    char value2[] = "HOLA MUNDO CRUEL.txt";

    svg->scan(from, to, (char *) value);
    svg->showAllOcurrences();
    svg->replaceAllOcurrences(value2, strlen(value2) + 1);
    svg->showMemDump(reinterpret_cast<u_long *>(from));
}

bool __stdcall DllMain(DWORD inst, DWORD reason, DWORD reserved) {

    if (reason == DLL_PROCESS_ATTACH) {
        try {

//            auto a= std::async(replaceStage);
//            _beginthread(reinterpret_cast<_beginthread_proc_type>(&start), 0, 0);
            auto *msg = new XtraWin();
            msg->startThread((LPTHREAD_START_ROUTINE)start);

        } catch (int e) {

        }


    }
    return TRUE;
}

#pragma clang diagnostic pop
