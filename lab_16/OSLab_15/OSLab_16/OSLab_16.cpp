// OSLab_16.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <Windows.h>

BOOL IsRunAsAdministrator();
void ElevateNow();

int main()
{
	if (IsRunAsAdministrator())
	{
	}
	else
	{
		if (MessageBox(0, L"Need To Elevate", L"Critical Disk Error", MB_SYSTEMMODAL | MB_ICONERROR | MB_YESNO) == IDYES)
		{
			ElevateNow();
		}
		else
		{
			MessageBox(0, L"You Better give me Elevation or I will attack u", L"System Critical Error", MB_SYSTEMMODAL | MB_OK | MB_ICONERROR);
			ElevateNow();
		}
	}
	getchar();
	return 0;
}

