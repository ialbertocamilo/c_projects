//
// Created by lobo_ on 8/04/2020.
//

#include <Windows.h>
#include "SvgMemory.h"
#include "XtraWin.h"


u_long returnAddy = 0;

int _eax, _ebx, _ecx, _edx, _esp, _ebp;
XtraWin *win = new XtraWin();

void __declspec(naked) __stdcall funcHook() {


	__asm{
	mov _eax, eax
	mov _ebx, ebx
	mov _ecx, ecx
	mov _edx, edx
	mov _esp, esp
	mov _ebp, ebp
	mov byte ptr ds:[ecx+0x10], al
	pushad
	};

	win->logger(" eax: %X\n", ( int * ) _eax);
	win->logger(" ebx: %X\n", ( int * ) _ebx);
	win->logger(" ecx: %X\n", ( int * ) _ecx);
	win->logger(" edx: %X\n", ( int * ) _edx);
	win->logger(" esp: %X\n", ( int * ) _esp);
	win->logger(" ebp: %X\n", ( int * ) _ebp);

	returnAddy = ( u_long ) GetModuleHandle("rakion.bin") + 0x116F2;
	__asm{
	popad
	jmp dword ptr ds:[returnAddy];
	};
	}
//PIMAGE_TLS_CALLBACK
	void hook() {   
		SvgMemory *mem = new SvgMemory();
		XtraWin *win = new XtraWin();
		int distance = 0;
		auto rakionbin = ( u_long ) GetModuleHandle("rakion.bin");
		u_long addy = rakionbin + 0x11710;

		auto oldprotect = mem->unprotect(( u_long * ) addy, 5);
		distance = addy - ( int ) funcHook;
		if ( distance < 0 )distance = (distance ^ 0xFFFFFFFF) + 1;
		long opcode = distance - 5;
		*(( char * ) addy) = ( char ) 0xe9;
		*(( int * ) (addy + 1)) = ( int ) opcode;
		win->logger("distance: %X\n", reinterpret_cast<void *>(( int ) distance));
		win->logger("address of my function : %X\n", reinterpret_cast<void *>(( int ) funcHook));
		win->logger("opcode : %X\n", reinterpret_cast<void *>(( int ) opcode));
		mem->protect(( u_long * ) addy, 5, oldprotect);

	}

	bool __stdcall DllMain(DWORD hInst, DWORD reason, DWORD reserved) {
		if ( reason == DLL_PROCESS_ATTACH ) {
			XtraWin *win = new XtraWin();
			win->msgBoxOK("inyectado");
			win->startThread(( LPTHREAD_START_ROUTINE ) hook);
		}
		return true;
	}

