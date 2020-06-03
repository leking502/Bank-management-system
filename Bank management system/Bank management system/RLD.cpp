#include "headf.h"
#include "stdafx.h"
using namespace std;
//ע���˻�
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
		cout << "��ȷ��Ҫע���˻���y/n��" << endl;
		cin >> b;
		if (b == 'y') 
		{
			string pw;
			system("cls");
			cout << "����������ȷ�����㱾�˲���" << endl;
			cin >> pw;
			while (1) {
				if (check::checkpassword(userh, pw, accounts))
				{
					system("cls");
					delete accounts[userh];
					cout << "��ɾ��" << endl;
					system("pause");
					system("cls");
					return 1;
				}
				system("cls");
				cout << "���벻��ȷ" << endl;
				system("pause");
				break;
			};

		};
		return 0;
	};
};
