#pragma once
#include "stdafx.h"
class Date;
class user_info;
using namespace std;
class RLD
{
public:
	//ע��
	static user_info* reg(Date date, int rate, Array<user_info*> accounts);
	//��¼
	static int signin(Array<user_info*> accounts);
	//ע��
	static bool delacc(int userh, Array<user_info*> accounts);
};

