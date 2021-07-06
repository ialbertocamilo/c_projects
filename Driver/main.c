#include <ntddk.h>
#include <ntstrsafe.h>

typedef unsigned long u_long;
typedef unsigned int u_int;
const WCHAR deviceNameBuffer[] = L"\\Device\\MYDEVICE";
const WCHAR deviceSymLinkBuffer[] = L"\\DosDevices\\MyDevice";
PDEVICE_OBJECT g_MyDevice; // Global pointer to our device object

VOID OnUnload(IN PDRIVER_OBJECT pDriverObject);

IRP irp;

typedef struct _SERVICE_DESCRIPTOR_TABLE {


	PVOID ServiceTableBase; //<-SSDT
	PVOID ServiceCounterTableBase;
	ULONGLONG NumberOfServices;
	PVOID ParamTableBase;
} SERVICE_DESCRIPTOR_TABLE, *PSERVICE_DESCRIPTOR_TABLE;

struct SSDTStruct {
	LONG *pServiceTable;
	PVOID pCounterTable;
#ifdef _WIN64
	ULONGLONG NumberOfServices;
#else
	ULONG NumberOfServices;
#endif
	PCHAR pArgumentTable;
};
// PSERVICE_DESCRIPTOR
// DRIVER_INITIALIZE DriverEntry;

__declspec(dllimport) SERVICE_DESCRIPTOR_TABLE KeServiceDescriptorTable;


void disableWP() {
	__asm {
	mov  edx, cr0
	and edx, 0xFFFEFFFF;
	mov cr0, edx;
	}
	}

	void enableWP() {
		__asm {
		push edx;
		mov edx, cr0;
		or edx, 0x00010000;
		mov cr0, edx;
		pop edx;
		}
		}


	NTSTATUS
	myZwQuerySystemInformation(ULONG SystemInformationClass,
	                           PVOID SystemInformation,
	                           ULONG SystemInformationLength, PULONG ReturnLength) {
		DbgPrint("hooked");
	}

	PIO_STACK_LOCATION irpStack = NULL;

	NTSTATUS DriverEntry(PDRIVER_OBJECT DriverObject,
	                     PUNICODE_STRING RegistryPath) {
		//        irpStack = IoGetCurrentIrpStackLocation(&irp);
		//        irpStack->Flags
		int offsetToAddress = 0x9D; // ZwQuerySystemInformation
		PSERVICE_DESCRIPTOR_TABLE pServiceDescriptorTable = &KeServiceDescriptorTable;
		DbgPrint("Service Descriptor Table %x\n", pServiceDescriptorTable);
		DbgPrint("KiServiceTable Table %x\n",
		         pServiceDescriptorTable->ServiceTableBase);
		DbgPrint(" Address of ZwQuerySystemInformation %x\n",
		         ( u_int ) pServiceDescriptorTable->ServiceTableBase +
		         (offsetToAddress * 4))

		NTSTATUS ntStatus = 0;
		UNICODE_STRING deviceNameUnicodeString, deviceSymLinkUnicodeString;

		// Normalize name and symbolic link.
		RtlInitUnicodeString(&deviceNameUnicodeString, deviceNameBuffer);
		RtlInitUnicodeString(&deviceSymLinkUnicodeString, deviceSymLinkBuffer);

		// Create the device.
		ntStatus = IoCreateDevice(DriverObject,
		                          0, // For driver extension
		                          &deviceNameUnicodeString, FILE_DEVICE_UNKNOWN,
		                          FILE_DEVICE_UNKNOWN, FALSE, &g_MyDevice);

		// Create the symbolic link
		ntStatus = IoCreateSymbolicLink(&deviceSymLinkUnicodeString,
		                                &deviceNameUnicodeString);

		DriverObject->DriverUnload = OnUnload;
		DriverObject->MajorFunction[IRP_MJ_CREATE] = Function_IRP_MJ_CREATE;
		DriverObject->MajorFunction[IRP_MJ_CLOSE] = Function_IRP_MJ_CLOSE;
		DriverObject->MajorFunction[IRP_MJ_DEVICE_CONTROL] =
				Function_IRP_DEVICE_CONTROL;

		printf();
		
		DbgPrint("Loading driver");

		return STATUS_SUCCESS;
	}

	VOID OnUnload(IN PDRIVER_OBJECT pDriverObject) {
		UNICODE_STRING symLink;

		RtlInitUnicodeString(&symLink, deviceSymLinkBuffer);

		IoDeleteSymbolicLink(&symLink);
		IoDeleteDevice(pDriverObject->DeviceObject);

		DbgPrint("OnUnload called!");

	}

	NTSTATUS create(PDRIVER_OBJECT DriverObject, PIRP pirp) {
		DbgPrint("IRP MJ CREATE received.");
		return STATUS_SUCCESS;
	}


	NTSTATUS close(PDRIVER_OBJECT DriverObject, PIRP pirp) {
		DbgPrint("IRP MJ CLOSE received.");
		return STATUS_SUCCESS;
	}

	NTSTATUS ioControl() {}