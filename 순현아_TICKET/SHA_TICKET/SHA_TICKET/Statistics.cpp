#include "Statistics.h"
#include "Screen.h"

int Statistics::totalSum(Screen* pScreen)
{
	int sum=0;
	Ticket** Ti = pScreen->getTicketArray();
	for (int row = 1; row < pScreen->getRowMax();row++)
	{
		for (int col = 1; col < pScreen->getColMax(); col++)
		{
			sum += Ti[row][col].getPayAmount();
		}
	}
	return sum;
}

int Statistics::totalCount(Screen* pScreen)
{
	int count=0;
	Ticket** Ti = pScreen->getTicketArray();
	for (int row = 1; row < pScreen->getRowMax(); row++)
	{
		for (int col = 1; col < pScreen->getColMax(); col++)
		{
			if (Ti[row][col].getCheck() == SEAT_COMPLETION_MARK)
			{
				count++;
			}	
		}
	}

	return count;
}