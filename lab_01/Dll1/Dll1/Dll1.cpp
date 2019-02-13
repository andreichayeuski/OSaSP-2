// Dll1.cpp : Определяет экспортированные функции для приложения DLL.
//

#include "stdafx.h"
#include<iostream>
#include <Windows.h>
#include <fstream>
#include <ctime>

#pragma warning(disable : 4996)
using namespace std;

extern "C++" __declspec(dllexport) void WriteFile()
{
	cout << "Введите строку для записи в файл\n";
	char str[256];
	cin.getline(str, 256);
	ofstream out;
	out.open("D:\\Документы\\Университет\\6 семестр\\ОС\\lab_01\\1.txt");
	if (out.is_open())
	{
		out << str;
	}
}
extern "C++" __declspec(dllexport) void StartProc()
{
	STARTUPINFO cif;
	ZeroMemory(&cif, sizeof(STARTUPINFO));
	PROCESS_INFORMATION pi;

	CreateProcess(L"C:\\Program Files\\Notepad\\notepad.exe", NULL, NULL, NULL, FALSE, NULL, NULL, NULL, &cif, &pi);
	
}

extern "C++" __declspec(dllexport) void CheckFile()
{
	setlocale(LC_CTYPE, "rus");
	char z[256];
	cout << "введите имя файла\n";
	cin.getline(z,256);
	ifstream file;
	file.open(z);
	if (!file)
		cout << "Файл не найден\n";
	else
		cout << "Файл существует\n";
}


extern "C++" __declspec(dllexport) BOOL EdrCenterText(HDC hdc, PRECT prc, LPCWSTR pStr)
{
	int iLength;
	SIZE size;
	iLength = wcslen(pStr);
	GetTextExtentPoint32(hdc, pStr, iLength, &size);
	return TextOut(hdc, (prc->right - prc->left - size.cx) / 2,
		(prc->bottom - prc->top - size.cy) / 2,
		pStr, iLength);
}


extern "C" __declspec(dllexport) int __stdcall GetTime()
{
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	cout << "Current Datetime:" << asctime(timeinfo) << endl;
	return 0;
}
