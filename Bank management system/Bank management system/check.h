#pragma once
#include "stdafx.h"
class user_info;
class check
{
public:
	//�������
	static bool checkpassword(int userh, string password, Array<user_info*>& accounts);
	//���id
	static int checkid(string id, Array<user_info*>& accounts);
	//������
	static int checkamount(int amount, int userh, Array<user_info*>& accounts);
};
