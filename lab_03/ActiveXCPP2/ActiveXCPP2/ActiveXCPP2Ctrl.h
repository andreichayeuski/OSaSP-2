#define DISPID_TEST_METHOD (1025314)
#pragma once

// ActiveXCPP2Ctrl.h: объявление класса элемента управления ActiveX для CActiveXCPP2Ctrl.


// CActiveXCPP2Ctrl: про реализацию см. ActiveXCPP2Ctrl.cpp.

class CActiveXCPP2Ctrl : public COleControl
{
	DECLARE_DYNCREATE(CActiveXCPP2Ctrl)

// Конструктор
public:
	CActiveXCPP2Ctrl();

// Переопределение
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// Реализация
protected:
	~CActiveXCPP2Ctrl();

	DECLARE_OLECREATE_EX(CActiveXCPP2Ctrl)    // Фабрика класса и guid
	DECLARE_OLETYPELIB(CActiveXCPP2Ctrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CActiveXCPP2Ctrl)     // ИД страницы свойств
	DECLARE_OLECTLTYPE(CActiveXCPP2Ctrl)		// Введите имя и промежуточное состояние

// Схемы сообщений
	DECLARE_MESSAGE_MAP()

// Схемы подготовки к отправке
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();
	afx_msg double TestMyMethod(LONG param1);

// Схемы событий
	DECLARE_EVENT_MAP()

// Подготовка к отправке и ИД событий
public:
	enum {
	};
};

