#pragma once

// ActiveXCPP2.h: ������� ���� ��������� ��� ActiveXCPP2.DLL

#if !defined( __AFXCTL_H__ )
#error "�������� afxctl.h �� ��������� ����� �����"
#endif

#include "resource.h"       // �������� �������


// CActiveXCPP2App: ��� ���������� ��. ActiveXCPP2.cpp.

class CActiveXCPP2App : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

