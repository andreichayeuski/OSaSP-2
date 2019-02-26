// ActiveXCPP2Ctrl.cpp: реализация класса CActiveXCPP2Ctrl элемента ActiveX.

#include "stdafx.h"
#include "ActiveXCPP2.h"
#include "ActiveXCPP2Ctrl.h"
#include "ActiveXCPP2PropPage.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CActiveXCPP2Ctrl, COleControl)

// Схема сообщений

BEGIN_MESSAGE_MAP(CActiveXCPP2Ctrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()

// Схема подготовки к отправке

BEGIN_DISPATCH_MAP(CActiveXCPP2Ctrl, COleControl)
	DISP_FUNCTION_ID(CActiveXCPP2Ctrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CActiveXCPP2Ctrl, "TestMyMethod",
		DISPID_TEST_METHOD, TestMyMethod,
		VT_R8, VTS_I4)
END_DISPATCH_MAP()

// Схема событий

BEGIN_EVENT_MAP(CActiveXCPP2Ctrl, COleControl)
END_EVENT_MAP()

// Страницы свойств

// TODO: при необходимости добавьте дополнительные страницы свойств.  Не забудьте увеличить значение счетчика.
BEGIN_PROPPAGEIDS(CActiveXCPP2Ctrl, 1)
	PROPPAGEID(CActiveXCPP2PropPage::guid)
END_PROPPAGEIDS(CActiveXCPP2Ctrl)

// Инициализировать фабрику класса и guid

IMPLEMENT_OLECREATE_EX(CActiveXCPP2Ctrl, "ACTIVEXCPP2.ActiveXCPP2Ctrl.1",
	0x23a90978, 0x5d84, 0x403e, 0xbb, 0xb2, 0x43, 0x68, 0x73, 0x8e, 0xa4, 0x38)

// Введите ИД и версию библиотеки

IMPLEMENT_OLETYPELIB(CActiveXCPP2Ctrl, _tlid, _wVerMajor, _wVerMinor)

// ИД интерфейса

const IID IID_DActiveXCPP2 = { 0x292B3356, 0xFB9C, 0x4FB8, { 0x9C, 0x2E, 0x85, 0x71, 0x13, 0xA3, 0x28, 0xE9 } };
const IID IID_DActiveXCPP2Events = { 0xB2962934, 0x7A14, 0x4FFB, { 0x84, 0x63, 0xF8, 0x22, 0x8, 0x7A, 0xE6, 0x4D } };

// Сведения о типах элементов управления

static const DWORD _dwActiveXCPP2OleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CActiveXCPP2Ctrl, IDS_ACTIVEXCPP2, _dwActiveXCPP2OleMisc)

// CActiveXCPP2Ctrl::CActiveXCPP2CtrlFactory::UpdateRegistry -
// Добавление или удаление записей системного реестра для CActiveXCPP2Ctrl

BOOL CActiveXCPP2Ctrl::CActiveXCPP2CtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: убедитесь, что элементы управления следуют правилам модели изолированных потоков.
	// Дополнительные сведения см. в MFC TechNote 64.
	// Если элемент управления не соответствует правилам модели изоляции, то
	// необходимо модифицировать приведенный ниже код, изменив значение 6-го параметра с
	// afxRegApartmentThreading на 0.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_ACTIVEXCPP2,
			IDB_ACTIVEXCPP2,
			afxRegApartmentThreading,
			_dwActiveXCPP2OleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


// CActiveXCPP2Ctrl::CActiveXCPP2Ctrl - Конструктор

CActiveXCPP2Ctrl::CActiveXCPP2Ctrl()
{
	InitializeIIDs(&IID_DActiveXCPP2, &IID_DActiveXCPP2Events);
	// TODO: Инициализируйте здесь данные экземпляра элемента управления.
}

// CActiveXCPP2Ctrl::~CActiveXCPP2Ctrl - Деструктор

CActiveXCPP2Ctrl::~CActiveXCPP2Ctrl()
{
	// TODO: Выполните здесь очистку данных экземпляра элемента управления.
}

// CActiveXCPP2Ctrl::OnDraw - функция рисования

void CActiveXCPP2Ctrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& /* rcInvalid */)
{
	if (!pdc)
		return;

	// TODO: Замените следующий код собственным кодом рисования.
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}

// CActiveXCPP2Ctrl::DoPropExchange - поддержка сохранения

void CActiveXCPP2Ctrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Вызывать функции PX_ для каждого постоянного настраиваемого свойства.
}


// CActiveXCPP2Ctrl::OnResetState - сброс элемента управления к состоянию по умолчанию

void CActiveXCPP2Ctrl::OnResetState()
{
	COleControl::OnResetState();  // Сбрасывает значения по умолчанию, найденные в DoPropExchange

	// TODO: Сбросьте здесь состояние любого другого элемента управления.
}


// CActiveXCPP2Ctrl::AboutBox - показывает пользователю панель "О программе"

void CActiveXCPP2Ctrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_ACTIVEXCPP2);
	dlgAbout.DoModal();
}


// обработчики сообщений CActiveXCPP2Ctrl
double CActiveXCPP2Ctrl::TestMyMethod(LONG param1)
{
	double d = param1*param1*3.14;
	return d;
}