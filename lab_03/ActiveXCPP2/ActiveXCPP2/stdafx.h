#pragma once

// stdafx.h: ���������� ���� ��� ����������� ��������� ���������� ������
// ��� ���������� ������ ��� ����������� �������, ������� ����� ������������,
// �� �� ����� ����������

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // ��������� ����� ������������ ���������� �� ���������� Windows
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // ��������� ������������ CString ����� ������
#define _ATL_NO_AUTOMATIC_NAMESPACE             // ��������� ���������� ���� �������

#include <afxctl.h>         // ��������� MFC ��� ��������� ���������� ActiveX
#include <afxext.h>         // ���������� MFC
#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // ��������� MFC ��� ������� ��������� ���������� Internet Explorer 4
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>                     // ��������� MFC ��� ������� ��������� ���������� Windows
#endif // _AFX_NO_AFXCMN_SUPPORT

// ������� ��� ����������� ���� ���������, ���� �� ������ ������������
//  ������ ��� ������ MFC
#ifndef _WIN64

#ifndef _AFX_NO_DB_SUPPORT
#include <afxdb.h>                      // ������ ��� ������ MFC ODBC
#endif // _AFX_NO_DB_SUPPORT

#ifndef _AFX_NO_DAO_SUPPORT
#include <afxdao.h>                     // ������ ��� ������ MFC DAO
#endif // _AFX_NO_DAO_SUPPORT

#endif // _WIN64

