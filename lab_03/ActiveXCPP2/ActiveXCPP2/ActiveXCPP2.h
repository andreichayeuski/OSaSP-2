#pragma once

// ActiveXCPP2.h: главный файл заголовка для ActiveXCPP2.DLL

#if !defined( __AFXCTL_H__ )
#error "включить afxctl.h до включения этого файла"
#endif

#include "resource.h"       // основные символы


// CActiveXCPP2App: про реализацию см. ActiveXCPP2.cpp.

class CActiveXCPP2App : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

