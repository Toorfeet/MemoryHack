#include <iostream>
#include <Windows.h>


using namespace std;
int main()
{
	cout << "[+]TOORFEET BYPASS" << endl;
	int valueToWrite = 0;
	cin >> valueToWrite;
	
	HWND window = FindWindow(0, "///"); //Поставить свое названия окна 

	if (window == 0) {
		cout << "error proccesing found!" << endl;
	}
	else {
		DWORD proccesId;

		GetWindowThreadProcessId(window, &proccesId);

		HANDLE process = OpenProcess(PROCESS_ALL_ACCESS, false, proccesId);

		if (!process) {
			cout << "Procces don't hack!" << endl;
		}
		else {
			int memoryWriteStatus = ReadProcessMemory(process, (LPVOID)0x0325AD0, &valueToWrite, (DWORD)sizeof(valueToWrite), NULL); //Вместо 0x0325AD0 Поставить свое значения статического или динамичного адреса
			cout << "BASEADDR:" << memoryWriteStatus << endl; // 0 - неудача 1 - удача
			if (memoryWriteStatus > 0)
			{
				cout << "CONNECT WRITEHACKESS! " << endl;
			}
			else {
				cout << "ERROR CONNECT WRITEHACKESS!" << endl;
			}
		}
		
		CloseHandle(process);
		cin.get();
	}
	return 0;
}
