#pragma once

// ActiveXCPP2PropPage.h: ���������� ������ �������� ������� CActiveXCPP2PropPage.


// CActiveXCPP2PropPage: ��� ���������� ��. ActiveXCPP2PropPage.cpp.

class CActiveXCPP2PropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CActiveXCPP2PropPage)
	DECLARE_OLECREATE_EX(CActiveXCPP2PropPage)

// �����������
public:
	CActiveXCPP2PropPage();

// ������ ����������� ����
	enum { IDD = IDD_PROPPAGE_ACTIVEXCPP2 };

// ����������
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

// ����� ���������
protected:
	DECLARE_MESSAGE_MAP()
};

