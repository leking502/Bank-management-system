#include "slf.h"
#include"headf.h"
int slf::savef(Date& date,Array<user_info*>& accounts)
{
	HANDLE hMapFile, hUserDate;
	CreateDirectoryA("C:\\Bankuserdate", NULL);
	
	hUserDate = CreateFileA(
		"C:\\Bankuserdate\\userdate",
		GENERIC_READ | GENERIC_WRITE,
		0,
		NULL,
		OPEN_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);
	hMapFile = CreateFileMapping(
		hUserDate,
		NULL,
		PAGE_READWRITE,
		0,
		10000,
		NULL
		);
	int x = GetLastError();
	LPVOID userdatef  = MapViewOfFile(
		hMapFile,
		FILE_MAP_ALL_ACCESS,
		0, 0, 0
	);

	ZeroMemory(userdatef, 10000);
	int add = 0;
	int* userdate = (int*)userdatef;
	*userdate = accounts.getsize();
	add += (sizeof(int) / sizeof(int));
	*(userdate + add) = date.getYear();
	add += (sizeof(int) / sizeof(int));
	*(userdate + add) = date.getMonth();
	add += (sizeof(int) / sizeof(int));
	*(userdate + add) = date.getDay();
	CreditAccount* ce;
	SavingsAccount* sa;
	add++;
	add++;
	add++;
	int caccf = 0;
	int saccf = 0;
	for (int i = 0;i < accounts.getsize();i++)
	{
		if (accounts[i]->gettype()) 
		{
			cout << accounts[i]->gettype();
			ce = (CreditAccount*)accounts[i]->getaccount();
			add++;
			*(double*)(userdate + add ) = ce->getBalance();
			*(userdate + add - 1) = (sizeof(double) / sizeof(int));
			add += (sizeof(double) / sizeof(int));
			add++;
			*(double*)(userdate + add ) = ce->getCredit();
			*(userdate + add - 1) = (sizeof(double) / sizeof(int));
			add += (sizeof(double) / sizeof(int));
			add++;
			*(double*)(userdate + add) = ce->getRate();
			*(userdate + add - 1) = (sizeof(double) / sizeof(int));
			add += (sizeof(double) / sizeof(int));
			add++;
			*(double*)(userdate + add) = ce->getFee();
			*(userdate + add - 1) = (sizeof(double) / sizeof(int));
			add += (sizeof(double) / sizeof(int));
			add++;
			*(string*)(userdate + add ) = ce->getId();
			*(userdate + add - 1) = (sizeof(ce->getId()) / sizeof(int));
			add += (sizeof(ce->getId()) / sizeof(int));
			add++;
			*(string*)(userdate + add )= accounts[i]->getname();
			*(userdate + add - 1) = (sizeof(accounts[i]->getname()) / sizeof(int));
			add += (sizeof(accounts[i]->getname()) / sizeof(int));
			add++;
			*(string*)(userdate + add)= accounts[i]->getpassword();
			*(userdate + add - 1) = (sizeof(accounts[i]->getpassword()) / sizeof(int));
			add += (sizeof(accounts[i]->getpassword()) / sizeof(int));
			add++;
			*(long long*)(userdate + add )= accounts[i]->getpnum();
			*(userdate + add - 1) = (sizeof(long long) / sizeof(int));
			add += (sizeof(long long) / sizeof(int));
			add++;
			*(int*)(userdate + add )= accounts[i]->gettype();
			*(userdate + add - 1) = (sizeof(int) / sizeof(int));;
			caccf ++;
			add++;
		};
	}
	*(userdate + 4) = caccf;
	for (int i = 0;i < accounts.getsize();i++)
	{
		if (!accounts[i]->gettype())
		{
			cout << accounts[i]->gettype();
			sa = (SavingsAccount*)accounts[i]->getaccount();
			add++;
			*(double*)(userdate + add) = sa->getBalance();
			*(userdate + add - 1) = (sizeof(double) / sizeof(int));;
			add += (sizeof(double) / sizeof(int));
			add++;
			*(double*)(userdate + add) = sa->getRate();
			*(userdate + add - 1) = (sizeof(double) / sizeof(int));;
			add += (sizeof(double) / sizeof(int));
			add++;
			*(string*)(userdate + add) = sa->getId();
			*(userdate + add - 1) = (sizeof(ce->getId()) / sizeof(int));;
			add += (sizeof(ce->getId()) / sizeof(int));
			add++;
			*(string*)(userdate + add) = accounts[i]->getname();
			*(userdate + add - 1) = (sizeof(accounts[i]->getname()) / sizeof(int));;
			add += (sizeof(accounts[i]->getname()) / sizeof(int));
			add++;
			*(string*)(userdate + add) = accounts[i]->getpassword();
			*(userdate + add - 1) = (sizeof(accounts[i]->getpassword()) / sizeof(int));;
			add += (sizeof(accounts[i]->getpassword()) / sizeof(int));
			add++;
			*(long long*)(userdate + add) = accounts[i]->getpnum();
			*(userdate + add - 1) = (sizeof(long long) / sizeof(int));;
			add += (sizeof(long long) / sizeof(int));
			add++;
			*(int*)(userdate + add) = accounts[i]->gettype();
			*(userdate + add - 1) = (sizeof(int) / sizeof(int));;
			saccf ++;
			add++;
		};
	}
	*(userdate + 5) = saccf;
	UnmapViewOfFile(userdatef);
	CloseHandle(hMapFile);
	CloseHandle(hUserDate);
	return 0;
};
int slf::loadf(Date& date, Array<user_info*>& accounts)
{
	HANDLE hMapFile, hUserDate;
	CreateDirectoryA("C:\\Bankuserdate", NULL);

	hUserDate = CreateFileA(
		"C:\\Bankuserdate\\userdate",
		GENERIC_READ | GENERIC_WRITE,
		0,
		NULL,
		OPEN_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);
	hMapFile = CreateFileMapping(
		hUserDate,
		NULL,
		PAGE_READWRITE,
		0,
		10000,
		NULL
	);
	int x = GetLastError();
	LPVOID userdatef = MapViewOfFile(
		hMapFile,
		FILE_MAP_ALL_ACCESS,
		0, 0, 0
	);
	int addf;
	int add = 0;
	int* userdate = (int*)userdatef;
	int size = *userdate;
	add += (sizeof(int) / sizeof(int));
	int Year = *(userdate + add);
	add += (sizeof(int) / sizeof(int));
	int Month = *(userdate + add);
	add += (sizeof(int) / sizeof(int));
	int Day = *(userdate + add);
	if (Year == 0)
	{
		date.changedate(2008, 11, 1);
	}
	else {
		date.changedate(Year, Month, Day);
	};
	add++;
	add++;
	add++;
	for(int i = 0;i< *(userdate + 4);i++)
	{
		addf = *(userdate + add);
		add++;
		double Balance = *(double*)(userdate + addf);
		add += addf;
		addf = *(userdate + add);
		add++;
		double Credit = *(double*)(userdate + add);
		add += addf;
		addf = *(userdate + add);
		add++;
		double Rate = *(double*)(userdate + add);
		add += addf;
		addf = *(userdate + add);
		add++;
		double Fee = *(double*)(userdate + add);
		add += addf;
		addf = *(userdate + add);
		add++;
		string Id = *(string*)(userdate + add);
		add += addf;
		addf = *(userdate + add);
		add++;
		string name = *(string*)(userdate + add);
		add += addf;
		addf = *(userdate + add);
		add++;
		string password = *(string*)(userdate + add);
		add += addf;
		addf = *(userdate + add);
		add++;
		long long pnum = *(long long*)(userdate + add);
		add += addf;
		addf = *(userdate + add);
		add++;
		int type = *(int*)(userdate + add);
		add += addf;
		CreditAccount* account1 = new CreditAccount(
			date,
			Id,
			Credit,
			Rate,
			Fee
		);
		user_info* user = user_info::createaccount(
			Id,
			name,
			pnum,
			password,
			type,
			account1,
			accounts
		);
		user->getaccount()->setbal(Balance);
		accounts.resize(accounts.getsize() + 1);
		accounts[accounts.getsize() - 1] = user;
	}
	for (int i = 0;i < *(userdate + 5);i++)
	{
		addf = *(userdate + add);
		add++;
		double Balance = *(double*)(userdate + addf);
		add += addf;
		addf = *(userdate + add);
		add++;
		double Rate = *(double*)(userdate + add);
		add += addf;
		addf = *(userdate + add);
		add++;
		string Id = *(string*)(userdate + add);
		add += addf;
		addf = *(userdate + add);
		add++;
		string name = *(string*)(userdate + add);
		add += addf;
		addf = *(userdate + add);
		add++;
		string password = *(string*)(userdate + add);
		add += addf;
		addf = *(userdate + add);
		add++;
		long long pnum = *(long long*)(userdate + add);
		add += addf;
		addf = *(userdate + add);
		add++;
		int type = *(int*)(userdate + add);
		add += addf;
		SavingsAccount* account1 = new SavingsAccount(
			date,
			Id,
			Rate
		);
		user_info* user = user_info::createaccount(
			Id,
			name,
			pnum,
			password,
			type,
			account1,
			accounts
		);
		user->getaccount()->setbal(Balance);
		accounts.resize(accounts.getsize() + 1);
		accounts[accounts.getsize() - 1] = user;
	}
	UnmapViewOfFile(userdatef);
	CloseHandle(hMapFile);
	CloseHandle(hUserDate);
	return 0;
};