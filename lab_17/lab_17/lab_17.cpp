// lab_17.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "lab_17.h"

#define MAX_LOADSTRING 100
int n = 10;
int t = 9;
int m = 10;
int el = 0;
HBITMAP hbitmap;

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: Разместите код здесь.

	// Инициализация глобальных строк
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_LAB17, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Выполнить инициализацию приложения:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB17));

	MSG msg;

	// Цикл основного сообщения:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB17));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_LAB17);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

	HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// Разобрать выбор в меню:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;
	case WM_CREATE:
		hbitmap = (HBITMAP)LoadImage(hInst, L"soccer_ball.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		SetTimer(hWnd,
			IDT_TIMER1,
			500,
			(TIMERPROC)NULL);
		SetTimer(hWnd,
			IDT_TIMER2,
			100,
			(TIMERPROC)NULL);
		SetTimer(hWnd,
			IDT_TIMER4,
			1000,
			(TIMERPROC)NULL);
		SetTimer(hWnd,
			IDT_TIMER4,
			1000,
			(TIMERPROC)NULL);
		break;

	case WM_TIMER:
		if (wParam == IDT_TIMER4)
		{
			if (t == 2)
			{
				KillTimer(hWnd, IDT_TIMER4);
			}
			t--;

		}
		if (wParam == IDT_TIMER2)
		{
			if (n > 1000)
			{
				n = 10;
			}
			n += 5;

			InvalidateRect(hWnd, NULL, TRUE);
		}
		if (wParam == IDT_TIMER4)
		{
			if (el % 2 == 0)
			{
				hbitmap = (HBITMAP)LoadImage(hInst, L"paint.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			}
			else
			{
				hbitmap = (HBITMAP)LoadImage(hInst, L"soccer_ball.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			}
			el++;
			InvalidateRect(hWnd, NULL, TRUE);
		}
		break;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_SHIFT:
		{
			KillTimer(hWnd, IDT_TIMER2);

			KillTimer(hWnd, IDT_TIMER4);
		}
		}
		break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc;
		BITMAP bitmap;
		HDC hdcMen;
		HGDIOBJ oldbitmap;
		hdc = BeginPaint(hWnd, &ps);
		COLORREF C1 = RGB(10, 14, 200);
		SetTextColor(hdc, C1);
		TextOut(hdc, n, 10, TEXT("OS is the Best (Yulia Olegovna, Vy tozhe)"), 42);
		char text[10];
		_itoa_s(t, text, 10);
		TextOutA(hdc, 30, 30, text, 1);

		hdcMen = CreateCompatibleDC(hdc);
		oldbitmap = SelectObject(hdcMen, hbitmap);
		GetObject(hbitmap, sizeof(bitmap), &bitmap);
		BitBlt(hdc, 0, 100, bitmap.bmWidth, bitmap.bmHeight, hdcMen, 0, 0, SRCCOPY);
		SelectObject(hdcMen, oldbitmap);
		DeleteDC(hdcMen);
		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
