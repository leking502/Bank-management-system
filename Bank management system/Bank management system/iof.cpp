#include "headf.h"
#include "stdafx.h"
using namespace std;
//注册时的输入输出
iofreg::iofreg(Array<user_info*> accounts) //输入输出相关函数类的实现
{
	bool fla;
	string id;
	string name;
	string password;
	long long  pnum;
	bool type;
	while (1) {
		system("cls");
		cout << "o=================================================o" << endl;
		cout << "|                                                 |" << endl;
		cout << "|                                                 |" << endl;
		cout << "|         请输入登录用账号名(不超过18个字)        |" << endl;
		cout << "|                                                 |" << endl;
		cout << "|                                                 |" << endl;
		cout << "|                                                 |" << endl;
		cout << "o=================================================o" << endl;
		cin.clear();
		cin >> id;
		if (id == "0")
		{
			this->id = "0";
			return;
		};
		if ((id.length() > 18) || (id.length() == 0))
		{
			system("cls");
			cout << "0=================================================0" << endl;
			cout << "|                                                 |" << endl;
			cout << "|                                                 |" << endl;
			cout << "|                   非法账号名                    |" << endl;
			cout << "|                                                 |" << endl;
			cout << "|                                                 |" << endl;
			cout << "|                                                 |" << endl;
			cout << "0=================================================o" << endl;
			system("pause");
			system("cls");
			continue;
		};
		if (check::checkid(id, accounts))
		{
			system("cls");
			cout << "o=================================================o" << endl;
			cout << "|                                                 |" << endl;
			cout << "|                                                 |" << endl;
			cout << "|         该账号名已存在，请尝试其他账号名        |" << endl;
			cout << "|                                                 |" << endl;
			cout << "|                                                 |" << endl;
			cout << "|                                                 |" << endl;
			cout << "o=================================================o" << endl;
			system("pause");
			system("cls");
			continue;
		};
		system("cls");
		while (1) {
			system("cls");
			cout << "o=================================================o" << endl;
			cout << "|                                                 |" << endl;
			cout << "|                                                 |" << endl;
			cout << "|                请输入开户真实姓名               |" << endl;
			cout << "|                                                 |" << endl;
			cout << "|                                                 |" << endl;
			cout << "|                                                 |" << endl;
			cout << "o=================================================o" << endl;
			cin.clear();
			cin >> name;
			if (name == "0")
			{
				break;
			};
			system("cls");
			if ((name.length() > 18) || (name.length() == 0))
			{
				system("cls");
				cout << "o=================================================o" << endl;
				cout << "|                                                 |" << endl;
				cout << "|                                                 |" << endl;
				cout << "|             请输入合法的姓名                    |" << endl;
				cout << "|                                                 |" << endl;
				cout << "|                                                 |" << endl;
				cout << "|                                                 |" << endl;
				cout << "o=================================================o" << endl;
				system("pause");
				system("cls");
				continue;
			};
			bool fpum = 0;
			while (1)
			{
				system("cls");
				cout << "o=================================================o" << endl;
				cout << "|                                                 |" << endl;
				cout << "|                                                 |" << endl;
				cout << "|                  请输入手机号码                 |" << endl;
				cout << "|                                                 |" << endl;
				cout << "|                                                 |" << endl;
				cout << "|                                                 |" << endl;
				cout << "o=================================================o" << endl;
				cin.clear();
				cin >> pnum;
				if (pnum == 0)
				{
					fpum = 1;
					break;
				};
				system("cls");
				if ((pnum > 99999999999) || (pnum < 10000000000))
				{
					system("cls");
					cout << "o=================================================o" << endl;
					cout << "|                                                 |" << endl;
					cout << "|                                                 |" << endl;
					cout << "|                   非法的号码                    |" << endl;
					cout << "|                                                 |" << endl;
					cout << "|                                                 |" << endl;
					cout << "|                                                 |" << endl;
					cout << "o=================================================o" << endl;
					system("pause");
					system("cls");
					continue;
				};
				bool fpw = 0;
				while (1)
				{
					system("cls");
					cout << "o=================================================o" << endl;
					cout << "|                                                 |" << endl;
					cout << "|                                                 |" << endl;
					cout << "|             请输入密码(最长18位)                |" << endl;
					cout << "|                                                 |" << endl;
					cout << "|                                                 |" << endl;
					cout << "|                                                 |" << endl;
					cout << "o=================================================o" << endl;
					cin.clear();
					cin >> password;
					if (password == "0")
					{
						fpw = 1;
						break;
					}
					system("cls");
					if ((password.length() > 18) || (password.length() == 0))
					{
						system("cls");
						cout << "o=================================================o" << endl;
						cout << "|                                                 |" << endl;
						cout << "|                                                 |" << endl;
						cout << "|               请输入合法的密码                  |" << endl;
						cout << "|                                                 |" << endl;
						cout << "|                                                 |" << endl;
						cout << "|                                                 |" << endl;
						cout << "o=================================================o" << endl;
						system("pause");
						system("cls");
						continue;
					};
					bool ftype = 0;
					while (1)
					{
						system("cls");
						cout << "o=================================================o" << endl;
						cout << "|                                                 |" << endl;
						cout << "|            请选择开户类型（输入数字）           |" << endl;
						cout << "|                                                 |" << endl;
						cout << "|                                                 |" << endl;
						cout << "|      (1)储蓄账户              (2)信用账户       |" << endl;
						cout << "|                                                 |" << endl;
						cout << "o=================================================o" << endl;
						cin.clear();
						cin >> type;
						if (type == 0)
						{
							ftype = 1;
							break;
						}
						system("cls");
						if (type == 2)
						{
							system("cls");
							cout << "o=================================================o" << endl;
							cout << "                 请确认信息                         " << endl;
							cout << "   请确认信息" << endl <<
								"   登录用户名：" << id << endl <<
								"   账户名：" << name << endl <<
								"   手机号：" << pnum << endl <<
								"   密码：" << password << endl <<
								"   账户类型： 信用账户" << endl;
							cout << "  (1)确定" << "(2)重新填写" << "(3)放弃并返回主页面 " << endl;
							cout << "o=================================================o" << endl;
							int i;
							cin.clear();
							cin >> i;
							system("cls");
							switch (i)
							{
							case(0):
							{
								continue;
							}
							case(1): {
								this->id = id;
								this->name = name;
								this->password = password;
								this->pnum = pnum;
								this->type = type;
								return;
							}
							case(2): {
								break;
							}
							case(3): {
								this->id = "0";
								this->name = "0";
								this->password = "0";
								this->pnum = NULL;
								this->type = NULL;
								return;
							}
							}
						};
						system("cls");
						cout << "o=================================================o" << endl;
						cout << "                    请确认信息                      " << endl <<
							"   登录用户名：" << id << endl <<
							"   账户名：" << name << endl <<
							"   手机号：" << pnum << endl <<
							"   密码：" << password << endl <<
							"   账户类型： 储蓄账户" << endl;
						cout << "  (1)确定" << "(2)重新填写" << "(3)放弃并返回主页面 " << endl;
						cout << "o=================================================o" << endl;
						int h;
						cin.clear();
						cin >> h;
						system("cls");
						switch (h)
						{
						case(0):
						{
							continue;
						}
						case(1): {
							this->id = id;
							this->name = name;
							this->password = password;
							this->pnum = pnum;
							this->type = type;
							return;
						}
						case(2): {
							break;
						}
						case(3): {
							this->id = "0";
							this->name = "0";
							this->password = "0";
							this->pnum = NULL;
							this->type = NULL;
							return;
							break;
						};
							   break;
							   break;
						};
						break;
					};
					if (ftype)
					{
						continue;
					}
					break;
				};
				if (fpw)
				{
					continue;
				}
				break;
			};
			if (fpum)
			{
				continue;
			}
			break;
		};
	};
};

