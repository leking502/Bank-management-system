#include "headf.h"
#include "stdafx.h"
using namespace std;
//ע��ʱ���������
iofreg::iofreg(Array<user_info*> accounts) //���������غ������ʵ��
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
		cout << "|         �������¼���˺���(������18����)        |" << endl;
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
			cout << "|                   �Ƿ��˺���                    |" << endl;
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
			cout << "|         ���˺����Ѵ��ڣ��볢�������˺���        |" << endl;
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
			cout << "|                �����뿪����ʵ����               |" << endl;
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
				cout << "|             ������Ϸ�������                    |" << endl;
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
				cout << "|                  �������ֻ�����                 |" << endl;
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
					cout << "|                   �Ƿ��ĺ���                    |" << endl;
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
					cout << "|             ����������(�18λ)                |" << endl;
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
						cout << "|               ������Ϸ�������                  |" << endl;
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
						cout << "|            ��ѡ�񿪻����ͣ��������֣�           |" << endl;
						cout << "|                                                 |" << endl;
						cout << "|                                                 |" << endl;
						cout << "|      (1)�����˻�              (2)�����˻�       |" << endl;
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
							cout << "                 ��ȷ����Ϣ                         " << endl;
							cout << "   ��ȷ����Ϣ" << endl <<
								"   ��¼�û�����" << id << endl <<
								"   �˻�����" << name << endl <<
								"   �ֻ��ţ�" << pnum << endl <<
								"   ���룺" << password << endl <<
								"   �˻����ͣ� �����˻�" << endl;
							cout << "  (1)ȷ��" << "(2)������д" << "(3)������������ҳ�� " << endl;
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
						cout << "                    ��ȷ����Ϣ                      " << endl <<
							"   ��¼�û�����" << id << endl <<
							"   �˻�����" << name << endl <<
							"   �ֻ��ţ�" << pnum << endl <<
							"   ���룺" << password << endl <<
							"   �˻����ͣ� �����˻�" << endl;
						cout << "  (1)ȷ��" << "(2)������д" << "(3)������������ҳ�� " << endl;
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

//��¼ʱ���������
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
		cout << "|               �������¼�˺���                  |" << endl;
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
				cout << "|                   ����������                    |" << endl;
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
					cout << "|                ������ȷ��¼�ɹ�                 |" << endl;
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
				cout << "|                   ���벻��ȷ                    |" << endl;
				cout << "|                                                 |" << endl;
				cout << "|                                                 |" << endl;
				cout << "|          (1)��������    (2)�����˺�             |" << endl;
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
		cout << "|                 �˺Ų�����                      |" << endl;
		cout << "|                                                 |" << endl;
		cout << "|                                                 |" << endl;
		cout << "|                                                 |" << endl;
		cout << "o=================================================o" << endl;
		system("pause");
	};
};