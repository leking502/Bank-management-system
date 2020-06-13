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
	bool transferacc(user_info user1, user_info user2, const Date& date, Array<user_info*> accounts);
};

