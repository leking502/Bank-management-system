#include "headf.h"
#include "stdafx.h"
using namespace std;
//注册账户
user_info* RLD::reg(Date& date, int rate, Array<user_info*>& accounts)
{

	iofreg userio = iofreg(accounts);
	if (userio.id == "0")
	{
		return 0;
	};
	string id = userio.id;
	string name = userio.name;
	int type = userio.type;
	long long pnum = userio.pnum;
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
		user_info* x = user_info::createaccount(
			id,
			name,
			pnum,
			password,
			type - 1,
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
		user_info* x = user_info::createaccount(
			id,
			name,
			pnum,
			password,
			type - 1,
			account0,
			accounts
		);
		return x;
	};
};

//登录账户
int RLD::signin(Array<user_info*>& accounts)
{
	iofsignin userio = iofsignin(accounts);;
	return userio.userh;
};

//注销账户
bool RLD::delacc(int userh, Array<user_info*>& accounts)
{
	while (1)
	{
		int b;
		system("cls");
		cout << "o=================================================o" << endl;
		cout << "|                                                 |" << endl;
		cout << "|              你确定要注销账户                   |" << endl;
		cout << "|                                                 |" << endl;
		cout << "|        (1)确定              (2)返回             |" << endl;
		cout << "|                                                 |" << endl;
		cout << "|                                                 |" << endl;
		cout << "o=================================================o" << endl;
		cin.clear();
		cin >> b;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore();
			system("cls");
			cout << "o=================================================o" << endl;
			cout << "|                                                 |" << endl;
			cout << "|                                                 |" << endl;
			cout << "|                 无效的输入                      |" << endl;
			cout << "|                                                 |" << endl;
			cout << "|                                                 |" << endl;
			cout << "|                                                 |" << endl;
			cout << "o=================================================o" << endl;
			system("pause");
			system("cls");
			cout << "o=================================================o" << endl;
			cout << "|                                                 |" << endl;
			cout << "|              你确定要注销账户                   |" << endl;
			cout << "|                                                 |" << endl;
			cout << "|        (1)确定              (2)返回             |" << endl;
			cout << "|                                                 |" << endl;
			cout << "|                                                 |" << endl;
			cout << "o=================================================o" << endl;
			cin >> b;
		}
		if (b == 0 || b >=2 )
		{
			return 0;
		}
		if (b == 1)
		{
			string pw;
			system("cls");
			cout << "o=================================================o" << endl;
			cout << "|                                                 |" << endl;
			cout << "|             输入密码来确认是你本人操作          |" << endl;
			cout << "|                                                 |" << endl;
			cout << "|                                                 |" << endl;
			cout << "|                                                 |" << endl;
			cout << "|                                                 |" << endl;;
			cout << "o=================================================o" << endl;
			cin >> pw;
			if (pw == "0")
			{
				continue;
			};
			while (1) {
				if (check::checkpassword(userh, pw, accounts))
				{
					system("cls");
					delete accounts[userh];
					cout << "o=================================================o" << endl;
					cout << "|                                                 |" << endl;
					cout << "|                                                 |" << endl;
					cout << "|                     已删除                      |" << endl;
					cout << "|                                                 |" << endl;
					cout << "|                                                 |" << endl;
					cout << "|                                                 |" << endl;;
					cout << "o=================================================o" << endl;
					system("pause");
					system("cls");
					return 1;
				}
				system("cls");

				cout << "o=================================================o" << endl;
				cout << "|                                                 |" << endl;
				cout << "|                                                 |" << endl;
				cout << "|                  密码不正确                     |" << endl;
				cout << "|                                                 |" << endl;
				cout << "|                                                 |" << endl;
				cout << "|                                                 |" << endl;;
				cout << "o=================================================o" << endl;
				system("pause");
				break;
			};
			continue;
		};
		return 0;
	};
};
