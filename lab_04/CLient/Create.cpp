#include"pch.h"
#include<iostream>
#include <unknwn.h>
#include "Create.h"
using namespace std;

typedef IUnknown* (*CREATEFUNCPTR)();
typedef double(*LPGETNUMBER)();
typedef double (*SumAB) (double a,double b);

IUnknown* CallCreateInstance(char* name)
{
	HINSTANCE hComponent = ::LoadLibrary(TEXT("MFCdll.dll"));
	if (hComponent == NULL)
	{
		cout << "CallCreateInstance:\t������: �� ���� ��������� ���������"<< endl;
		return NULL;
	}

	CREATEFUNCPTR CreateInstance = (CREATEFUNCPTR)::GetProcAddress(hComponent, "CreateInstance");
	if (CreateInstance == NULL)
	{
		cout << "CallCreateInstance:\t������: "
			<< "�� ���� ����� ������� CreateInstance"
			<< endl;
		return NULL;
	}
	return CreateInstance();
}

double CallSum(char * name)
{
	HINSTANCE hComponent = ::LoadLibrary(TEXT("MFCdll.dll"));
	if (hComponent == NULL)
	{
		cout << "CallSum:\t������: �� ���� ��������� ���������"<< endl;
		return NULL;
	}

	LPGETNUMBER Sum = (LPGETNUMBER)::GetProcAddress(hComponent, "Sum");
	if (Sum == NULL)
	{
		cout << "CallSum:\t������: "
			<< "�� ���� ����� ������� Sum"
			<< endl;
		return NULL;
	}
	return Sum();
}