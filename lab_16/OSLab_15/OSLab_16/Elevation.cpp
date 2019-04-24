#include "stdafx.h"
#include <Windows.h>

BOOL IsRunAsAdministrator()
// ���� ����� ���������, ������ �� �� ����� �������������� ��� ���������� ���������.
// ���������� ��������� ����������, ������� ���������� ���� ����.
{
	BOOL fIsRunAsAdmin = FALSE;
	DWORD dwError = ERROR_SUCCESS;
	PSID pAdministratorsGroup = NULL;

	SID_IDENTIFIER_AUTHORITY NtAuthority = SECURITY_NT_AUTHORITY;
	if (!AllocateAndInitializeSid( // ������� AllocateAndInitializeSid �������� � �������������� ������������� ������������ (SID) �������� � ������� ���������.
		&NtAuthority,                // ��������� �� ��������� SID_IDENTIFIER_AUTHORITY . ��� ��������� ������������� �������� ���������� �������������� �������� ������ ��� ��������� � SID.
		2,                           // ���������� ���������� �������� ��� ���������� � SID. 
		SECURITY_BUILTIN_DOMAIN_RID, //
		DOMAIN_ALIAS_RID_ADMINS,
		0, 0, 0, 0, 0, 0,
		&pAdministratorsGroup))      // ��������� �� ����������, ������� �������� ��������� �� ���������� � ������������������ ��������� SID .
	{
		dwError = GetLastError();
		goto Cleanup;
	}

	if (!CheckTokenMembership(NULL, pAdministratorsGroup, &fIsRunAsAdmin))
		// ��������� SID �� ������
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

void ElevateNow() // ������ ����� �������� ������� ����� ����.
{
	BOOL bAlreadyRunningAsAdministrator = FALSE; // ������ �� �� ����� ��������������. 
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