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
		cout << "�������¼���˺���(������18����)" << endl;
		cin.clear();
		cin >> id;
		if ((id.length() > 18) || (id.length() == 0))
		{
			printf("%s\n", "�Ƿ��˺���");
			system("pause");
			system("cls");
			continue;
		};
		if (id == "0") 
		{
			cout << "�Ƿ����˺���" << endl;
			system("pause");
			system("cls");
			continue;
		};
		if (check::checkid(id, accounts)) 
		{
			cout << "���˺����Ѵ��ڣ��볢�������˺���" << endl;
			system("pause");
			system("cls");
			continue;
		};
		system("cls");
		while (1) {
			printf("%s\n", "�����뿪����ʵ����");
			cin.clear();
			cin >> name;
			system("cls");
			if ((name.length() > 18) || (name.length() == 0))
			{
				printf("%s\n", "������Ϸ�������");
				system("pause");
				system("cls");
				continue;
			};
			while (1)
			{
				printf("%s\n", "�������ֻ�����");
				cin.clear();
				cin >> pnum;
				system("cls");
				if ((pnum > 99999999999) || (pnum < 10000000000))
				{
					printf("%s\n", "�Ƿ��ĺ���");
					system("pause");
					system("cls");
					continue;
				};
				while (1)
				{
					printf("%s\n", "����������(�18λ)");
					cin.clear();
					cin >> password;
					system("cls");
					if ((password.length() > 18) || (password.length() == 0))
					{
						printf("%s\n", "������Ϸ�������");
						system("pause");
						system("cls");
						continue;
					};
					while (1)
					{
						printf("%s\n%s  %s\n", "��ѡ�񿪻����ͣ��������֣�", "(0)�����˻�", "(1)�����˻�");
						cin.clear();
						cin >> type;
						system("cls");
						if (type)
						{
							cout << "��ȷ����Ϣ" <<endl<<
								"��¼�û�����"<<id<<endl<<
								"�˻�����  " << name <<endl<<
								"�ֻ��ţ�  " << pnum <<endl<<
								"���룺   " << password <<endl<<
								"�˻����ͣ� �����˻�" << endl;
							cout << "(0)ȷ��" << "(1)������д" << "(2)������������ҳ��" << endl;
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
						cout << "��ȷ����Ϣ" <<endl<<
							"��¼�û�����" << id <<endl<<
							"�˻�����  " << name <<endl<<
							"�ֻ��ţ�  " << pnum <<endl<<
							"���룺   " << password <<endl<<
							"�˻����ͣ� �����˻�" << endl;
						cout << "(0)ȷ��" << "(1)������д" << "(2)������������ҳ��" << endl;
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

//��¼ʱ���������
iofsignin::iofsignin(Array<user_info*> accounts)
{
	string id;
	string password;
	while (1) {
		int fl = 0;
		system("cls");
		printf("%s\n", "�������¼�˺���");
		cin.clear();
		cin >> id;
		int userhP = check::checkid(id, accounts);
		if (userhP)
		{
			while (1) {
				int userh = userhP - 1;
				system("cls");
				cout << "����������" << endl;
				cin.clear();
				cin >> password;
				if (check::checkpassword(userh,password, accounts))
				{
					system("cls");
					cout << "������ȷ��¼�ɹ�" << endl;
					Sleep(3000);
					this->userh = userh;
					return;
				};
				bool f;
				system("cls");
				cout << "���벻��ȷ (0)�������� (1)�����˺� " << endl;
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
		cout << "�˺Ų�����" << endl;
		system("pause");
	};
};