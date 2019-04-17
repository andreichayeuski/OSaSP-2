// Lab10.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "windows.h"
#include <ole2.h>
#include <iostream>

using namespace std;

HRESULT AutoWrap(int autoType, VARIANT *pvResult, IDispatch *pDisp,
	LPOLESTR ptName, int cArgs...)
{
	// Begin variable-argument list...
	va_list marker;
	va_start(marker, cArgs); //формируем список аргументов, передаваемых в cArgs

	if (!pDisp) {
		MessageBox(NULL, TEXT("NULL IDispatch passed to AutoWrap()"),
			TEXT("Error"), 0x10010);
		_exit(0);
	}
	// pDisp – это объект, на котoром выполняется метод, напр. document
	// Variables used...
	DISPPARAMS dp = { NULL, NULL, 0, 0 }; //структура определяет параметры,
										  // передаваемые в метод
	DISPID dispidNamed = DISPID_PROPERTYPUT;
	DISPID dispID;
	HRESULT hr;
	char buf[200];
	char szName[200];

	// Convert down to ANSI
	WideCharToMultiByte(CP_ACP, 0, ptName, -1, szName, 256, NULL, NULL);

	// Get DISPID for name passed...
	hr = pDisp->GetIDsOfNames(IID_NULL, &ptName, 1, LOCALE_USER_DEFAULT,
		&dispID);
	if (FAILED(hr)) {
		sprintf(buf,
			"IDispatch::GetIDsOfNames(\"%s\") failed w/err0x%08lx",
			szName, hr);
		MessageBox(NULL, TEXT("Click"), TEXT("AutoWrap()"), 0x10010);
		_exit(0);
		return hr;
	}

	// Allocate memory for arguments...
	VARIANT *pArgs = new VARIANT[cArgs + 1];

	// Extract arguments...
	for (int i = 0; i < cArgs; i++) {
		pArgs[i] = va_arg(marker, VARIANT);
	}

	// Build DISPPARAMS
	dp.cArgs = cArgs;
	dp.rgvarg = pArgs;

	// Handle special-case for property-puts!
	if (autoType & DISPATCH_PROPERTYPUT) {
		dp.cNamedArgs = 1;
		dp.rgdispidNamedArgs = &dispidNamed;
	}

	// Make the call!
	hr = pDisp->Invoke(dispID, IID_NULL, LOCALE_SYSTEM_DEFAULT, autoType,
		&dp, pvResult, NULL, NULL);
	if (FAILED(hr)) {
		sprintf(buf,
			"IDispatch::Invoke(\"%s\"=%08lx) failed w/err 0x%08lx",
			szName, dispID, hr);
		MessageBox(NULL, TEXT("Click Me"), TEXT("AutoWrap()"), 0x10010);
		_exit(0);
		return hr;
	}
	// End variable-argument section...
	va_end(marker);

	delete[] pArgs;

	return hr;

}

