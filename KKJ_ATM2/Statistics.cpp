#include "Statistics.h"
#include <iostream>
using namespace std;
int Statistics::sum(Account* pArray, int size)
{
	int i, total = 0;
	Account* sArray = pArray;
	for (i = 0; i < size; i++)
	{
		total += sArray[i].getBalance();
	}
	return total;
}

int Statistics::average(Account* pArray, int size)
{
	int avg = sum(pArray, size) / size;
	return avg;
}

int Statistics::max(Account* pArray, int size)
{
	int i = 0, max;
	Account* sArray = pArray;
	max = sArray[0].getBalance();
	for (i = 0; i < size; i++)
	{
		if (sArray[i].getBalance() > max)
			max = sArray[i].getBalance();
	}
	return max;
}

void Statistics::sort(Account* pArray, int size)
{
	int i = 0, j = 0;
	Account* sArray = pArray;
	Account temp;
	for (i = 0; i < size - 1; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (sArray[i].getBalance() < sArray[j].getBalance())
			{
				temp = sArray[i];
				sArray[i] = sArray[j];
				sArray[j] = temp;
			}
		}
	}
	

	for (i = 0; i < size; i++)
	{
		cout << i + 1 << ". " << sArray[i].getAccountName() << "  " << sArray[i].getAcctID() << "  " << sArray[i].getBalance() << "¿ø" << endl;
	}


}
