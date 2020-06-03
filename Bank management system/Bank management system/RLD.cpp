#include "headf.h"
#include "stdafx.h"
using namespace std;
//注册账户
int RLD::reg(Date date,int rate, Array<user_info*> accounts)
{
	
	iofreg userio = iofreg(accounts);
	string id = userio.id;
	string name = userio.name;
	BOOL type = userio.type;
	int pnum = userio.pnum;
	string password = userio.password;
	if (type)
	{
		CreditAccount* account1 = new CreditAccount(
			date,
			id,
			10000,
			rate,
			100
		);
		int x = (int)user_info::createaccount(
			id,
			name,
			pnum,
			password,
			type,
			account1,
			accounts
		);
		return x;
	}
	else
	{
		SavingsAccount* account0 = new SavingsAccount(
			date,
			id,
			rate
		);
		int x = (int)user_info::createaccount(
			id,
			name,
			pnum,
			password,
			type,
			account0,
			accounts
		);
		return x;
	};
};

//登录账户
int RLD::signin(Array<user_info*> accounts)
{
	iofsignin userio = iofsignin(accounts);;
	return userio.userh;
};

//注销账户
bool RLD::delacc(int userh, Array<user_info*> accounts) 
{
	while (1) 
	{
		char b;
		system("cls");
		cout << "你确定要注销账户（y/n）" << endl;
		cin >> b;
		if (b == 'y') 
		{
			string pw;
			system("cls");
			cout << "输入密码来确认是你本人操作" << endl;
			cin >> pw;
			while (1) {
				if (check::checkpassword(userh, pw, accounts))
				{
					system("cls");
					delete accounts[userh];
					cout << "已删除" << endl;
					system("pause");
					system("cls");
					return 1;
				}
				system("cls");
				cout << "密码不正确" << endl;
				system("pause");
				break;
			};

		};
		return 0;
	};
};
