#include "stdafx.h"
#include <Windows.h>

BOOL IsRunAsAdministrator()
// Этот метод проверяет, имеете ли Вы права администратора для выполнения программы.
// Возвращает булевскую переменную, которая определяет этот факт.
{
	BOOL fIsRunAsAdmin = FALSE;
	DWORD dwError = ERROR_SUCCESS;
	PSID pAdministratorsGroup = NULL;

	SID_IDENTIFIER_AUTHORITY NtAuthority = SECURITY_NT_AUTHORITY;
	if (!AllocateAndInitializeSid( // Функция AllocateAndInitializeSid выделяет и инициализирует идентификатор безопасности (SID) максимум с восемью подузлами.
		&NtAuthority,                // Указатель на структуру SID_IDENTIFIER_AUTHORITY . Эта структура предоставляет значение полномочий идентификатора верхнего уровня для установки в SID.
		2,                           // Определяет количество подузлов для размещения в SID. 
		SECURITY_BUILTIN_DOMAIN_RID, //
		DOMAIN_ALIAS_RID_ADMINS,
		0, 0, 0, 0, 0, 0,
		&pAdministratorsGroup))      // Указатель на переменную, которая получает указатель на выделенную и инициализированную структуру SID .
	{
		dwError = GetLastError();
		goto Cleanup;
	}

	if (!CheckTokenMembership(NULL, pAdministratorsGroup, &fIsRunAsAdmin))
		// ПРОВЕРЯЕТ SID на админа
	{
		dwError = GetLastError();
		goto Cleanup;
	}

Cleanup:

	if (pAdministratorsGroup)
	{
		FreeSid(pAdministratorsGroup);
		pAdministratorsGroup = NULL;
	}

	if (ERROR_SUCCESS != dwError)
	{
		throw dwError;
	}

	return fIsRunAsAdmin;
}

void ElevateNow() // Второй метод повышает уровень Ваших прав.
{
	BOOL bAlreadyRunningAsAdministrator = FALSE; // имеете ли Вы права администратора. 
	try
	{
		bAlreadyRunningAsAdministrator = IsRunAsAdministrator();
	}
	catch (...)
	{
		//_asm nop
	}
	if (!bAlreadyRunningAsAdministrator)
	{
		char szPath[MAX_PATH];
		if (GetModuleFileName(NULL, (LPWSTR)szPath, ARRAYSIZE(szPath)))
		{
			SHELLEXECUTEINFO sei = { sizeof(sei) };

			sei.lpVerb = L"runas";
			sei.lpFile = (LPCWSTR)szPath;
			sei.hwnd = NULL;
			sei.nShow = SW_NORMAL;

			if (!ShellExecuteEx(&sei))
			{
				DWORD dwError = GetLastError();
				if (dwError == ERROR_CANCELLED)
					//Annoys you to Elevate it LOL
					CreateThread(0, 0, (LPTHREAD_START_ROUTINE)ElevateNow, 0, 0, 0);
			}
		}
	}
	else
	{
		///Code
	}
}