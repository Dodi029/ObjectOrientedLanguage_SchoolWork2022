#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
	int ���¹�ȣ;
	string ������;
	int �ܾ�;
public:
	BankAccount(int a, string b, int c);
	void set���¹�ȣ(int ���¹�ȣ);
	void set������(string ������);
	void set�ܾ�(int �ܾ�);
	int get���¹�ȣ();
	string get������();
	int get�ܾ�();
	void �Ա�(int �Աݾ�);
	void ���(int ��ݾ�);
	void �����������();
};