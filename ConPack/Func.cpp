#include "Defines.h"


int ReadInt(string Colum, string Key, string Path, int Default)
{
	static char number[16];
	wsprintfA(number, "%d", Default);
	return atoi(ReadString(Colum, Key, Path, number).data());
}

float ReadFloat(string Colum, string Key, string Path, float Default)
{
	static char number[16];
	sprintf(number, "%f", Default);
	return atof(ReadString(Colum, Key, Path, number).data());
}

string ReadString(string Colum, string Key, string Path, string Default)
{
	static char result[1024];
	Path = "./" + Path;
	GetPrivateProfileStringA(
		Colum.data(), Key.data(), Default.data(),
		result, 1023, Path.data());
	return result;
}

string IntToString(int data)
{
	static char number[16];
	_itoa(data, number, 10);
	return number;
}


vector<int> SplitUseToken(string s, string token)
{
	vector<int> v;
	int i = 0;
	int pos = s.find(token);

	while (pos != string::npos) {
		v.push_back(atoi(s.substr(i, pos - i).data()));
		i = ++pos;
		pos = s.find(token, pos);

		if (pos == string::npos)
			v.push_back(atoi(s.substr(i, s.length()).data()));
	}
	return v;
}

int Random(int Min, int Max)
{
	if (Min > Max)
	{
		int Temp = Min;
		Min = Max;
		Max = Temp;
	}
	static random_device device;
	static mt19937_64 engine(device());

	uniform_int_distribution<int> range(Min, Max);
	return range(engine);
}
