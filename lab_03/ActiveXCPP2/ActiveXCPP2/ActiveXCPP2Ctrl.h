#define DISPID_TEST_METHOD (1025314)
#pragma once

// ActiveXCPP2Ctrl.h: ���������� ������ �������� ���������� ActiveX ��� CActiveXCPP2Ctrl.


// CActiveXCPP2Ctrl: ��� ���������� ��. ActiveXCPP2Ctrl.cpp.

class CActiveXCPP2Ctrl : public COleControl
{
	DECLARE_DYNCREATE(CActiveXCPP2Ctrl)

// �����������
public:
	CActiveXCPP2Ctrl();

// ���������������
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// ����������
protected:
	~CActiveXCPP2Ctrl();

	DECLARE_OLECREATE_EX(CActiveXCPP2Ctrl)    // ������� ������ � guid
	DECLARE_OLETYPELIB(CActiveXCPP2Ctrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CActiveXCPP2Ctrl)     // �� �������� �������
	DECLARE_OLECTLTYPE(CActiveXCPP2Ctrl)		// ������� ��� � ������������� ���������

// ����� ���������
	DECLARE_MESSAGE_MAP()

// ����� ���������� � ��������
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();
	afx_msg double TestMyMethod(LONG param1);

// ����� �������
	DECLARE_EVENT_MAP()

// ���������� � �������� � �� �������
public:
	enum {
	};
};

