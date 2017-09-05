#pragma once

#include <Windows.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

#define WINSIZEX 80
#define WINSIZEY 30

enum TextColor
{
	BLACK,
	BLUE,
	GREEN,
	SKYBLUE,
	RED,
	PINK,
	BROWN,
	GRAY,
	DARKGRAY,
	LIGHTBLUE,
	LIGHTGREEN,
	LIGHTSKYBLUE,
	LIGHTRED,
	LIGHTPINK,
	YELLOW,
	WHITE
};

typedef struct tagPosition
{
	double X;
	double Y;
	tagPosition(double _x = 0, double _y = 0)
		: X(_x), Y(_y)
	{}
} POSITION;

typedef struct tagSelectMenuPosition
{
	vector<POSITION> Pos;

	void SetMax(int max)
	{
		Pos.resize(max);
	}
	void SetPosition(int index, POSITION pos)
	{
		Pos[index] = pos;
	}
	POSITION& GetPosition(int index)
	{
		return Pos[index];
	}
} SMP, *PSMP;

#include "Console.h"

/* CONSLE HANDLER */
#define CONSOLE Console::Inst
#define CONPOS(x, y) Console::Inst.SetPos(x, y)
#define CONFLIP Console::Inst.Flipping()

/* Game Construction Function */
void BackGround();
void MenuTitle();
void PrintMarker(POSITION pos);
void SettingMenuPos(PSMP smp, INT max, INT xpos, INT ypos);
void PrintMenu(PSMP smp, INT cnt, INT Select, const string data[]);
