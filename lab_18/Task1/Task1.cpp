// Task1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include "pch.h"
#include <windows.h>
#include <iostream>
  /* #define KEY_UP 72
   #define KEY_DOWN 80
   #define KEY_LEFT 75
   #define KEY_RIGHT 77
*/
#define ENABLE_QUICK_EDIT_MODE  0x0040
using namespace std;

int main()
{

	HANDLE hIn;
	HANDLE hOut;
	COORD KeyWhere;
	COORD MouseWhere;
	COORD EndWhere;
	bool Continue = TRUE;
	int KeyEvents = 0;
	int MouseEvents = 0;
	INPUT_RECORD InRec;
	DWORD NumRead;

	hIn = GetStdHandle(STD_INPUT_HANDLE);
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "Key Events   : " << endl;
	cout << "Mouse Events : " << flush;

	KeyWhere.X = 0;
	KeyWhere.Y = 0;
	MouseWhere.X = 15;
	MouseWhere.Y = 1;
	EndWhere.X = 0;
	EndWhere.Y = 3;
	int position = 0;

	SetConsoleMode(hIn, ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);

	while (Continue)
	{
		ReadConsoleInput(hIn,
			&InRec,
			1,
			&NumRead);

		switch (InRec.EventType)
		{
		case KEY_EVENT:
		{
			switch (InRec.Event.KeyEvent.wVirtualKeyCode) {
			case VK_UP:
				KeyWhere.Y -= 1;
				SetConsoleCursorPosition(hOut, KeyWhere);
				break;
			case VK_DOWN:
				KeyWhere.Y += 1;
				SetConsoleCursorPosition(hOut, KeyWhere);
				break;
			case VK_LEFT:
				KeyWhere.X -= 1;
				SetConsoleCursorPosition(hOut, KeyWhere);
				break;
			case VK_RIGHT:
				KeyWhere.X += 1;
				SetConsoleCursorPosition(hOut, KeyWhere);
				break;
			case VK_END:
				KeyWhere.X = position;
				SetConsoleCursorPosition(hOut, KeyWhere);
				break;
			default:
			{
				cout << InRec.Event.KeyEvent.uChar.AsciiChar << flush;
				KeyWhere.X += 1;
				position = KeyWhere.X;
				break;
			}
			}
			break;
		}
		case MOUSE_EVENT:
			TCHAR* title = NULL;
			DWORD z = GetConsoleTitle(title, sizeof(TCHAR));
			cout << endl << " X:" << InRec.Event.MouseEvent.dwMousePosition.X << " Y:" << InRec.Event.MouseEvent.dwMousePosition.Y << endl;
			SetConsoleCursorPosition(hOut,
				MouseWhere);
			break;
		}
	}
	getchar();

	return 0;
}
