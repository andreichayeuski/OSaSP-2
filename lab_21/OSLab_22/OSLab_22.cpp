// OSLab_22.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <wincrypt.h>
#include <cryptuiapi.h>
#include <iostream>
#include <fstream>
#include <string>
#include <tchar.h>

#define ENCRYPT_BLOCK_SIZE 8
#pragma comment (lib, "crypt32.lib")
#pragma comment (lib, "cryptui.lib")
using namespace std;

#define TASK1
//#define TASK2

int _tmain(int argc, _TCHAR* argv[])
{
#ifdef TASK1
	char* buffer;
	ifstream is;
	is.open("D:/test.txt", ios::binary);
	is.seekg(0, ios::end);
	int len = is.tellg();
	is.seekg(0, ios::beg);
	buffer = new char[len];
	is.read(buffer, len);
	is.close();

	HCRYPTPROV hProv;
	HCRYPTKEY hSessionKey;

	if (!CryptAcquireContext(&hProv, NULL, NULL, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT))
	{
		std::cout << "Error in CryptAcquireContext1" << std::endl;
		return 1;
	}
	std::cout << "Cryptographic provider initialized" << std::endl;

	if (!CryptGenKey(hProv, CALG_RC4, CRYPT_EXPORTABLE, &hSessionKey))
	{
		std::cout << "CryptGenKey" << std::endl;
		return 1;
	}
	std::cout << "Session key generated" << std::endl;

	DWORD count = strlen(buffer);
	DWORD dwBufferLen = count + ENCRYPT_BLOCK_SIZE - (count % ENCRYPT_BLOCK_SIZE);

	char* pbBuffer = (char*)malloc(dwBufferLen);

	if (!CryptEncrypt(hSessionKey, 0, true, 0, (BYTE*)buffer, &count, strlen(buffer)))
	{
		std::cout << "Error in CryptEncrypt" << std::endl;
		return 1;
	}
	std::cout << "Encryption completed" << std::endl;

	std::cout << "Encrypted string: " << buffer << std::endl;
	memcpy(pbBuffer, buffer, count);

	if (CryptDecrypt(hSessionKey, 0, TRUE, 0, (LPBYTE)pbBuffer, &count))
	{
		std::cout << "After decryption: ";
		cout.write(pbBuffer, len);
		std::cout << "\n";
	}

	getchar();
	return 0;
#endif
#ifdef TASK2
	HCRYPTPROV hProv;
	HCRYPTKEY hSessionKey;
	system("chcp 1251");

	if (!CryptAcquireContextW(&hProv, NULL, NULL, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT))	//криптопровайдер
	{
		cout << "Error in Crypto" << endl;
		return 1;
	}

	CryptGenKey(hProv, CALG_RC4, CRYPT_EXPORTABLE, &hSessionKey);	//ключ

	char ch = _getch();
	string str = "";
	int i = 0;
	while (ch != 13)
	{
		_putch('*');
		str += ch;
		ch = _getch();
	}

	cout << "\nYou enter string: " << str << endl;

	const char* string2 = str.c_str();
	DWORD len = strlen(string2);

	if (!CryptEncrypt(hSessionKey, 0, true, 0, (BYTE*)string2, &len, strlen(string2)))	//шифрование
	{
		cout << "Error in Crypto" << endl;
		cout << GetLastError();
		return 1;
	}

	char *string = new char[2];
	ifstream fin("D:/pass.txt");
	fin >> string;
	fin.close();
	DWORD delen = strlen(string);
	PBYTE pbBuffer = (BYTE *)malloc(delen);

	if (!CryptEncrypt(hSessionKey, 0, true, 0, (BYTE*)string, &delen, strlen(string)))	//шифрование
	{
		cout << "Error in Crypto" << endl;
		return 1;
	}

	if (strcmp(string, string2) == 0)
		cout << "You are welcome";
	else
		cout << "Wrong password";

	//memcpy(pbBuffer, string, delen);
	//if (CryptDecrypt(hSessionKey, 0, TRUE, 0, pbBuffer, &delen))		//дешифрование
	//{
	//	memcpy(string, pbBuffer, delen);
	//	cout << endl << "Decrypted string: " << string;
	//}

	getchar();
	return 0;
#endif
}