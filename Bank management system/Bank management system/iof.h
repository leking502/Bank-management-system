#pragma once
#include "stdafx.h"
using namespace std;
//���������غ�����
class iof
{
public:
	string id;
	string password;
	iof() {};
};
//ע�����������������
class iofreg :public iof
{
public:
	string name;
	long long  pnum;
	int type;
	iofreg(Array<user_info*>& accounts);
};
//��¼���������������
class iofsignin :public iof
{
public:
	int userh;
	iofsignin(Array<user_info*>& accounts);
};
