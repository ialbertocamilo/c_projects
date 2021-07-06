//
// Created by lobo_ on 2/04/2020.
//

#include <cstring>
#include <winnt.h>
#include <minwindef.h>
#include <rpcndr.h>
#include <memoryapi.h>
#include <exception>
#include "XtraWin.h"

#ifndef AUTOSTAGE_MEMORY_H
#define AUTOSTAGE_MEMORY_H


class SvgMemory {

public:
    static void *write(void *lpDstAddress, void *lpBaseAddress) {
        return memmove(lpDstAddress, lpBaseAddress, sizeof(lpBaseAddress));
    }

    static bool query(void *address, PMEMORY_BASIC_INFORMATION memory_information) {

        return VirtualQuery(address, memory_information, 0x1c);
    }

    static DWORD protect(void *address, int size, DWORD protect) {
        DWORD oldProtect;
        VirtualProtect(address, size, protect, &oldProtect);
        return oldProtect;
    }

    static DWORD protect_s(void *address, int size, DWORD protect) {
        DWORD oldProtect;
        try {
            VirtualProtect(address, size, protect, &oldProtect);
        } catch (std::exception e) {
            auto *w = new XtraWin();
            w->logger(" protect exception: %d ", (int *) GetLastError());
        }
        return oldProtect;
    }

    static DWORD unprotect(void *address, int size) {
        DWORD oldProtect;
        VirtualProtect(address, size, PAGE_EXECUTE_READWRITE, &oldProtect);
        return oldProtect;
    }

    static DWORD unprotect_s(void *address, int size) {
        DWORD oldProtect;
        try {
            VirtualProtect(address, size, PAGE_EXECUTE_READWRITE, &oldProtect);
        } catch (std::exception e) {
            auto *w = new XtraWin();
            w->logger(" protect exception: %d ", (int *) GetLastError());
        }
        return oldProtect;
    }

    static bool protectRead(void *address, int size) {
        DWORD oldProtect;
        return VirtualProtect(address, size, PAGE_READONLY, &oldProtect);
    }

    static int mov(void *dst, void *src, int sz) {
        byte *to = reinterpret_cast<byte *>( dst);
        byte *from = reinterpret_cast<byte *>( src);
        int bytes = 0;
        if (sz == 0)sz = sizeof(src);

        while (sz--) {

            *to++ = *from++;
            bytes++;
        }
        return bytes;
    }

    static int cmp(void *dst, byte *src) {
        int count = 0;
        byte *to = reinterpret_cast<byte *>( dst);
        byte *from = reinterpret_cast<byte *>( src);

        int sz = strlen((char *) src);
        for (int i = 0; i < sz; i++) {
            if (to[i] & from[i])count++;
            else return 0;
        }
        return count;
    }

};

#endif //AUTOSTAGE_MEMORY_H
