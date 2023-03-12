#include <iostream>
#include <string>

using namespace std;

#include "Statistics.h"

int Statistics::sum(Account* pArray, int size) {							// ���� �ܰ� ����
	int totalMoney = 0;														// �ʱⰪ = 0

	for (int i = 0; i < size; i++)
			totalMoney += (pArray + i)->getBalance();						// �迭�� ����� ��� �ݾ��� ����
	return totalMoney;														// ��� ���� ���� ����
}

int Statistics::average(Account* pArray, int size) {						// ���� �ܰ� ���
	int avg;
	int totalMoney;

	totalMoney = sum(pArray, size);											// ���� �ܰ� ���� ���ϱ�
	avg = totalMoney / size;												// ������ ���� �� ��ŭ ������
	return avg;																// ��� ����
}

int Statistics::max(Account* pArray, int size) {							// ���� �ܰ� �ְ�
	int max = (pArray + 0)->getBalance();									// �ܰ� �ְ� 

	for (int i = 0; i < size; i++) {
			if ((pArray + i)->getBalance() > max)							// ���� ���ظ鼭 ���� ū �� ����
				max = (pArray + i)->getBalance();
	}
	return max;																// ���� ū �� ����
}

void Statistics::sort(Account* pArray, int size) {							// ���� ���� ����
	Account tmp;															// �ٲ� ������ ������ ���� ����

	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if ((pArray + i)->getBalance() < (pArray + j)->getBalance()) {	// ���� �ܾ� �� �� �� ū ���� 
				tmp = *(pArray + j);										// �ӽ� ������ �ܾ��� �� ū ���� ����

				*(pArray + j) = *(pArray + i);
				*(pArray + i) = tmp;
			}
		}
	}

	for (int i = 0; i < size; i++)											// size(���� ��) ��ŭ �ݺ�
		cout << ' ' << i + 1 << "�� " << (pArray + i)->getAccountName() << "\t" <<
		(pArray + i)->getAcctID() << "\t" << (pArray + i)->getBalance() << "��" << endl;
	cout << endl;
}
