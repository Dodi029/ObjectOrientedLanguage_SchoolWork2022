#include "ATMachine.h"
#include "Account.h"
#include "Statistics.h"
#include <random>
#define ID_CHECK 1
using namespace std;

ATMachine::ATMachine(int size, int balance, string password)
{
	nMachineBalance = balance;
	strManagerPassword = password;
	nMaxAccountNum = size;
	nCurrentAccountNum = 0;
	pAcctArray = new Account[nMaxAccountNum];
}

bool ATMachine::isManager(string password)
{
	if (strManagerPassword == password)
		return true;
	else
		return false;
}

void ATMachine::displayReport()
{
	cout << "\n----------------" << endl;
	cout << "ATM  ���� �ܰ�: " << nMachineBalance << "��" << endl;
	cout << "�� �ܰ� �Ѿ�: " << Statistics::sum(pAcctArray, nCurrentAccountNum) << "��" << "(��" << nCurrentAccountNum << "��)" << endl;
	cout << "�� �ܰ� ���: " << Statistics::average(pAcctArray, nCurrentAccountNum) << "��" << endl;
	cout << "�� �ܰ� �ְ�: " << Statistics::max(pAcctArray, nCurrentAccountNum) << "��" << endl;
	cout << "----------------" << endl;
	cout << "-�� ���� ���-" << endl;
	cout << "----------------" << endl;
	Statistics::sort(pAcctArray, nCurrentAccountNum);
}

ATMachine::~ATMachine()
{
	delete[] pAcctArray;
}


void ATMachine::displayMenu()
{
	cout << "----------------" << endl;
	cout << "--TUKOREA BANK--" << endl;
	cout << "----------------" << endl;
	cout << "1. ���� ����" << endl;
	cout << "2. ���� ��ȸ" << endl;
	cout << "3. ���� �Ա�" << endl;
	cout << "4. ���� ���" << endl;
	cout << "5. ���� ��ü" << endl;
	cout << "6. ���� ����" << endl;
	cout << "7. �� ����" << endl;
	cout << "9. ���� ����" << endl;
}

void ATMachine::createAccount()
{
	int id;
	int money = 0;
	string name, password;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(BASE_ACCOUNT_ID, 1000);
	id = dis(gen);

	cout << "------����------" << endl;
	cout << "�̸� �Է�: ";
	cin.ignore();
	getline(cin, name);
	cout << "��й�ȣ �Է�: ";
	getline(cin, password);
	
	pAcctArray[nCurrentAccountNum].create(id, money, name, password);
	cout << name << "�� " << id << "�� ���¹�ȣ�� ���������� �����Ǿ����ϴ�. �����մϴ�." << endl;
	nCurrentAccountNum++;
}

void ATMachine::checkMoney()
{
	int id, check = 0;
	string password;
	cout << "------��ȸ------" << endl;
	cout << "���¹�ȣ �Է�: ";
	cin >> id;
	cin.ignore();

	for (int i = 0; i < nCurrentAccountNum; i++)
	{
		if (pAcctArray[i].getAcctID() == id)
		{
			check = ID_CHECK;
			cout << "��й�ȣ �Է�: ";
			getline(cin, password);
			if (pAcctArray[i].check(id, password) != AUTHENTIFICATION_FAIL)
				cout << "�����ܾ�: " << pAcctArray[i].check(id, password) << "��" << endl;
			else
				cout << "��й�ȣ�� Ʋ�Ƚ��ϴ�." << endl;
		}
	}
	if (check == 0)
		cout << "�ش� ���¹�ȣ�� �������� �ʽ��ϴ�." << endl;
}

void ATMachine::closeAccount()
{
	int id, check = 0;
	string password;
	cout << "------����------" << endl;
	cout << "���¹�ȣ �Է�: ";
	cin >> id;
	cin.ignore();
	cout << "��й�ȣ �Է�: ";
	getline(cin, password);
	for (int i= 0; i < nCurrentAccountNum; i++)
	{ 
		if (pAcctArray[i].getAcctID() == id)
		{
			check = ID_CHECK;
			if (pAcctArray[i].check(id, password) != AUTHENTIFICATION_FAIL)
			{
				if (pAcctArray[i].check(id, password) != 0)
				{
					cout << id << "�� ���¸� ������ �� �����ϴ�.  �ܾ�: " << pAcctArray[i].check(id, password) << "��" << endl;
				}
				else
				{
					pAcctArray[i].close();
				}
			}
			else
				cout << "��й�ȣ�� Ʋ�Ƚ��ϴ�." << endl;
		}
	}
	if (check == 0)
		cout << "�ش� ���¹�ȣ�� �������� �ʽ��ϴ�." << endl;
		
}

