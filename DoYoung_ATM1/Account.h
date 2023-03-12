#ifndef ACCOUNT_H
#define ACCOUNT_H

using std::string;

#define AUTHENTIFICATION_FAIL			 -1								// ���� ���� ����
#define AUTHENTIFICATION_SUCCESS		 1								// ���� ���� ����
#define BASE_ACCOUNT_ID					100								// ���¹�ȣ�� 100�� ���� 1000���� �������� �ο�

class Account {
private:
	int nID;															// ���� ��ȣ(�ʱ� �� = -1)
	int nBalance;														// �ܰ� (�ʱ� �� = 0)
	string strAccountName;												// �� ��
	string strPassword;													// ���� ��й�ȣ

private:
	inline bool authenticate(int id, string passwd);					// ���� ���� : true(1), ���� ���� : false(0)

public:
	Account();
	void create(int id, int money, string name, string password);		// ���°���
	void close();														// ���� ����
	int check(int id, string password);									// return �� : nBalance(�ܰ�) or ���� ����(AUTHENTIFICATION_FAIL)
	int getAcctID() { return nID; }										// ���� ��ȣ �о����
	int deposit(int id, string password, int inmoney);					// ���� �Ա�
	int widraw(int id, string password, int outmoney);					// ���
	int deposit(int id, int money);										// ���� ��ü
};

#endif