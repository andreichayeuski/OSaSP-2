#pragma once

// ActiveXCPP2PropPage.h: объявление класса страницы свойств CActiveXCPP2PropPage.


// CActiveXCPP2PropPage: про реализацию см. ActiveXCPP2PropPage.cpp.

class CActiveXCPP2PropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CActiveXCPP2PropPage)
	DECLARE_OLECREATE_EX(CActiveXCPP2PropPage)

// Конструктор
public:
	CActiveXCPP2PropPage();

// Данные диалогового окна
	enum { IDD = IDD_PROPPAGE_ACTIVEXCPP2 };

// Реализация
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
};

