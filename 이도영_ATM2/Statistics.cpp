#include <iostream>
#include <string>

using namespace std;

#include "Statistics.h"

int Statistics::sum(Account* pArray, int size) {							// 계좌 잔고 총합
	int totalMoney = 0;														// 초기값 = 0

	for (int i = 0; i < size; i++)
			totalMoney += (pArray + i)->getBalance();						// 배열에 저장된 모든 금액을 더함
	return totalMoney;														// 모든 더한 값을 리턴
}

int Statistics::average(Account* pArray, int size) {						// 계좌 잔고 평균
	int avg;
	int totalMoney;

	totalMoney = sum(pArray, size);											// 계좌 잔고 총합 구하기
	avg = totalMoney / size;												// 총합을 계좌 수 만큼 나누기
	return avg;																// 평균 리턴
}

int Statistics::max(Account* pArray, int size) {							// 계좌 잔고 최고값
	int max = (pArray + 0)->getBalance();									// 잔고 최고값 

	for (int i = 0; i < size; i++) {
			if ((pArray + i)->getBalance() > max)							// 값을 비교해면서 가장 큰 값 저장
				max = (pArray + i)->getBalance();
	}
	return max;																// 가장 큰 값 리턴
}

void Statistics::sort(Account* pArray, int size) {							// 내림 차순 정렬
	Account tmp;															// 바꾼 순서를 저장할 공간 선언

	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if ((pArray + i)->getBalance() < (pArray + j)->getBalance()) {	// 계좌 잔액 비교 후 더 큰 값을 
				tmp = *(pArray + j);										// 임시 공간에 잔액이 더 큰 계좌 저장

				*(pArray + j) = *(pArray + i);
				*(pArray + i) = tmp;
			}
		}
	}

	for (int i = 0; i < size; i++)											// size(계좌 수) 만큼 반복
		cout << ' ' << i + 1 << "번 " << (pArray + i)->getAccountName() << "\t" <<
		(pArray + i)->getAcctID() << "\t" << (pArray + i)->getBalance() << "원" << endl;
	cout << endl;
}
