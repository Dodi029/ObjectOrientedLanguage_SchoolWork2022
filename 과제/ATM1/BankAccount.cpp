#include "BankAccount.h"

BankAccount::BankAccount(int a, string b, int c) {
	���¹�ȣ = a;
	������ = b;
	�ܾ� = c;
}

void BankAccount::set���¹�ȣ(int ���¹�ȣ) {
	this->���¹�ȣ = ���¹�ȣ;
}
void BankAccount::set������(string ������) {
	this->������ = ������;
}

void BankAccount::set�ܾ�(int �ܾ�) {
	this->�ܾ� = �ܾ�;
}

int BankAccount::get���¹�ȣ() {
	return ���¹�ȣ;
}

string BankAccount::get������() {
	return ������;
}

int BankAccount::get�ܾ�() {
	return �ܾ�;
}

void BankAccount::�Ա�(int �Աݾ�) {
	�ܾ� += �Աݾ�;
	cout << �Աݾ� << "���� �ԱݵǾ� ���� �ܾ��� " << �ܾ� << "���Դϴ�." << endl;
}

void BankAccount::���(int ��ݾ�) {
	while(�ܾ� < ��ݾ�) {
		cout << "�Է��� �ݾ��� ���� �ܾ� " << �ܾ� << "������ �����ϴ�." << endl;
		cout << "��ݾ� �Է� : ";
		cin >> ��ݾ�;
	}
	�ܾ� -= ��ݾ�;
	cout << ��ݾ� << "���� ��ݵǾ� ���� �ܾ��� " << �ܾ� << "���Դϴ�." << endl;
}

void BankAccount::�����������() {
	cout << "======================" << endl;
	cout << "���� ������ ����" << endl;
	cout << "���¹�ȣ : " << ���¹�ȣ << endl;
	cout << "������ : " << ������ << endl;
	cout << "�ܾ� : " << �ܾ� << endl;
	cout << "======================" << endl;
}