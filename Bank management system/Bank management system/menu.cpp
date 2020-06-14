#include "headf.h"
#include "stdafx.h"
using namespace std;
//用户主页面
void menu::usermenu(int userh, Date date, Array<user_info*> accounts)
{
	int f;
	while (1) {
		system("cls");
		cout << "o=================================================o" << endl;
		cout << "|                  1.查看账户信息                 |" << endl;
		cout << "|                  2.取款                         |" << endl;
		cout << "|                  3.存款                         |" << endl;
		cout << "|                  4.修改密码                     |" << endl;
		cout << "|                  5.转账                         |" << endl;
		cout << "|                  6.登出                         |" << endl;
		cout << "|                  7.注销账号                     |" << endl;
		cout << "o=================================================o" << endl;
		cin.clear();
		cin >> f;
		switch (f)
		{
		case(1): {
			system("cls");
			long long x = accounts[userh]->getpnum();
			cout << "o=================================================o" << endl;
			cout << "                                                    " << endl;
			cout << "   登录名：" << accounts[userh]->getaccount()->getId() << endl;
			cout << "   用户姓名：" << accounts[userh]->getname() << endl;
			cout << "   手机号码：" << x << endl;
			cout << "   余额：" << accounts[userh]->getaccount()->getBalance() << endl;
			cout << "                                                    " << endl;
			cout << "o=================================================o" << endl;
			system("pause");
			system("cls");
			continue;
		}
		case(2):
		{
			de_an_wi::withdrawal(userh, date, accounts);
			continue;
		}
		case(3):
		{
			de_an_wi::deposit(userh, date, accounts);
			continue;
		}
		case(4):
		{
			string pw, npw;
			while (1) {
				system("cls");
				cout << "o=================================================o" << endl;
				cout << "|                                                 |" << endl;
				cout << "|                  请输入旧密码                   |" << endl;
				cout << "|                                                 |" << endl;
				cout << "|                                                 |" << endl;
				cout << "|                                                 |" << endl;
				cout << "|                                                 |" << endl;
				cout << "o=================================================o" << endl;
				cin.clear();
				cin >> pw;
				if (pw == "0")
				{
					break;
				};
				if (check::checkpassword(userh, pw, accounts))
				{
					while (1) {
						system("cls");
						cout << "o=================================================o" << endl;
						cout << "|                                                 |" << endl;
						cout << "|                  请输入新密码                   |" << endl;
						cout << "|                                                 |" << endl;
						cout << "|                                                 |" << endl;
						cout << "|                                                 |" << endl;
						cout << "|                                                 |" << endl;
						cout << "o=================================================o" << endl;
						cin.clear();
						cin >> npw;
						if (npw == "0")
						{
							break;
						};
						accounts[userh]->changepassword(npw);
						system("cls");
						cout << "o=================================================o" << endl;
						cout << "|                                                 |" << endl;
						cout << "|                  更改成功                       |" << endl;
						cout << "|                                                 |" << endl;
						cout << "|                                                 |" << endl;
						cout << "|                                                 |" << endl;
						cout << "|                                                 |" << endl;
						cout << "o=================================================o" << endl;
						system("pause");
					};
				};
				system("cls");
				cout << "o=================================================o" << endl;
				cout << "|                                                 |" << endl;
				cout << "|                  密码不正确                     |" << endl;
				cout << "|                                                 |" << endl;
				cout << "|                                                 |" << endl;
				cout << "|                                                 |" << endl;
				cout << "|                                                 |" << endl;
				cout << "o=================================================o" << endl;
				system("pause");
				continue;
			};
			continue;
		}
		case(5):
		{
			tracc::transferacc(userh, date, accounts);
			continue;
		}
		case(6):
		{
			return;
		}
		case(7):
		{
			if (RLD::delacc(userh, accounts))
			{
				accounts.resize(accounts.getsize() - 1);
				continue;
			};
			continue;
		}
		default:
			system("cls");
			cout << "o=================================================o" << endl;
			cout << "|                                                 |" << endl;
			cout << "|                                                 |" << endl;
			cout << "|                  无效的输入                     |" << endl;
			cout << "|                                                 |" << endl;
			cout << "|                                                 |" << endl;
			cout << "|                                                 |" << endl;;
			cout << "o=================================================o" << endl;
			system("pause");
			system("cls");
			continue;
		};
	};
};
//登录界面
void menu::sginmenu(Date date, Array<user_info*> accounts)
{
	int f;
	while (1) {
		system("cls");
		cout << "o=================================================o" << endl;
		cout << "|                                                 |" << endl;
		cout << "|                  1.开户                         |" << endl;
		cout << "|                  2.账号登录                     |" << endl;
		cout << "|                  3.退出系统                     |" << endl;
		cout << "|                                                 |" << endl;
		cout << "|                                                 |" << endl;
		cout << "o=================================================o" << endl;
		cout << "-> ";
		cin.clear();
		cin >> f;
		switch (f)
		{
		case(1):
		{
			system("cls");
			user_info* user = RLD::reg(date, 1, accounts);
			if (user == 0)
			{
				continue;
			}
			cout << "o=================================================o" << endl;
			cout << "|                                                 |" << endl;
			cout << "|                                                 |" << endl;
			cout << "|                  开户成功                       |" << endl;
			cout << "|                                                 |" << endl;
			cout << "|                                                 |" << endl;
			cout << "|                                                 |" << endl;;
			cout << "o=================================================o" << endl;
			cout << "-> " << endl;
			accounts.resize(accounts.getsize() + 1);
			accounts[accounts.getsize() - 1] = user;
			system("pause");
			system("cls");
			continue;
		}
		case(2): {
			system("cls");
			int userh = RLD::signin(accounts);
			if (userh == -1)
			{
				continue;
			}
			menu::usermenu(userh, date, accounts);
			continue;
		}
		case(3): {
			menu::leavemenu();
		}
		default:
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
			continue;
		};

	};
};
//离开界面
void menu::leavemenu() {
	system("cls");
	cout << "o=================================================o" << endl;
	cout << "|                                                 |" << endl;
	cout << "|                                                 |" << endl;
	cout << "|      感谢您对本银行的支持，欢迎下次光临！       |" << endl;
	cout << "|                                                 |" << endl;
	cout << "|                                                 |" << endl;
	cout << "|                                                 |" << endl;
	cout << "o=================================================o" << endl;
	system("pause");
	system("cls");
	exit(0);
};
//空白框
void menu::blankmenu() {
	cout << "o=================================================o" << endl;
	cout << "|                                                 |" << endl;
	cout << "|                                                 |" << endl;
	cout << "|                                                 |" << endl;
	cout << "|                                                 |" << endl;
	cout << "|                                                 |" << endl;
	cout << "|                                                 |" << endl;
	cout << "o=================================================o" << endl;
};