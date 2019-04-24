// OS_Lab_13.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include "windows.h"

SERVICE_STATUS          serviceStatus;
SERVICE_STATUS_HANDLE   serviceStatusHandle;

DWORD ServiceInitialization(DWORD   argc, LPTSTR  *argv, DWORD *specificError);
// Application define ServiceMain()...
void WINAPI ServiceStart(DWORD argc, LPTSTR *argv);
void WINAPI ServiceCtrlHandler(DWORD opcode);
void SvcDebugOut(LPSTR String, DWORD Status);

int main()
{
	SERVICE_TABLE_ENTRY ServiceTable[1];
	ServiceTable[0].lpServiceName = (LPWSTR)TEXT("SERV_G");
	ServiceTable[0].lpServiceProc = (LPSERVICE_MAIN_FUNCTION)ServiceStart;

	if (!StartServiceCtrlDispatcher(ServiceTable))
	{
		printf("Error in registration:%x", GetLastError());

	}
	else

	{
		printf("Registration OK");
	}

	getchar();
	return 0;
}


DWORD ServiceInitialization(DWORD argc, LPTSTR *argv, DWORD *specificError)
{
	*argv;
	argc;
	specificError;
	// should return status...
	return 0;
}

void WINAPI ServiceStart(DWORD argc, LPTSTR *argv)
{
	DWORD status;
	DWORD specificError;
	// Type of service, application or driver...
	serviceStatus.dwServiceType = SERVICE_WIN32;
	// The service is starting...
	serviceStatus.dwCurrentState = SERVICE_START_PENDING;
	// The service can be stopped & can be paused and continued.
	serviceStatus.dwControlsAccepted = SERVICE_ACCEPT_STOP | SERVICE_ACCEPT_PAUSE_CONTINUE;
	serviceStatus.dwWin32ExitCode = 0;
	serviceStatus.dwServiceSpecificExitCode = 0;
	serviceStatus.dwCheckPoint = 0;
	serviceStatus.dwWaitHint = 0;

	serviceStatusHandle = RegisterServiceCtrlHandler(TEXT("SERV_G"), ServiceCtrlHandler);

	if (serviceStatusHandle == (SERVICE_STATUS_HANDLE)0)
	{
		SvcDebugOut((LPSTR)"[MY_SERVICE] RegisterServiceCtrlHandler() failed, error: %d.\n", GetLastError());
		return;
	}
	else
		printf("RegisterServiceCtrlHandler() looks OK.\n");

	//===============================================================
	   // Initialization code goes here. Return the status...
	status = ServiceInitialization(argc, argv, &specificError);
	// Handle error condition
	if (status != NO_ERROR)
	{
		// The service is not running...
		serviceStatus.dwCurrentState = SERVICE_STOPPED;
		serviceStatus.dwCheckPoint = 0;
		serviceStatus.dwWaitHint = 0;
		serviceStatus.dwWin32ExitCode = status;
		serviceStatus.dwServiceSpecificExitCode = specificError;
		SetServiceStatus(serviceStatusHandle, &serviceStatus);
		return;
	}

	// Initialization complete - report running status.
	serviceStatus.dwCurrentState = SERVICE_RUNNING;
	serviceStatus.dwCheckPoint = 0;
	serviceStatus.dwWaitHint = 0;

	if (!SetServiceStatus(serviceStatusHandle, &serviceStatus))
	{
		status = GetLastError();
		SvcDebugOut((LPSTR)"SetServiceStatus() error: %ld\n", status);
	}
	else
		printf("SetServiceStatus() looks OK.\n");
	// By assuming starting and initializing the service is OK, this
	// is where the service does its work...
	SvcDebugOut((LPSTR)"Returning the Main Thread.\n", 0);
	return;
}
BOOL MySystemShutdown()
{
	HANDLE hToken;
	TOKEN_PRIVILEGES tkp;

	// Получаем маркер текущего процесса.

	if (!OpenProcessToken(GetCurrentProcess(),
		TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken))
		return(FALSE);

	// Получаем LUID для привелегии завершения работы.

	LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME,
		&tkp.Privileges[0].Luid);

	tkp.PrivilegeCount = 1;  // будет установлена одна привелегия
	tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

	// Получаем привелегию завершения работы для этого процесса.

	AdjustTokenPrivileges(hToken, FALSE, &tkp, 0,
		(PTOKEN_PRIVILEGES)NULL, 0);

	if (GetLastError() != ERROR_SUCCESS)
		return FALSE;

	// Шутдауним систему и заставляем все приложения закрыться.

	if (!ExitWindowsEx(EWX_SHUTDOWN | EWX_FORCE, 0))
		return FALSE;

	return TRUE;
}
int addLogMessage(const char* text)
{
	std::ofstream out;          // поток для записи
	out.open("D:\\Документы\\Университет\\6 семестр\\ОС\\lab_13\\Debug\\1.txt"); // окрываем файл для записи
	if (out.is_open())
	{
		out << text << std::endl;
	}
	return 0;
}
void  WINAPI ServiceCtrlHandler(DWORD request)
{
	switch (request)
	{
	case SERVICE_CONTROL_STOP:
		addLogMessage("Stopped.");

		serviceStatus.dwWin32ExitCode = 0;
		serviceStatus.dwCurrentState = SERVICE_STOPPED;
		SetServiceStatus(serviceStatusHandle, &serviceStatus);
		MySystemShutdown();
		return;

	case SERVICE_CONTROL_SHUTDOWN:
		addLogMessage("Shutdown.");
		serviceStatus.dwWin32ExitCode = 0;
		serviceStatus.dwCurrentState = SERVICE_STOPPED;
		SetServiceStatus(serviceStatusHandle, &serviceStatus);

		
		return;

	default:
		break;
	}

	SetServiceStatus(serviceStatusHandle, &serviceStatus);

	return;
}



void SvcDebugOut(LPSTR String, DWORD Status)
{
	CHAR  Buffer[1024];

	if (strlen(String) < 1000)
	{
		sprintf(Buffer, String, Status);
		OutputDebugStringA(Buffer);
	}
	else
		printf("String too long...\n");
}
