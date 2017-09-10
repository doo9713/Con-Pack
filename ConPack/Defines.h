#pragma once

#include <Windows.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <random>
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
	int X;
	int Y;
	tagPosition(int _x = 0, int _y = 0)
		: X(_x), Y(_y)
	{}
	tagPosition& operator=(tagPosition pos)
	{
		X = pos.X;
		Y = pos.Y;
		return *this;
	}
	bool operator==(tagPosition pos)
	{
		if (X == pos.X && Y == pos.Y)
			return true;
		else
			return false;
	}
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

/* ETC Function */
int ReadInt(string Colum, string Key, string Path, int Default = 0);
float ReadFloat(string Colum, string Key, string Path, float Default = 0);
string ReadString(string Colum, string Key, string Path, string Default = "Error");
string IntToString(int data);
vector<int> SplitUseToken(string s, string token);
int Random(int Min, int Max);

/* Unit Defines */
#define CHECKOUTSIDE(x, y) (x < 1 || x > 77 || y < 1 || y > 28) || (x > 31 && x < 47 && y < 3)

/* Player Defines */
#define PLAYER "б▄"
#define ENEMY  "бс"

/* Enemy Defines */
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

/* Game Defines */
#define NEWGAME false
#define LOADGAME true