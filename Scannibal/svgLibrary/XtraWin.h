//
// Created by lobo_ on 2/04/2020.
//

#ifndef AUTOSTAGE_XTRAWIN_H
#define AUTOSTAGE_XTRAWIN_H

#include <Windows.h>
#include <process.h>
#include <cstdio>
#include <iostream>

class XtraWin {
public:
    static int msgBoxOK(char *msg) {
        return MessageBox(0, msg, "", MB_OK);
    }

    static int msgBoxOK(char *msg, char *title) {
        return MessageBox(0, msg, title, MB_OK);
    }

    static int msgBoxOK(int msg, int radix) {
        char buffer[50];
        _itoa_s(msg, buffer, radix);
        return MessageBox(0, buffer, "", MB_OK);
    }

    static int msgBoxOK(int msg, char *title, int radix) {
        char buffer[50];
        _itoa_s(msg, buffer, radix);
        return MessageBox(0, buffer, title, MB_OK);
    }

    static u_int startThread(void *function) {
        return _beginthread(reinterpret_cast<_beginthread_proc_type>(function), 0, 0);
    }
    static HANDLE startThread(LPTHREAD_START_ROUTINE function) {
        return CreateThread(nullptr,0,function, nullptr,0, nullptr);

    }
    static void logger(char *format, void *var) {
        if (var==nullptr){
            char nullvalue[4]="";
            var= &nullvalue;
        }
        auto f = fopen("d:\\logger.txt", "a");
        fprintf(f, format, var);
        fclose(f);
    }

};
#endif //AUTOSTAGE_XTRAWIN_H