int main(int argc, char* argv[])
{
	// Initialize COM for this thread...
	CoInitialize(NULL);

	// Get CLSID for Word.Application...
	CLSID clsid;
	HRESULT hr = CLSIDFromProgID(L"Word.Application", &clsid);
	if (FAILED(hr)) {
		::MessageBox(NULL, TEXT("CLSIDFromProgID() failed"), TEXT("Error"),
			0x10010);
		return -1;
	}

	// Start Word and get IDispatch...
	IDispatch *pWordApp;
	hr = CoCreateInstance(clsid, NULL, CLSCTX_LOCAL_SERVER,
		IID_IDispatch, (void **)&pWordApp);
	if (FAILED(hr)) {
		::MessageBox(NULL, TEXT("Word not registered properly"),
			TEXT("Error"), 0x10010);
		return -2;
	}

	// Make Word visible
	{
		VARIANT x;
		x.vt = VT_I4;
		x.lVal = 1;
		AutoWrap(DISPATCH_PROPERTYPUT, NULL, pWordApp, L"Visible", 1,
			x);
	}

	// Get Documents collection
	IDispatch *pDocs;
	{
		VARIANT result;
		VariantInit(&result);
		AutoWrap(DISPATCH_PROPERTYGET, &result, pWordApp, L"Documents",
			0);

		pDocs = result.pdispVal;
	}
	//WIN32_FIND_DATA FindFileData;
	//HANDLE hFind = INVALID_HANDLE_VALUE;
	//TCHAR filesearch[50];
	//cout << "Enter file name: " << endl;
	//_getws_s(filesearch);
	//// Find the first file in the directory.
	//hFind = FindFirstFile(filesearch, &FindFileData);

	//if (hFind == INVALID_HANDLE_VALUE)
	//{
	//	printf("Invalid file handle. Error is %u.\n", GetLastError());
	//}
	//else
	//{
		// Call Documents.Open()
	IDispatch *pDoc0;
	{
		VARIANT result;
		VariantInit(&result);
		VARIANT x;
		x.vt = VT_BSTR;
		x.bstrVal = ::SysAllocString(L"D:\\a.docx");

		AutoWrap(DISPATCH_METHOD, &result, pDocs, L"Open", 1, x);
		pDoc0 = result.pdispVal;
		SysFreeString(x.bstrVal);

		::MessageBox(NULL,
			TEXT("Click Me"),
			TEXT("word doc"), 0x10000);

		//FindClose(hFind);

	}

	/*IDispatch *pDoc1;
	{
		VARIANT result;
		VariantInit(&result);
		AutoWrap(DISPATCH_PROPERTYGET, &result, pWordApp, L"ActiveDocument",
			0);

		pDoc1 = result.pdispVal;
		::MessageBox(NULL,
			TEXT("Click Me"),
			TEXT("word doc"), 0x10000);

	}*/
	IDispatch* pDocRas;
	{
		VARIANT result;
		VariantInit(&result);
		AutoWrap(DISPATCH_PROPERTYGET, &result, pWordApp, L"Selection",
			0);
		pDocRas = result.pdispVal;
	}
	/////
	IDispatch* pDocRas1;
	{
		VARIANT result;
		VariantInit(&result);
		VARIANT x;
		x.vt = VT_I4;
		x.lVal = 1;
		VARIANT y;
		y.vt = VT_I4;
		y.lVal = 1;
		AutoWrap(DISPATCH_METHOD, &result, pDocRas, L"MoveRight", 2, x, y);
		pDocRas1 = result.pdispVal;
	}
	IDispatch* pDocRas41;
	{
		VARIANT result;
		VariantInit(&result);
		VARIANT x;
		x.vt = VT_I4;
		x.lVal = 1;
		VARIANT y;
		y.vt = VT_I4;
		y.lVal = 1;
		VARIANT z;
		z.vt = VT_BOOL;
		z.lVal = true;
		AutoWrap(DISPATCH_METHOD, &result, pDocRas, L"MoveRight", 3, x, y, z);
		pDocRas41 = result.pdispVal;
	}
	/////
	IDispatch* pDocRas51;
	{
		VARIANT result;
		VariantInit(&result);
		AutoWrap(DISPATCH_PROPERTYGET, &result, pDocRas, L"Font",
			0);

		pDocRas51 = result.pdispVal;
	}
	IDispatch* pDocRas62;
	{
		VARIANT result;
		VariantInit(&result);
		VARIANT x, y, z;
		x.vt = VT_I4;
		x.lVal = 255;
		y.vt = VT_I4;
		y.lVal = 255;
		z.vt = VT_I4;
		z.lVal = 255;
		AutoWrap(DISPATCH_PROPERTYPUT, &result, pDocRas51, L"Color", 3, x, y, z);
		pDocRas62 = result.pdispVal;
	}

	IDispatch* pDocRas401;
	{
		VARIANT result;
		VariantInit(&result);
		VARIANT x;
		x.vt = VT_I4;
		x.lVal = 1;
		VARIANT y;
		y.vt = VT_I4;
		y.lVal = 1;
		VARIANT z;
		z.vt = VT_BOOL;
		z.lVal = true;
		AutoWrap(DISPATCH_METHOD, &result, pDocRas, L"MoveRight", 2, x, y);
		pDocRas401 = result.pdispVal;
	}

	IDispatch* pDocRas2;
	{
		VARIANT result;
		VariantInit(&result);
		AutoWrap(DISPATCH_PROPERTYGET, &result, pWordApp, L"Selection",
			0);
		pDocRas2 = result.pdispVal;
	}
	IDispatch* pDocRas411;
	{
		VARIANT result;
		VariantInit(&result);
		VARIANT x;
		x.vt = VT_I4;
		x.lVal = 1;
		VARIANT y;
		y.vt = VT_I4;
		y.lVal = 1;
		VARIANT z;
		z.vt = VT_BOOL;
		z.lVal = true;
		AutoWrap(DISPATCH_METHOD, &result, pDocRas2, L"MoveRight", 3, x, y, z);
		pDocRas411 = result.pdispVal;
	}
	/////
	IDispatch* pDocRas511;
	{
		VARIANT result;
		VariantInit(&result);
		AutoWrap(DISPATCH_PROPERTYGET, &result, pDocRas2, L"Font",
			0);

		pDocRas511 = result.pdispVal;
	}
	IDispatch* pDocRas621;
	{
		VARIANT result;
		VariantInit(&result);
		VARIANT x, y, z;
		x.vt = VT_I4;
		x.lVal = 26367;
		y.vt = VT_I4;
		y.lVal = 255;
		z.vt = VT_I4;
		z.lVal = 0;
		AutoWrap(DISPATCH_PROPERTYPUT, &result, pDocRas511, L"Color", 3, x, y, z);
		pDocRas621 = result.pdispVal;
	}

	IDispatch* pDocRas4011;
	{
		VARIANT result;
		VariantInit(&result);
		VARIANT x;
		x.vt = VT_I4;
		x.lVal = 1;
		VARIANT y;
		y.vt = VT_I4;
		y.lVal = 1;
		VARIANT z;
		z.vt = VT_BOOL;
		z.lVal = true;
		AutoWrap(DISPATCH_METHOD, &result, pDocRas2, L"MoveRight", 2, x, y);
		pDocRas4011 = result.pdispVal;
	}

	IDispatch* pDocRas21;
	{
		VARIANT result;
		VariantInit(&result);
		AutoWrap(DISPATCH_PROPERTYGET, &result, pWordApp, L"Selection",
			0);
		pDocRas21 = result.pdispVal;
	}
	IDispatch* pDocRas4111;
	{
		VARIANT result;
		VariantInit(&result);
		VARIANT x;
		x.vt = VT_I4;
		x.lVal = 1;
		VARIANT y;
		y.vt = VT_I4;
		y.lVal = 1;
		VARIANT z;
		z.vt = VT_BOOL;
		z.lVal = true;
		AutoWrap(DISPATCH_METHOD, &result, pDocRas21, L"MoveRight", 3, x, y, z);
		pDocRas4111 = result.pdispVal;
	}
	/////
	IDispatch* pDocRas5111;
	{
		VARIANT result;
		VariantInit(&result);
		AutoWrap(DISPATCH_PROPERTYGET, &result, pDocRas21, L"Font",
			0);

		pDocRas5111 = result.pdispVal;
	}
	IDispatch* pDocRas6211;
	{
		VARIANT result;
		VariantInit(&result);
		VARIANT x, y, z;
		x.vt = VT_I4;
		x.lVal = 65535;
		y.vt = VT_I4;
		y.lVal = 255;
		z.vt = VT_I4;
		z.lVal = 0;
		AutoWrap(DISPATCH_PROPERTYPUT, &result, pDocRas5111, L"Color", 3, x, y, z);
		pDocRas6211 = result.pdispVal;
	}

	IDispatch* pDocRas40111;
	{
		VARIANT result;
		VariantInit(&result);
		VARIANT x;
		x.vt = VT_I4;
		x.lVal = 1;
		VARIANT y;
		y.vt = VT_I4;
		y.lVal = 1;
		VARIANT z;
		z.vt = VT_BOOL;
		z.lVal = true;
		AutoWrap(DISPATCH_METHOD, &result, pDocRas21, L"MoveRight", 2, x, y);
		pDocRas40111 = result.pdispVal;
	}

	IDispatch* pDocRas211;
	{
		VARIANT result;
		VariantInit(&result);
		AutoWrap(DISPATCH_PROPERTYGET, &result, pWordApp, L"Selection",
			0);
		pDocRas211 = result.pdispVal;
	}
	IDispatch* pDocRas41111;
	{
		VARIANT result;
		VariantInit(&result);
		VARIANT x;
		x.vt = VT_I4;
		x.lVal = 1;
		VARIANT y;
		y.vt = VT_I4;
		y.lVal = 1;
		VARIANT z;
		z.vt = VT_BOOL;
		z.lVal = true;
		AutoWrap(DISPATCH_METHOD, &result, pDocRas211, L"MoveRight", 3, x, y, z);
		pDocRas41111 = result.pdispVal;
	}
	/////
	IDispatch* pDocRas51111;
	{
		VARIANT result;
		VariantInit(&result);
		AutoWrap(DISPATCH_PROPERTYGET, &result, pDocRas211, L"Font",
			0);

		pDocRas51111 = result.pdispVal;
	}
	IDispatch* pDocRas62111;
	{
		VARIANT result;
		VariantInit(&result);
		VARIANT x, y, z;
		x.vt = VT_I4;
		x.lVal = 32768;
		y.vt = VT_I4;
		y.lVal = 255;
		z.vt = VT_I4;
		z.lVal = 0;
		AutoWrap(DISPATCH_PROPERTYPUT, &result, pDocRas51111, L"Color", 3, x, y, z);
		pDocRas62111 = result.pdispVal;
	}

	IDispatch* pDocRas401111;
	{
		VARIANT result;
		VariantInit(&result);
		VARIANT x;
		x.vt = VT_I4;
		x.lVal = 1;
		VARIANT y;
		y.vt = VT_I4;
		y.lVal = 1;
		VARIANT z;
		z.vt = VT_BOOL;
		z.lVal = true;
		AutoWrap(DISPATCH_METHOD, &result, pDocRas211, L"MoveRight", 2, x, y);
		pDocRas401111 = result.pdispVal;
	}

	IDispatch* pDocRas2111;
	{
		VARIANT result;
		VariantInit(&result);
		AutoWrap(DISPATCH_PROPERTYGET, &result, pWordApp, L"Selection",
			0);
		pDocRas2111 = result.pdispVal;
	}
	IDispatch* pDocRas411111;
	{
		VARIANT result;
		VariantInit(&result);
		VARIANT x;
		x.vt = VT_I4;
		x.lVal = 1;
		VARIANT y;
		y.vt = VT_I4;
		y.lVal = 1;
		VARIANT z;
		z.vt = VT_BOOL;
		z.lVal = true;
		AutoWrap(DISPATCH_METHOD, &result, pDocRas2111, L"MoveRight", 3, x, y, z);
		pDocRas411111 = result.pdispVal;
	}
	/////
	IDispatch* pDocRas511111;
	{
		VARIANT result;
		VariantInit(&result);
		AutoWrap(DISPATCH_PROPERTYGET, &result, pDocRas2111, L"Font",
			0);

		pDocRas511111 = result.pdispVal;
	}
	IDispatch* pDocRas621111;
	{
		VARIANT result;
		VariantInit(&result);
		VARIANT x, y, z;
		x.vt = VT_I4;
		x.lVal = 16763904;
		y.vt = VT_I4;
		y.lVal = 255;
		z.vt = VT_I4;
		z.lVal = 0;
		AutoWrap(DISPATCH_PROPERTYPUT, &result, pDocRas511111, L"Color", 3, x, y, z);
		pDocRas621111 = result.pdispVal;
	}


	IDispatch* pDocRas4011111;
	{
		VARIANT result;
		VariantInit(&result);
		VARIANT x;
		x.vt = VT_I4;
		x.lVal = 1;
		VARIANT y;
		y.vt = VT_I4;
		y.lVal = 1;
		VARIANT z;
		z.vt = VT_BOOL;
		z.lVal = true;
		AutoWrap(DISPATCH_METHOD, &result, pDocRas2111, L"MoveRight", 2, x, y);
		pDocRas4011111 = result.pdispVal;
	}

	IDispatch* pDocRas21111;
	{
		VARIANT result;
		VariantInit(&result);
		AutoWrap(DISPATCH_PROPERTYGET, &result, pWordApp, L"Selection",
			0);
		pDocRas21111 = result.pdispVal;
	}
	IDispatch* pDocRas4111111;
	{
		VARIANT result;
		VariantInit(&result);
		VARIANT x;
		x.vt = VT_I4;
		x.lVal = 1;
		VARIANT y;
		y.vt = VT_I4;
		y.lVal = 1;
		VARIANT z;
		z.vt = VT_BOOL;
		z.lVal = true;
		AutoWrap(DISPATCH_METHOD, &result, pDocRas21111, L"MoveRight", 3, x, y, z);
		pDocRas4111111 = result.pdispVal;
	}
	/////
	IDispatch* pDocRas5111111;
	{
		VARIANT result;
		VariantInit(&result);
		AutoWrap(DISPATCH_PROPERTYGET, &result, pDocRas21111, L"Font",
			0);

		pDocRas5111111 = result.pdispVal;
	}
	IDispatch* pDocRas6211111;
	{
		VARIANT result;
		VariantInit(&result);
		VARIANT x, y, z;
		x.vt = VT_I4;
		x.lVal = 16711680;
		y.vt = VT_I4;
		y.lVal = 255;
		z.vt = VT_I4;
		z.lVal = 0;
		AutoWrap(DISPATCH_PROPERTYPUT, &result, pDocRas5111111, L"Color", 3, x, y, z);
		pDocRas6211111 = result.pdispVal;
	}


	IDispatch* pDocRas40111111;
	{
		VARIANT result;
		VariantInit(&result);
		VARIANT x;
		x.vt = VT_I4;
		x.lVal = 1;
		VARIANT y;
		y.vt = VT_I4;
		y.lVal = 1;
		VARIANT z;
		z.vt = VT_BOOL;
		z.lVal = true;
		AutoWrap(DISPATCH_METHOD, &result, pDocRas21111, L"MoveRight", 2, x, y);
		pDocRas40111111 = result.pdispVal;
	}

	IDispatch* pDocRas211111;
	{
		VARIANT result;
		VariantInit(&result);
		AutoWrap(DISPATCH_PROPERTYGET, &result, pWordApp, L"Selection",
			0);
		pDocRas211111 = result.pdispVal;
	}
	IDispatch* pDocRas41111111;
	{
		VARIANT result;
		VariantInit(&result);
		VARIANT x;
		x.vt = VT_I4;
		x.lVal = 1;
		VARIANT y;
		y.vt = VT_I4;
		y.lVal = 1;
		VARIANT z;
		z.vt = VT_BOOL;
		z.lVal = true;
		AutoWrap(DISPATCH_METHOD, &result, pDocRas211111, L"MoveRight", 3, x, y, z);
		pDocRas41111111 = result.pdispVal;
	}
	/////
	IDispatch* pDocRas51111111;
	{
		VARIANT result;
		VariantInit(&result);
		AutoWrap(DISPATCH_PROPERTYGET, &result, pDocRas211111, L"Font",
			0);

		pDocRas51111111 = result.pdispVal;
	}
	IDispatch* pDocRas62111111;
	{
		VARIANT result;
		VariantInit(&result);
		VARIANT x, y, z;
		x.vt = VT_I4;
		x.lVal = 8388736;
		y.vt = VT_I4;
		y.lVal = 255;
		z.vt = VT_I4;
		z.lVal = 0;
		AutoWrap(DISPATCH_PROPERTYPUT, &result, pDocRas51111111, L"Color", 3, x, y, z);
		pDocRas62111111 = result.pdispVal;
	}








	//-----------------------------------------------------------------------------------------------------------------------------------------------


	//IDispatch *pDoc2;
	//{
	//	VARIANT result;
	//	VariantInit(&result);
	//	AutoWrap(DISPATCH_PROPERTYGET, &result, pDoc1, L"Content",
	//		0);
	//	pDoc2 = result.pdispVal;
	//}
	//// Call Documents.Open()
	//IDispatch *pDoc3;
	//{
	//	VARIANT result;
	//	VariantInit(&result);
	//	VARIANT x;
	//	x.vt = VT_BSTR;
	//	x.bstrVal = ::SysAllocString(L"fd");
	//	AutoWrap(DISPATCH_METHOD, &result, pDoc2, L"InsertAfter", 1, x);
	//	pDoc3 = result.pdispVal;
	//	/*
	//				pDoc0->Release();
	//				pDoc1->Release();
	//				pDoc2->Release();
	//				pDoc3->Release();
	//				pDocs->Release();
	//				pWordApp->Release();*/
	//				//}
	//				//FindClose(hFind);
	//}

	/*
	IDispatch *pDoc4;
	{
		VARIANT result;
		VariantInit(&result);
		AutoWrap(DISPATCH_PROPERTYGET, &result, pDoc1, L"Paragraphs",
			0);
		pDoc4 = result.pdispVal;
	}
	/////
	IDispatch *pDoc41;
	{
		VARIANT result;
		VariantInit(&result);
		VARIANT x;
		x.vt = VT_I4;
		x.lVal = 1;
		AutoWrap(DISPATCH_METHOD, &result, pDoc4, L"Item", 1, x);
		pDoc41 = result.pdispVal;
	}
	/////
	IDispatch *pDoc51;
	{
		VARIANT result;
		VariantInit(&result);
		AutoWrap(DISPATCH_PROPERTYGET, &result, pDoc41, L"Range",
			0);

		pDoc51 = result.pdispVal;
	}

	IDispatch *pDoc5;
	{
		VARIANT result;
		VariantInit(&result);
		AutoWrap(DISPATCH_PROPERTYGET, &result, pDoc51, L"Font",
			0);

		pDoc5 = result.pdispVal;
	}
	IDispatch *pDoc6;
	{
		VARIANT result;
		VariantInit(&result);
		VARIANT x, y, z;
		x.vt = VT_BSTR;
		x.bstrVal = ::SysAllocString(L"Times New Roman");
		AutoWrap(DISPATCH_PROPERTYPUT, &result, pDoc5, L"Name", 1, x);
		pDoc6 = result.pdispVal;
	}
	IDispatch *pDoc62;
	{
		VARIANT result;
		VariantInit(&result);
		VARIANT x, y, z;
		x.vt = VT_I4;
		x.lVal = 255;
		AutoWrap(DISPATCH_PROPERTYPUT, &result, pDoc5, L"Color", 1, x);
		pDoc62 = result.pdispVal;
	}
	IDispatch *pDoc63;
	{
		VARIANT result;
		VariantInit(&result);
		VARIANT x, y, z;
		x.vt = VT_BOOL;
		x.boolVal = true;
		AutoWrap(DISPATCH_PROPERTYPUT, &result, pDoc5, L"Italic", 1, x);
		pDoc63 = result.pdispVal;
	}
	IDispatch *pDoc64;
	{
		VARIANT result;
		VariantInit(&result);
		VARIANT x, y, z;
		x.vt = VT_BOOL;
		x.boolVal = true;
		AutoWrap(DISPATCH_PROPERTYPUT, &result, pDoc5, L"Bold", 1, x);
		pDoc64 = result.pdispVal;
	}
	IDispatch *pDoc111;
	{
		VARIANT result;
		VariantInit(&result);
		AutoWrap(DISPATCH_PROPERTYGET, &result, pDoc1, L"Background",
			0);
		pDoc111 = result.pdispVal;
	}
	IDispatch *pDoc112;
	{
		VARIANT result;
		VariantInit(&result);
		AutoWrap(DISPATCH_PROPERTYGET, &result, pDoc111, L"Fill",
			0);
		pDoc112 = result.pdispVal;
	}
	IDispatch *pDoc113;
	{
		VARIANT result;
		VariantInit(&result);
		AutoWrap(DISPATCH_PROPERTYGET, &result, pDoc112, L"ForeColor",
			0);
		pDoc113 = result.pdispVal;
	}
	/*IDispatch *pDoc1234;
	{
		VARIANT result;
		VariantInit(&result);
		AutoWrap(DISPATCH_PROPERTYGET, &result, pWordApp, L"Selection",
			0);
		pDoc1234 = result.pdispVal;
	}*/
	/*IDispatch *pDoc114;
	{
		VARIANT result;
		VariantInit(&result);
		VARIANT x, y, z;
		x.vt = VT_I4;
		x.lVal = 4;
		y.vt = VT_I4;
		y.lVal = 122;
		z.vt = VT_I4;
		z.lVal = 122;
		AutoWrap(DISPATCH_METHOD, &result, pDoc1234, L"MoveRight", 0, x);
		pDoc114 = result.pdispVal;
	}*/

	// Uninitialize COM for this thread...
	CoUninitialize();

	return 0;
}
