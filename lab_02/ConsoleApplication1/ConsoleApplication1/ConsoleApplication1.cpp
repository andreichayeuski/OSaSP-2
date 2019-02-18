// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <objbase.h>
#include "..\ConsoleApplication2\int.h"

void trace(const char*msg)
{
	std::cout << msg << std::endl;
}

//Интерфейсы
//interface IX :IUnknown
//{
//	virtual void __stdcall Fx() = 0;
//	virtual void __stdcall Fx1() = 0;
//};
//
//interface IY :IUnknown
//{
//	virtual void __stdcall Fy() = 0;
//};

//Предварительное объявление GUID
extern const IID IID_IX;
extern const IID IID_IY;
//Компонент
class CA : public IX, public IY
{
	virtual HRESULT __stdcall QueryInterface(const IID&  iid,
		void** ppv);
	virtual ULONG __stdcall AddRef() { return 0; }
	virtual ULONG __stdcall Release() { return 0; }
	virtual void __stdcall Fx() { std::cout << "Hi, from FX" << std::endl; };
	virtual void __stdcall Fx1(int i) { std::cout << i * i  << std::endl; };
	virtual void __stdcall Fy() { std::cout << "Hi, from FY" << std::endl; };
};

HRESULT __stdcall CA::QueryInterface(const IID& iid, void ** ppv)
{
	if (iid == IID_IUnknown)
	{
		trace("return a pointer to IUnknown");
		*ppv = static_cast<IX*>(this);
	}
	else
		if (iid == IID_IX)
		{
			trace("return a pointer to IX");
			*ppv = static_cast<IX*>(this);
		}

		else
			if (iid == IID_IY)
			{
				trace("return a pointer to IY");
				*ppv = static_cast<IY*>(this);
			}
			else
			{
				trace("Interface not supported");
				*ppv = NULL;
				return E_NOINTERFACE;
			}
	reinterpret_cast<IUnknown*>(*ppv)->AddRef();
	return S_OK;
}

//Функция создания
IUnknown* CreateInstance()
{
	IUnknown* pI = static_cast<IY*> (new CA);
	pI->AddRef();
	return pI;


}
//  IID
// {32bb8320-b41b-11cf-a6bb-0080c7b2d682}
static const IID IID_IX =
{ 0x32bb8320, 0xb41b, 0x11cf,
{0xa6, 0xbb,0x0,0x80,0xc7,0xb2,0xd6,0x82} };
// {32bb8321-b41b-11cf-a6bb-0080c7b2d682}
static const IID IID_IY =
{ 0x32bb8321, 0xb41b, 0x11cf,
{0xa6, 0xbb,0x0,0x80,0xc7,0xb2,0xd6,0x82} };


//Клиент
int main()
{

	HRESULT hr,hh;
	trace("Get a pointer to Iunknown");
	IUnknown* pIUnknown = CreateInstance();
	trace("Get a pointer to IX");
	IX* pIX = NULL;
	IY* pIY = NULL;
	hr = pIUnknown->QueryInterface(IID_IX, (void**)&pIX);
	hh= pIUnknown->QueryInterface(IID_IY, (void**)&pIY);
	if (SUCCEEDED(hr))
	{
		trace("IX gotcha successfully!");
		pIX->Fx();
		int chislo = 0;
		std::cin >> chislo;
		pIX->Fx1(chislo);
	}
	if (SUCCEEDED(hh))
	{
		trace("IY gotcha successfully!");
		pIY->Fy();
	}
	std::cout << "Press any key" << std::endl;
	getchar();
	//delete pIUnknown;
	return 0;
}

