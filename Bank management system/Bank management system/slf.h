#pragma once
template<typename user_info>
class Array;
using namespace std;
class user_info;
class Date;
class slf
{
public:
	static int savef(Date& date,Array<user_info*>& accounts);
	static int loadf(Date& date, Array<user_info*>& accounts);
};

