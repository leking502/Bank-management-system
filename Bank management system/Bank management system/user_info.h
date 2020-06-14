#pragma once
#include "stdafx.h"
template<typename user_info>
class Array;
using namespace std;
class Account;
class user_info

{
public:
	static user_info* createaccount( //建立账户函数
		string id, //用户id
		string name, //用户姓名
		long long pnum, //电话号码
		string password,
		bool type,
		Account* account,
		Array<user_info*> accounts
	);
	Account* getaccount(); //获取账户类的函数
	long long getpnum();  //获取电话号码
	string getpassword();//获取密码
	string getname();//获取姓名
	void changepnum(long long pnum);  //更改电话号码
	void changepassword(string password);//更改密码
	void changename(string name);//更改姓名
	~user_info();
private:
	string password;//密码
	string name;//姓名
	Account* account;//账户类
	long long pnum; //手机号
	user_info(string id, string name, long long pnum, string password, bool type, Account* account); //构造函数
};

