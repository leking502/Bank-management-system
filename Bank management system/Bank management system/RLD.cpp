#include "headf.h"
#include "stdafx.h"
using namespace std;
//ע���˻�
user_info* RLD::reg(Date date, int rate, Array<user_info*> accounts)
{

	iofreg userio = iofreg(accounts);
	if (userio.id == "0")
	{
		return 0;
	};
	string id = userio.id;
	string name = userio.name;
	BOOL type = userio.type;
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
		user_info* x = user_info::createaccount(
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

//��¼�˻�
int RLD::signin(Array<user_info*> accounts)
{
	iofsignin userio = iofsignin(accounts);;
	return userio.userh;
};

//ע���˻�
bool RLD::delacc(int userh, Array<user_info*> accounts)
{
	while (1)
	{
		char b;
		system("cls");
		cout << "o=================================================o" << endl;
		cout << "|                                                 |" << endl;
		cout << "|              ��ȷ��Ҫע���˻���y/n��            |" << endl;
		cout << "|                                                 |" << endl;
		cout << "|                                                 |" << endl;
		cout << "|                                                 |" << endl;
		cout << "|                                                 |" << endl;;
		cout << "o=================================================o" << endl;
		cin >> b;
		if (b == '0')
		{
			return 0;
		}
		if (b == 'y')
		{
			string pw;
			system("cls");
			cout << "o=================================================o" << endl;
			cout << "|                                                 |" << endl;
			cout << "|             ����������ȷ�����㱾�˲���          |" << endl;
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
					cout << "|                     ��ɾ��                      |" << endl;
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
				cout << "|                  ���벻��ȷ                     |" << endl;
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
