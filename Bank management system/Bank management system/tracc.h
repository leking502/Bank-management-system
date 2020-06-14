#pragma once
#include "stdafx.h"
template<typename user_info>
class Array;
using namespace std;
class user_info;
class Date;
class tracc
{
public:
	bool transferacc(int userh, const Date& date, Array<user_info*> accounts);
};

