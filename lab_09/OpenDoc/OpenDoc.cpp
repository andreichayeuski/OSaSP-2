// OpenDoc.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "dll.h"
#include<iostream>
#include<conio.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	TCHAR filesearch[50];
	cout << "Enter file name: " << endl;
	_getws_s(filesearch);
	OpenDoc(filesearch);
	_getch();
	return 0;
}
