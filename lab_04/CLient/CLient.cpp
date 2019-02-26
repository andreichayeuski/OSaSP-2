// CLient.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include<objbase.h>
#include"Create.h"
#include"IFace.h"
#include"GUID.h"
using namespace std;

void trace(const char* msg)
{
	cout << "Клиент 1:\t" << msg << endl;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	HRESULT hr;
	char name[40]="";
	//cout << "Введите имя файла компонента [Cmpnt?.dll]: ";
	//cin >> name;
	//cout << endl;
	double res = CallSum(name);
	cout << " -------------------------------------------------------- " << endl;
	cout << "Результат CallSum: " << res<<endl;
	cout << " -------------------------------------------------------- " << endl;
	trace("Получить указатель на IUnknown");
	IUnknown* pIUnknown = CallCreateInstance(name);
	if (pIUnknown == NULL)
	{
		trace("Вызов CallCreateInstance неудачен");
		return 1;
	}
	trace("Получить интерфейс IX");

	IX* pIX;
	hr = pIUnknown->QueryInterface(IID_IX, (void**)&pIX);
	if (SUCCEEDED(hr))
	{
		trace("IX получен успешно");
		pIX->Fx();
		pIX->Release();
	}
	else
	{
		trace("Не могу получить интерфейс IX");
	}
	trace("Освободить интерфейс IUnknown");
	pIUnknown->Release();
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
