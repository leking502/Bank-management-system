#pragma once
#include "stdafx.h"
class user_info;
class check
{
public:
	//¼ì²éÃÜÂë
	static bool checkpassword(int userh, string password, Array<user_info*>& accounts);
	//¼ì²éid
	static int checkid(string id, Array<user_info*>& accounts);
	//¼ì²éÓà¶î
	static int checkamount(int amount, int userh, Array<user_info*>& accounts);
};
