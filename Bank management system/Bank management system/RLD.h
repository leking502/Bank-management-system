#pragma once
#include "stdafx.h"
class Date;
class user_info;
using namespace std;
class RLD
{
public:
	//×¢²á
	static user_info* reg(Date date, int rate, Array<user_info*> accounts);
	//µÇÂ¼
	static int signin(Array<user_info*> accounts);
	//×¢Ïú
	static bool delacc(int userh, Array<user_info*> accounts);
};

