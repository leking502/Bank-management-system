#include "headf.h"
#include "stdafx.h"
#include "slf.h"
using namespace std;
//用户主页面
int menu::usermenu(int userh, Date& date, Array<user_info*>& accounts)
{
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
		int f ;
		cin >> f;
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
			cout << "|                  1.查看账户信息                 |" << endl;
			cout << "|                  2.取款                         |" << endl;
			cout << "|                  3.存款                         |" << endl;
			cout << "|                  4.修改密码                     |" << endl;
			cout << "|                  5.转账                         |" << endl;
			cout << "|                  6.登出                         |" << endl;
			cout << "|                  7.注销账号                     |" << endl;
			cout << "o=================================================o" << endl;
			cin >> f;
		}
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
			cout << "   余额：" << fixed << setprecision(0) <<accounts[userh]->getaccount()->getBalance() << endl;
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
					bool fpwc = 0;
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
						if (npw == pw) 
						{
							system("cls");
							cout << "o=================================================o" << endl;
							cout << "|                                                 |" << endl;
							cout << "|              新密码和旧密码不能相同             |" << endl;
							cout << "|                                                 |" << endl;
							cout << "|                                                 |" << endl;
							cout << "|                                                 |" << endl;
							cout << "|                                                 |" << endl;
							cout << "o=================================================o" << endl;
							system("pause");
							continue;
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
						slf::savef(date, accounts);
						system("pause");
						fpwc = 1;
						break;
					};
					if (fpwc) 
					{
						break;
					};
					continue;
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
			return accounts.getsize();
		}
		case(7):
		{
			RLD::delacc(userh, accounts);
			return accounts.getsize();
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
void menu::sginmenu(Date& date, Array<user_info*>& accounts)
{
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
		int f;
		cin >> f;
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
			cout << "|                  1.开户                         |" << endl;
			cout << "|                  2.账号登录                     |" << endl;
			cout << "|                  3.退出系统                     |" << endl;
			cout << "|                                                 |" << endl;
			cout << "|                                                 |" << endl;
			cout << "o=================================================o" << endl;
			cout << "-> ";
			cin >> f;
		}
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
			system("cls");
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
			slf::savef(date, accounts);
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
			int ls = menu::usermenu(userh, date, accounts);
			for (userh;userh < accounts.getsize() - 1;userh++)
			{
				accounts[userh] = accounts[userh + 1];
			};
			accounts.resize(ls);
			slf::savef(date, accounts);
			continue;
		}
		case(3): {
			menu::leavemenu();
			return;
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
	return;
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