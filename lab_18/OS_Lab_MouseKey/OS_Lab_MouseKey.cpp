// OS_Lab_MouseKey.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

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

	SetConsoleMode(hIn, ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);

	KeyWhere.X = 0;
	KeyWhere.Y = 0;
	MouseWhere.X = 15;
	MouseWhere.Y = 1;
	EndWhere.X = 0;
	EndWhere.Y = 3;

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
			++KeyEvents;
			SetConsoleCursorPosition(hOut, KeyWhere);
			cout << KeyEvents << flush;
			if (InRec.Event.KeyEvent.uChar.AsciiChar == 'x')
			{
				SetConsoleCursorPosition(hOut,
					EndWhere);
				cout << "Exiting..." << endl;
				Continue = FALSE;
			}
			switch (InRec.Event.KeyEvent.wVirtualKeyCode) {
			case VK_UP:
				cout << endl << "Up   " << endl;//key up
				break;
			case VK_DOWN:
				cout << endl << "Down " << endl;   // key down
				break;
			case VK_LEFT:
				cout << endl << "Left " << endl;  // key left
				break;
			case VK_RIGHT:
				cout << endl << "Right" << endl;  // key right
				break;
			default:
				cout << endl << "Mouse Events : " << endl;
				//  cout << endl << "null" << endl;  // not arrow
				break;
			}
			break;
		}
		case MOUSE_EVENT:
		{
			TCHAR* title = NULL;
			DWORD z = GetConsoleTitle(title, sizeof(TCHAR));
			cout << endl << InRec.Event.MouseEvent.dwMousePosition.X << endl;
			++MouseEvents;
			SetConsoleCursorPosition(hOut,
				MouseWhere);
			cout << MouseEvents << flush;
			break;
		}
		}
	}
	getchar();

	return 0;
}
