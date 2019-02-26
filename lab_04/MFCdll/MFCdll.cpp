// MFCdll.cpp: определяет процедуры инициализации для библиотеки DLL.
//

#include "stdafx.h"
#include "MFCdll.h"
#include<iostream>
#include<objbase.h>
#include"IFace.h"
#include"GUID.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: если эта библиотека DLL динамически связана с библиотеками DLL MFC,
//		все функции, экспортированные из данной DLL-библиотеки, которые выполняют вызовы к
//		MFC, должны содержать макрос AFX_MANAGE_STATE в
//		самое начало функции.
//
//		Например:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// тело нормальной функции
//		}
//
//		Важно, чтобы данный макрос был представлен в каждой
//		функции до вызова MFC.  Это означает, что
//		должен стоять в качестве первого оператора в
//		функции и предшествовать даже любым объявлениям переменных объекта,
//		поскольку их конструкторы могут выполнять вызовы к MFC
//		DLL.
//
//		В Технических указаниях MFC 33 и 58 содержатся более
//		подробные сведения.
//

// CMFCdllApp

BEGIN_MESSAGE_MAP(CMFCdllApp, CWinApp)
END_MESSAGE_MAP()


// Создание CMFCdllApp

CMFCdllApp::CMFCdllApp()
{
	// TODO: добавьте код создания,
	// Размещает весь важный код инициализации в InitInstance
}


// Единственный объект CMFCdllApp

CMFCdllApp theApp;


// Инициализация CMFCdllApp

BOOL CMFCdllApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

void trace(const char* msg)
{
	printf(msg);
}

class CA :public IX
{
	virtual HRESULT __stdcall QueryInterface(const IID& iid, void** ppv);
	virtual ULONG __stdcall AddRef();
	virtual ULONG __stdcall Release();

	virtual void __stdcall Fx() { printf("Call Fx()!");}
public:
	CA():m_cRef(0){}
	~CA() { trace("Ликвидация"); }
private:
	long m_cRef;
};
HRESULT __stdcall CA::QueryInterface(const IID& iid, void** ppv)
{
	if (iid == IID_IUnknown)
	{
		trace("Возвратить указатель на IUnknown");
		*ppv = static_cast<IX*>(this);
	}
	else if (iid == IID_IX)
	{
		trace("Возвратить указатель на IX");
		*ppv = static_cast<IX*>(this);
	}
	else
	{
		trace("Интерфейс не поддерживается");
		*ppv = NULL;
		return E_NOINTERFACE;
	}
	reinterpret_cast<IUnknown*>(*ppv)->AddRef();
	return S_OK;
}

ULONG __stdcall CA::AddRef()
{
	return InterlockedIncrement(&m_cRef);
}

ULONG __stdcall CA::Release()
{
	if (InterlockedDecrement(&m_cRef) == 0)
	{
		delete this;
		return 0;
	}
	return m_cRef;
}

extern "C" IUnknown* CreateInstance()
{
	IUnknown* pI = static_cast<IX*>(new CA);
	pI->AddRef();
	return pI;
}

extern "C" double __stdcall Sum() 
{
	double a, b;
	std::cout << "Введите 2 числа:" << std::endl;
	std::cin >> a;
	std::cin >> b;
	return (a + b); 
};