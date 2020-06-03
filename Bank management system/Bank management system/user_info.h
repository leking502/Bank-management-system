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
		int pnum, //�绰����
		string password,
		bool type,
		Account* account, 
		Array<user_info*> accounts
	);
	Account* getaccount(); //��ȡ�˻���ĺ���
	int getpnum();  //��ȡ�绰����
	string getpassword();//��ȡ����
	string getname();//��ȡ����
	void changepnum(int pnum);  //��ȡ�绰����
	void changepassword(string password);//��ȡ����
	void changename(string name);//��ȡ����
	~user_info();
private:
	string password;//����
	string name;//����
	Account* account;//�˻���
	int pnum; //�ֻ���
	user_info(string id,string name, int pnum, string password,bool type, Account* account); //���캯��
};

