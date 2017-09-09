#pragma once

class Console
{
public:
	static Console Inst;
	COORD Size;
private:
	HANDLE ScreenBuffer[2];
	UINT ScreenNumber;
	COORD Pos;
	BYTE BackColor;
	BYTE TextColor;
	BYTE DefaultBackColor;
	BYTE DefaultTextColor;
public:
	Console& SetDefaultTextColor(BYTE color)
	{
		DefaultTextColor = color;
		return *this;
	}
	Console& SetDefaultBackColor(BYTE color)
	{
		DefaultBackColor = color;
		return *this;
	}
	Console& SetBackColor(BYTE color)
	{
		BackColor = color;
		return *this;
	}
	Console& SetTextColor(BYTE color)
	{
		TextColor = color;
		return *this;
	}
	Console& Clear()
	{
		static COORD DefaultPos = { 0, 0 };
		DWORD Dump;
		FillConsoleOutputAttribute(
			ScreenBuffer[ScreenNumber],
			DefaultBackColor << 4 | DefaultTextColor,
			Size.X * Size.Y, DefaultPos, &Dump);
		FillConsoleOutputCharacterA(
			ScreenBuffer[ScreenNumber],
			' ', Size.X * Size.Y, DefaultPos, &Dump);
		SetPos(0, 0);
		return *this;
	}
	Console& SetPos(POSITION Pos)
	{
		return SetPos(Pos.X, Pos.Y);
	}
	Console& SetPos(UINT x, UINT y)
	{
		Pos.X = x;
		Pos.Y = y + (Pos.X / Size.X);
		if (Pos.Y >= Size.Y)
			Pos.Y -= Size.Y;
		Pos.X -= (Pos.X / Size.X) * Size.X;
		return *this;
	}
	void Flipping()
	{
		Sleep(50);
		SetConsoleActiveScreenBuffer(ScreenBuffer[ScreenNumber]);
		ScreenNumber = ScreenNumber ^ 0x01;
	}
	Console& operator<<(double Number)
	{
		static char Buff[32];
		_gcvt(Number, 5, Buff);	
		return operator<<(Buff);
	}
	Console& operator<<(int Number)
	{
		static char Buff[32];
		itoa(Number, Buff, 10);
		return operator<<(Buff);
	}
	Console& operator<<(char ch)
	{
		static char Buff[2];
		Buff[0] = ch;
		return operator<<(Buff);
	}
	Console& operator<<(const char* str)
	{
		DWORD Dump;
		UINT len = strlen(str);

		FillConsoleOutputAttribute(
			ScreenBuffer[ScreenNumber],
			BackColor << 4 | TextColor, len, Pos, &Dump
		);

		WriteConsoleOutputCharacterA(
			ScreenBuffer[ScreenNumber],
			str, len, Pos, &Dump
		);
		SetPos(Pos.X + len, Pos.Y);
		return *this;
	}
private:
	Console(const char * Title = "CON - PAC", int row = WINSIZEX, int col = WINSIZEY);
	Console(const Console&) = delete;
public:
	~Console();
};

