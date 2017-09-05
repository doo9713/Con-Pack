#include "Defines.h"
#include "Game.h"

#define START 0
#define LOAD  1
#define EXIT  2

void main()
{
	/* Main Menu Info */
	INT indexCnt = 3;
	POSITION startPos(32, 15);
	string indexData[3] = { "1. 새로하기", "2. 이어하기" , "3. 종료" };

	SMP smp;
	INT Select = 0;

	SettingMenuPos(&smp, indexCnt, startPos.X, startPos.Y);

	while (1)
	{
		CONSOLE.Clear();

		BackGround();
		MenuTitle();
		PrintMenu(&smp, indexCnt, Select, indexData);

		if (GetAsyncKeyState(VK_DOWN) & 0x0001)
		{
			Select += 1;
			if (Select >= smp.Pos.size())
				Select = smp.Pos.size() - 1;
		}
		if (GetAsyncKeyState(VK_UP) & 0x0001)
		{
			Select -= 1;
			if (Select < 0)
				Select = 0;
		}
		if (GetAsyncKeyState(VK_RETURN) & 0x0001)
		{
			Game start;
			switch (Select)
			{
			case START:			
				start.mainActive();
				break;
			case LOAD:
				break;
			case EXIT:
				return;
			}
		}

		CONFLIP;
	}
}

