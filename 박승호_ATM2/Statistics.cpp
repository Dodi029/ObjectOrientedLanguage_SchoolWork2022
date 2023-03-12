#include <iostream>
#include <string>
#include "ATMachine.h"
#include "Account.h"
#include "Statistics.h"

using namespace std;

class Statistics;

int Statistics::sum(Account* pArray, int size) {
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += pArray[i].getBalance();
	}
	return sum;
}
int Statistics::average(Account* pArray, int size) {
	int sum = 0;
	double average = 0;
	for (int i = 0; i < size; i++)
	{
		sum += pArray[i].getBalance();
	}
	average = (double)sum / size;
	return average;
}
int Statistics::max(Account* pArray, int size) {
	int max = INT_MIN;
	for (int i = 0; i < size; i++)
	{
		if (pArray[i].getBalance() > max) {
			max = pArray[i].getBalance();
		}
	}
	return max;
}
void Statistics::sort(Account* pArray, int size) {
	Account* newArray = pArray;
	Account temp;
	for (int i = 0; i < size-1; i++)
	{
		for (int j = i + 1; j < size; j++) {
			if (newArray[j].getBalance() > newArray[i].getBalance()) {
				temp = newArray[i];
				newArray[i] = newArray[j];
				newArray[j] = temp;
			}
		}		
	}
	for (int i = 0; i < size; i++) {
		cout << newArray[i].getAccountName() << "\t" << newArray[i].getAcctID() << "\t" << newArray[i].getBalance() << endl;
	}
}