void ATMachine::despositMoeny()
{
	int id, money, check = 0, d_money;
	string password;
	cout << "------�Ա�------" << endl;
	cout << "���¹�ȣ �Է�: ";
	cin >> id;
	cin.ignore();
	for (int i = 0; i < nCurrentAccountNum; i++)
	{
		if (pAcctArray[i].getAcctID() == id)
		{
			check = ID_CHECK;
			cout << "��й�ȣ �Է�: ";
			getline(cin, password);
			if (pAcctArray[i].check(id, password) != AUTHENTIFICATION_FAIL)
			{
				cout << "�Աݾ�  �Է�: ";
				cin >> money;
				d_money = pAcctArray[i].deposit(id, password, money);
				cout << "���� �ܾ�: " << d_money << "��" << endl;
				cout << "�Ա� �Ϸ�" << endl;
				nMachineBalance += d_money;
			}
			else
				cout << "��й�ȣ�� Ʋ�Ƚ��ϴ�." << endl;
		}
	}
	if (check == 0)
		cout << "�ش� ���¹�ȣ�� �������� �ʽ��ϴ�." << endl;
}

void ATMachine::widrawMoney()
{
	if (nMachineBalance == NEGATIVE_ATM_BALANCE)
		cout << "�˼��մϴ�. ATM �ܾ��� �����ϴ� �ٸ� ATM �̿�ٶ��ϴ�." << endl;
	else
	{
		int id, money, check = 0, w_money = 0;
		string password;
		cout << "------���------" << endl;
		cout << "���¹�ȣ �Է�: ";
		cin >> id;
		cin.ignore();
		for (int i = 0; i < nCurrentAccountNum; i++)
		{
			if (pAcctArray[i].getAcctID() == id)
			{
				check = ID_CHECK;
				cout << "��й�ȣ �Է�: ";
				getline(cin, password);
				if (pAcctArray[i].check(id, password) != AUTHENTIFICATION_FAIL)
				{
					cout << "��ݾ�  �Է�: ";
					cin >> money;
					w_money = pAcctArray[i].widraw(id, password, money);
					if (w_money > -1)
					{
						if (nMachineBalance >= money)
						{
							cout << "���� �ܾ�: " << w_money << "��" << endl;
							cout << "��� �Ϸ�" << endl;
							nMachineBalance -= w_money;
						}
					}
					else
					{
						cout << "�ܾ� ����" << endl;
						cout << "�����ܾ�: " << pAcctArray[i].check(id, password) << "��" << endl;
					}
				}
				else
					cout << "��й�ȣ�� Ʋ�Ƚ��ϴ�." << endl;
			}
		}
		if (check == 0)
			cout << "�ش� ���¹�ȣ�� �������� �ʽ��ϴ�." << endl;
	}
}

void ATMachine::transfer()
{
	int id, check = 0, t_id, t_id_check = 0, t_money = 0, i_money = 0, balance = 0;
	string password;
	cout << "------��ü------" << endl;
	cout << "���¹�ȣ �Է�: ";
	cin >> id;
	cin.ignore();
	for (int i = 0; i < nCurrentAccountNum; i++)
	{
		if (pAcctArray[i].getAcctID() == id)
		{
			check = ID_CHECK;
			cout << "��й�ȣ �Է�: ";
			getline(cin, password);
			if (pAcctArray[i].check(id, password) != AUTHENTIFICATION_FAIL)
			{
				cout << "��ü���� �Է�: ";
				cin >> t_id;
				cin.ignore();
				for (int j = 0; j < nCurrentAccountNum; j++)
				{
					if (pAcctArray[j].getAcctID() == t_id)
					{
						t_id_check = ID_CHECK;
						cout << "��ü�ݾ� �Է�: ";
						cin >> t_money;
						i_money = pAcctArray[i].widraw(id, password, t_money);
						if (i_money > -1)
						{
							pAcctArray[j].deposit(t_id, t_money);
							cout << "���� �ܾ�: " << i_money << endl;
						}
						else
							cout << "�ܾ� ����" << endl;
					}
				}
				if (t_id_check == 0)
					cout << "�ش� ���¹�ȣ�� �������� �ʽ��ϴ�." << endl;
			}
			else
				cout << "��й�ȣ�� Ʋ�Ƚ��ϴ�." << endl;
		}
	}
	if (check == 0)
		cout << "�ش� ���¹�ȣ�� �������� �ʽ��ϴ�." << endl;
}

void ATMachine::managerMode()
{
	string password;
	cout << "------����------" << endl;
	cout << "������ ��й�ȣ �Է�: ";
	cin >> password;
	if (isManager(password) == 1)
	{
		cout << "\n�������Դϴ�." << endl;
		displayReport();
	}

	else
		cout << "������ ������ �����ϴ�." << endl;
}

	