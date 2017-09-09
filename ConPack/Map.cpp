#include "Map.h"


void Map::PrintCandy()
{
	CONSOLE.SetTextColor(LIGHTSKYBLUE);
	for (int i = 1; i < WINSIZEY - 1; ++i)
		for (auto iter : candyPos[i])
			CONPOS(iter, i) << "¡¤";
	CONSOLE.SetTextColor(WHITE);
}

Map::Map(int stage)
{
	char Path[1024];
	wsprintfA(Path, "/Data/Stage%d.dat", stage);
	for (int i = 1; i < WINSIZEY - 1; ++i)
	{		
		string temp = ReadString("TriggerPoint", IntToString(i), Path);
		triggerPos[i] = SplitUseToken(temp, ",");
		int t_cnt = 0;
		for (int j = 2; j < WINSIZEX - 2; j+=2)
		{
			if (j == triggerPos[i].at(t_cnt)) 
			{
				if(t_cnt < triggerPos[i].size()-1)
					++t_cnt;
				continue;
			}
			else
			{
				candyPos[i].push_back(j);
			}
		}
	}
}

Map::~Map()
{
	for (int i = 0; i < WINSIZEY; ++i)
		triggerPos[i].clear();
}
