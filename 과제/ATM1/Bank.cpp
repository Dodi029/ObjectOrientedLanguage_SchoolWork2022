#include "Bank.h"

Bank::Bank() {
	num = 0;
}

void Bank::���°���() {
	string ������;
	cout << "������ �Է� : ";
	cin >> ������;
	int �ܾ�;
	cout << "�ܾ� �Է� : ";
	cin >> �ܾ�;

	����[num] = new BankAccount(num, ������, �ܾ�);
	num++;
}

void Bank::��������() {
	int ���¹�ȣ;
	cout << "���¹�ȣ �Է� : ";
	cin >> ���¹�ȣ;
	for(int i=0; i<num; i++) {
		if(����[i]->get���¹�ȣ() == ���¹�ȣ) {
			delete ����[i];
			for(int j=i+1; j<num; j++) {
				����[j-1] = ����[j];
			}
			cout << i << "�� ���°� �Ҹ�Ǿ����ϴ�." << endl;
			num--;
			return;
		}
	}
}

void Bank::��ü�������() {
	cout << "�� ������ �� : " << num << endl;
	cout << "------------------------" << endl;
	cout << "  ���¹�ȣ         �̸� " << endl;
	cout << "------------------------" << endl;
	
	for(int i=0; i<num; i++) {
		cout << "   " << ����[i]->get���¹�ȣ() << "  " << ����[i]->get������() << endl;
	}
	cout << "------------------------" << endl;
}

void Bank::���ϰ������() {
	int ���¹�ȣ;
	cout << "���¹�ȣ �Է� : ";
	cin >> ���¹�ȣ;
	
	for(int i = 0; i < num; i++) {
		if(����[i]->get���¹�ȣ() == ���¹�ȣ)
			����[i]->�����������();
	}
}

void Bank::�Ա�() {
	int ���¹�ȣ, �Աݾ�;
	cout << "���¹�ȣ �Է� : ";
	cin >> ���¹�ȣ;
	cout << "�Աݾ� �Է� : ";
	cin >> �Աݾ�;
	
	for(int i=0 ; i<num; i++) {
		if(����[i]->get���¹�ȣ() == ���¹�ȣ) {
			����[i]->�Ա�(�Աݾ�);
			return;
		}
	}
}

void Bank::���() {
	int ���¹�ȣ, ��ݾ�;
	cout << "���¹�ȣ �Է� : ";
	cin >> ���¹�ȣ;
	cout << "��ݾ� �Է� : ";
	cin >> ��ݾ�;
	
	for(int i=0; i<num; i++) {
		if(����[i]->get���¹�ȣ() == ���¹�ȣ) {
			����[i]->���(��ݾ�);
			return;
		}
	}
}