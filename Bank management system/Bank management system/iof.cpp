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
		cout << "请输入登录用账号名(不超过18个字)" << endl;
		cin.clear();
		cin >> id;
		if ((id.length() > 18) || (id.length() == 0))
		{
			printf("%s\n", "非法账号名");
			system("pause");
			system("cls");
			continue;
		};
		if (id == "0") 
		{
			cout << "非法的账号名" << endl;
			system("pause");
			system("cls");
			continue;
		};
		if (check::checkid(id, accounts)) 
		{
			cout << "该账号名已存在，请尝试其他账号名" << endl;
			system("pause");
			system("cls");
			continue;
		};
		system("cls");
		while (1) {
			printf("%s\n", "请输入开户真实姓名");
			cin.clear();
			cin >> name;
			system("cls");
			if ((name.length() > 18) || (name.length() == 0))
			{
				printf("%s\n", "请输入合法的姓名");
				system("pause");
				system("cls");
				continue;
			};
			while (1)
			{
				printf("%s\n", "请输入手机号码");
				cin.clear();
				cin >> pnum;
				system("cls");
				if ((pnum > 99999999999) || (pnum < 10000000000))
				{
					printf("%s\n", "非法的号码");
					system("pause");
					system("cls");
					continue;
				};
				while (1)
				{
					printf("%s\n", "请输入密码(最长18位)");
					cin.clear();
					cin >> password;
					system("cls");
					if ((password.length() > 18) || (password.length() == 0))
					{
						printf("%s\n", "请输入合法的密码");
						system("pause");
						system("cls");
						continue;
					};
					while (1)
					{
						printf("%s\n%s  %s\n", "请选择开户类型（输入数字）", "(0)储蓄账户", "(1)信用账户");
						cin.clear();
						cin >> type;
						system("cls");
						if (type)
						{
							cout << "请确认信息" <<endl<<
								"登录用户名："<<id<<endl<<
								"账户名：  " << name <<endl<<
								"手机号：  " << pnum <<endl<<
								"密码：   " << password <<endl<<
								"账户类型： 信用账户" << endl;
							cout << "(0)确定" << "(1)重新填写" << "(2)放弃并返回主页面" << endl;
							int i;
							cin.clear();
							cin >> i;
							system("cls");
							switch (i)
							{
							case(0): {
								this->id = id;
								this->name = name;
								this->password = password;
								this->pnum = pnum;
								this->type = type;
								return;
							}
							case(1): {
								break;
							}
							case(2): {
								this->id = "0";
								this->name = "0";
								this->password = "0";
								this->pnum = NULL;
								this->type = NULL;
								return;
							}
							}
						};
						cout << "请确认信息" <<endl<<
							"登录用户名：" << id <<endl<<
							"账户名：  " << name <<endl<<
							"手机号：  " << pnum <<endl<<
							"密码：   " << password <<endl<<
							"账户类型： 储蓄账户" << endl;
						cout << "(0)确定" << "(1)重新填写" << "(2)放弃并返回主页面" << endl;
						int h;
						cin.clear();
						cin >> h;
						system("cls");
						switch (h)
						{
						case(0): {
							this->id = id;
							this->name = name;
							this->password = password;
							this->pnum = pnum;
							this->type = type;
							return;
						}
						case(1): {
							break;
						}
						case(2): {
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
					break;
				};
				break;
			};
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
		printf("%s\n", "请输入登录账号名");
		cin.clear();
		cin >> id;
		int userhP = check::checkid(id, accounts);
		if (userhP)
		{
			while (1) {
				int userh = userhP - 1;
				system("cls");
				cout << "请输入密码" << endl;
				cin.clear();
				cin >> password;
				if (check::checkpassword(userh,password, accounts))
				{
					system("cls");
					cout << "密码正确登录成功" << endl;
					Sleep(3000);
					this->userh = userh;
					return;
				};
				bool f;
				system("cls");
				cout << "密码不正确 (0)重新输入 (1)更换账号 " << endl;
				cin.clear();
				cin >> f;
				system("cls");
				if (!f) 
				{
					continue;
				};
				fl = 1;
				break;
			};
		};
		if (fl) 
		{
			continue;
		};
		system("cls");
		cout << "账号不存在" << endl;
		system("pause");
	};
};