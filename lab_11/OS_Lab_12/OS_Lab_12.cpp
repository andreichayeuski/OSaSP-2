﻿// OS_Lab_12.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <windows.h> 
#include <iostream> 
using namespace std;
#define _SECOND 10000000 // одна секунда для ожидающего таймера 
HANDLE hTimer; // ожидающий таймер 

DWORD WINAPI thread(LPVOID)
{
	// ждем сигнал от ожидающего таймера 
	WaitForSingleObject(hTimer, INFINITE);
	// выводим сообщение 
	cout<<"\nThe timer is signaled." << endl;
	return 0;
}

int main()
{
	cout << "start" << endl;
	HANDLE hThread;
	DWORD IDThread;
	_int64 qwTimeInterval; // время задержки для таймера 
	// создаем ожидающий таймер  

	hTimer = CreateWaitableTimer(NULL, FALSE, NULL);
	if (hTimer == NULL)
		return GetLastError();
	// время задержки для таймера = 3 секунды 
	qwTimeInterval = -3 * _SECOND;
	// инициализируем таймер 
	if (!SetWaitableTimer(
		hTimer, // дескриптор таймера 
		(LARGE_INTEGER*)&qwTimeInterval, // временной интервал 
		0, // непериодический таймер 
		NULL, // процедуры завершения нет 
		NULL, // параметров к этой процедуре нет 
		FALSE // режим сбережения энергии не устанавливать 
	))
	{
		cout << "Set waitable timer failed." << endl
		<< "The last error code: " << GetLastError() << endl;
		return 0;
	}
	// запускаем поток 
	hThread = CreateThread(NULL, 0, thread, NULL, 0, &IDThread);
	if (hThread == NULL)
		return GetLastError();
	// ждем, пока поток закончит работу 
	WaitForSingleObject(hThread, INFINITE);
	// закрываем дескрипторы 
	CloseHandle(hThread);
	CloseHandle(hTimer);
	return 0;
}