//登录时的输入输出
iofsignin::iofsignin(Array<user_info*> accounts)
{
	string id;
	string password;
	while (1) {
		int fl = 0;
		system("cls");
		cout << "o=================================================o" << endl;
		cout << "|                                                 |" << endl;
		cout << "|                                                 |" << endl;
		cout << "|               请输入登录账号名                  |" << endl;
		cout << "|                                                 |" << endl;
		cout << "|                                                 |" << endl;
		cout << "|                                                 |" << endl;
		cout << "o=================================================o" << endl;
		cin.clear();
		cin >> id;
		if (id == "0")
		{
			this->userh = -1;
			return;
		}
		int userhP = check::checkid(id, accounts);
		if (userhP)
		{
			int fpw = 0;
			while (1) {
				int userh = userhP - 1;
				system("cls");
				cout << "o=================================================o" << endl;
				cout << "|                                                 |" << endl;
				cout << "|                                                 |" << endl;
				cout << "|                   请输入密码                    |" << endl;
				cout << "|                                                 |" << endl;
				cout << "|                                                 |" << endl;
				cout << "|                                                 |" << endl;
				cout << "o=================================================o" << endl;
				cin.clear();
				cin >> password;
				if (password == "0")
				{
					fpw = 1;
					break;
				};
				if (check::checkpassword(userh, password, accounts))
				{
					system("cls");
					cout << "o=================================================o" << endl;
					cout << "|                                                 |" << endl;
					cout << "|                                                 |" << endl;
					cout << "|                密码正确登录成功                 |" << endl;
					cout << "|                                                 |" << endl;
					cout << "|                                                 |" << endl;
					cout << "|                                                 |" << endl;
					cout << "o=================================================o" << endl;
					system("pause");
					system("cls");
					this->userh = userh;
					return;
				};
				bool f;
				system("cls");
				cout << "o=================================================o" << endl;
				cout << "|                                                 |" << endl;
				cout << "|                   密码不正确                    |" << endl;
				cout << "|                                                 |" << endl;
				cout << "|                                                 |" << endl;
				cout << "|          (1)重新输入    (2)更换账号             |" << endl;
				cout << "|                                                 |" << endl;
				cout << "o=================================================o" << endl;
				cin.clear();
				cin >> f;
				system("cls");
				if (f == 1)
				{
					continue;
				};
				fl = 1;
				break;
			};
			if (fpw)
			{
				continue;
			}
		};
		if (fl)
		{
			continue;
		};
		system("cls");
		cout << "o=================================================o" << endl;
		cout << "|                                                 |" << endl;
		cout << "|                                                 |" << endl;
		cout << "|                 账号不存在                      |" << endl;
		cout << "|                                                 |" << endl;
		cout << "|                                                 |" << endl;
		cout << "|                                                 |" << endl;
		cout << "o=================================================o" << endl;
		system("pause");
	};
};