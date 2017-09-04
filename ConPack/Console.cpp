#include "Defines.h"

Console Console::Inst;

Console::Console(const char * Title, int row, int col)
	: ScreenNumber(0)
{
	Size.X = row;
	Size.Y = col;

	DefaultTextColor = WHITE;
	DefaultBackColor = BLACK;

	TextColor = WHITE;
	BackColor = BLACK;

	ScreenBuffer[0] = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		0, NULL, CONSOLE_TEXTMODE_BUFFER, 0
	);
	ScreenBuffer[1] = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		0, NULL, CONSOLE_TEXTMODE_BUFFER, 0
	);

	SetConsoleTitleA(Title);
	COORD Size = { row, col };
	SMALL_RECT rect = { 0, 0, Size.X - 1, Size.Y - 1 };
	SetConsoleScreenBufferSize(ScreenBuffer[0], Size);
	SetConsoleWindowInfo(ScreenBuffer[0], TRUE, &rect);
	SetConsoleScreenBufferSize(ScreenBuffer[1], Size);
	SetConsoleWindowInfo(ScreenBuffer[1], TRUE, &rect);

	CONSOLE_CURSOR_INFO Cursor;
	Cursor.bVisible = false;
	SetConsoleCursorInfo(ScreenBuffer[0], &Cursor);
	SetConsoleCursorInfo(ScreenBuffer[1], &Cursor);

	Flipping();
}


Console::~Console()
{
	CloseHandle(ScreenBuffer[0]);
	CloseHandle(ScreenBuffer[1]);
}
