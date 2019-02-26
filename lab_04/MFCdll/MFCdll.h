// MFCdll.h: основной файл заголовка для библиотеки DLL MFCdll
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CMFCdllApp
// Реализацию этого класса см. в файле MFCdll.cpp
//

class CMFCdllApp : public CWinApp
{
public:
	CMFCdllApp();

// Переопределение
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
