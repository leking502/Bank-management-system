#include "headf.h"
#include "stdafx.h"
using namespace std;
//��������Ƿ���ȷ
bool check::checkpassword(int userh, string password, Array<user_info*> accounts)
{
	if (accounts[userh]->getpassword() == password) 
	{
		return 1;
	};
	return 0;
};

//����Ƿ�����˻���
int check::checkid(string id, Array<user_info*> accounts)
{
	for (int i = 0;i < accounts.getsize();i++) {
		if (accounts[i]->getaccount()->getId() == id)
		{
			return 1+i;
		};
	}
	return 0;
};
