﻿// Task2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <windows.h> 
#include <iostream> 
using namespace std;
#define _SECOND 10000000 // одна секунда для ожидающего таймера 
HANDLE hTimer; // ожидающий таймер 

DWORD WINAPI thread1(LPVOID)
{
	TCHAR Buffer[256] = TEXT("Hello from 4 group another one");
	HANDLE hOut;
	DWORD dwNumberOfBytes;
	FILE* fp;
	TCHAR stdPath[30] = TEXT("D:\\Lab11.txt");
	hOut = CreateFile(stdPath, GENERIC_WRITE, 0, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hOut == INVALID_HANDLE_VALUE) {
		printf("ERROR %x \n", GetLastError());
		getchar();

		return 2;
	}

	else
	{
		WriteFile(hOut, Buffer, 256, &dwNumberOfBytes, NULL);
		printf("__File WRITE:");
		getchar();
		CloseHandle(hOut);
	}
	return 0;
}

VOID CALLBACK completion_proc(LPVOID lpArg, DWORD dwTimerLowValue, DWORD dwTimerHighValue)
{
	//cout << endl << "Wait Timer" << endl;
	// ждем сигнал от ожидающего таймера 
	//WaitForSingleObject(hTimer, INFINITE);
	// выводим сообщение 
	TCHAR Buffer[256];
	HANDLE hIn;
	DWORD dwNumberOfBytes;
	FILE* fp;
	TCHAR stdPath[30] = TEXT("D:\\Lab11.txt");
	hIn = CreateFile(stdPath, GENERIC_READ, 0, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hIn == INVALID_HANDLE_VALUE) {
		printf("ERROR %x \n", GetLastError());
		getchar();

		return;
	}

	else
	{
		printf("__File READ:");
		ReadFile(hIn, Buffer, 256, &dwNumberOfBytes, NULL);
		wprintf(Buffer);
		getchar();
		CloseHandle(hIn);
	}
}


int main()
{
	cout << "start" << endl;
	HANDLE hThread1;
	HANDLE hThread2;
	DWORD IDThread1;
	DWORD IDThread2;

	_int64 qwTimeInterval; // время задержки для таймера 
	// создаем ожидающий таймер  

	hTimer = CreateWaitableTimer(NULL, FALSE, NULL);
	if (hTimer == NULL)
		return GetLastError();
	// время задержки для таймера = 10 секунд
	qwTimeInterval = -10 * _SECOND;
	// инициализируем таймер 
	if (!SetWaitableTimer(
		hTimer, // дескриптор таймера 
		(LARGE_INTEGER*)&qwTimeInterval, // временной интервал 
		0, // непериодический таймер 
		completion_proc, // процедура завершения 
		NULL, // параметров к этой процедуре нет 
		FALSE // режим сбережения энергии не устанавливать 
	))
	{
		cout << "Set waitable timer failed." << endl
			<< "The last error code: " << GetLastError() << endl;
		return 0;
	}

	// запускаем поток 
	hThread1 = CreateThread(NULL, 0, thread1, NULL, 0, &IDThread1);
	SleepEx(INFINITE, TRUE);
	if (hThread1 == NULL)
		return GetLastError();
	// ждем, пока поток закончит работу 
	WaitForSingleObject(hThread1, INFINITE);
	// закрываем дескрипторы 
	CloseHandle(hThread1);
	CloseHandle(hTimer);
	return 0;
}