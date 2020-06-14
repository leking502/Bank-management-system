#pragma once
#include "stdafx.h"
template<typename user_info>
class Array;
using namespace std;
class Account;
class user_info

{
public:
	static user_info* createaccount( //�����˻�����
		string id, //�û�id
		string name, //�û�����
		long long pnum, //�绰����
		string password,
		bool type,
		Account* account,
		Array<user_info*> accounts
	);
	Account* getaccount(); //��ȡ�˻���ĺ���
	long long getpnum();  //��ȡ�绰����
	string getpassword();//��ȡ����
	string getname();//��ȡ����
	void changepnum(long long pnum);  //���ĵ绰����
	void changepassword(string password);//��������
	void changename(string name);//��������
	~user_info();
private:
	string password;//����
	string name;//����
	Account* account;//�˻���
	long long pnum; //�ֻ���
	user_info(string id, string name, long long pnum, string password, bool type, Account* account); //���캯��
};

