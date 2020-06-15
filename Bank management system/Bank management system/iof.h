#pragma once
#include "stdafx.h"
using namespace std;
//输入输出相关函数类
class iof
{
public:
	string id;
	string password;
	iof() {};
};
//注册输入输出函数子类
class iofreg :public iof
{
public:
	string name;
	long long  pnum;
	int type;
	iofreg(Array<user_info*>& accounts);
};
//登录输入输出函数子类
class iofsignin :public iof
{
public:
	int userh;
	iofsignin(Array<user_info*>& accounts);
};
