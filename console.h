#pragma once


#include<iostream>
#include<iomanip>
#include<conio.h>

#include <windows.h>

using namespace std;
class console {

public:
	void getRowColbyLeftClick(int& rpos, int& cpos)
	{
		HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
		DWORD Events;
		INPUT_RECORD InputRecord;
		SetConsoleMode(hInput, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);

		do
		{
			ReadConsoleInput(hInput, &InputRecord, 1, &Events);

			if (InputRecord.EventType == MOUSE_EVENT &&
				InputRecord.Event.MouseEvent.dwEventFlags == 0 &&
				InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				cpos = InputRecord.Event.MouseEvent.dwMousePosition.X;
				rpos = InputRecord.Event.MouseEvent.dwMousePosition.Y;
				break;
			}
		} while (true);
	}

	void gotoRowCol(int rpos, int cpos)
	{
		COORD scrn;
		HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
		scrn.X = cpos;
		scrn.Y = rpos;
		SetConsoleCursorPosition(hOuput, scrn);
	}

	void color(int k)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		CONSOLE_SCREEN_BUFFER_INFO csbi;
		GetConsoleScreenBufferInfo(hConsole, &csbi);

		// Keep existing background, change only text color
		WORD background = csbi.wAttributes & 0xF0;

		SetConsoleTextAttribute(
			hConsole,
			background | (k & 0x0F)
		);
	}

	void hideConsoleCursor()
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO cursorInfo;
		GetConsoleCursorInfo(hConsole, &cursorInfo);
		cursorInfo.bVisible = false;
		SetConsoleCursorInfo(hConsole, &cursorInfo);
	}

	void printaline(int r1, int c1, int r2, int c2, char sym = -37, float def = 0.01) {

		for (float i = 0; i <= 1; i = i + def) {
			int x = r1 + (r2 - r1) * i;
			int y = c1 + (c2 - c1) * i;
			gotoRowCol(x, y);
			cout << sym;
		}

	}
};

