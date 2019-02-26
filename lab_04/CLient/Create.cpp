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
		cout << "CallCreateInstance:\tОшибка: Не могу загрузить компонент"<< endl;
		return NULL;
	}

	CREATEFUNCPTR CreateInstance = (CREATEFUNCPTR)::GetProcAddress(hComponent, "CreateInstance");
	if (CreateInstance == NULL)
	{
		cout << "CallCreateInstance:\tОшибка: "
			<< "Не могу найти функцию CreateInstance"
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
		cout << "CallSum:\tОшибка: Не могу загрузить компонент"<< endl;
		return NULL;
	}

	LPGETNUMBER Sum = (LPGETNUMBER)::GetProcAddress(hComponent, "Sum");
	if (Sum == NULL)
	{
		cout << "CallSum:\tОшибка: "
			<< "Не могу найти функцию Sum"
			<< endl;
		return NULL;
	}
	return Sum();
}