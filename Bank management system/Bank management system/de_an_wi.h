#pragma once
template<typename user_info>
class Array;
using namespace std;
class user_info;
class Date;
class de_an_wi
{
public:
	static void  deposit(int userh, const Date& date, Array<user_info*> accounts);
	static void  withdrawal(int userh, const Date& date, Array<user_info*> accounts);
};
