#include <iostream>
#include "proc.h"

int main()
{
	//Get procId of the target process
	DWORD procId = GetProcId(L"ac_client.exe");

	//Getmodulebaseaddress
	uintptr_t moduleBase = GetModuleBaseAddress(procId, L"ac_client.exe");

	//Get handle to process
	HANDLE hProcess = 0;
	hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, procId);

	//Resolve base address of the pointer chain
	//uintptr_t dynamicPtrBaseAddr = moduleBase + 0x17B0B8;

	//std::cout << "DynamicPtrBaseAddr = " << "0x" << std::hex << dynamicPtrBaseAddr << std::endl;

	//Resolve our ammo pointer chain
	//std::vector<unsigned int> ammoOffsets = {0x364, 0x14, 0x0};
	//uintptr_t ammoAddr = FindDMAAddy(hProcess, dynamicPtrBaseAddr, ammoOffsets);

	uintptr_t healthAddr = 0x0062AC5C;

	//std::cout << "ammoAddr = " << "0x" << std::hex << ammoAddr << std::endl;
	std::cout << "healthAddr = " << "0x" << std::hex << healthAddr << std::endl;

	//Read Ammo Value
	//int ammoValue = 0;

	//ReadProcessMemory(hProcess, (BYTE*)ammoAddr, &ammoValue, sizeof(ammoValue), nullptr);
	//std::cout << "Current ammo = " << std::dec << ammoValue << std::endl;

	//Write to it
	//int newAmmo = 1337;
	//WriteProcessMemory(hProcess, (BYTE*)ammoAddr, &newAmmo, sizeof(newAmmo), nullptr);
	
	ReadProcessMemory(hProcess, (BYTE*)healthAddr, &healthAddr, sizeof(healthAddr), nullptr);

	int newHealth = 1000;
	WriteProcessMemory(hProcess, (BYTE*)healthAddr, &newHealth, sizeof(newHealth), nullptr);

	ReadProcessMemory(hProcess, (BYTE*)healthAddr, &healthAddr, sizeof(healthAddr), nullptr);

	//Read ammo value again
	//ReadProcessMemory(hProcess, (BYTE*)ammoAddr, &ammoValue, sizeof(ammoValue), nullptr);
	//std::cout << "New ammo = " << std::dec << ammoValue << std::endl;

	getchar();
	return 0;
}