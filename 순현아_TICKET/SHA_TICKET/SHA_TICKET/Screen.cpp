#include <iostream>
#include <string>
#include "Screen.h"
#include "Pay.h"

using namespace std;

Screen::Screen(string name, int price, int r, int c) {
	strMovieName = name;
	nRowMax = r + 1;
	nColMax = c + 1;
	nTicketPrice = price;
	pSeatArray = new Ticket * [nRowMax];
	for (int r = 0; r < nRowMax; r++) {
		pSeatArray[r] = new Ticket[nColMax];
	}
	for (int i = 0; i < nRowMax; i++) {
		for (int j = 0; j < nColMax; j++) {
			pSeatArray[i][j].setCheck(SEAT_EMPTY_MARK);
		}
	}
}
Screen::~Screen() { 
	for (int i = 0; i < nRowMax; i++)
	{
		delete[] pSeatArray[i];
	}
	delete[] pSeatArray;
}

Ticket*Screen::checkReservedID(int id)
{
	for (int row = 1; row < nRowMax; row++)
	{
		for (int col = 1; col < nColMax; col++)
		{
			if (id == pSeatArray[row][col].getReservedID())
			{
				return pSeatArray[row]+col;
			}
		}
	}
	
}
void Screen::showMovieMenu()
{
	cout << "----------------------------------------------------" << endl;
	cout << "      ��ȭ �޴� - " << strMovieName <<endl;
	cout << "----------------------------------------------------" << endl;
	cout << "1. �� ��ȭ ����" << endl;
	cout << "2. �¼� ���� ��Ȳ" << endl;
	cout << "3. ���� �ϱ�" << endl;
	cout << "4. ���� ���" << endl;
	cout << "5. ���� �ϱ�" << endl;
	cout << "7. ���� �޴� �̵�" << endl;
}

void Screen::showSeatMap()
{
	int nRow = 0, nCol = 0;
	cout << "\t[ �¼� ���� ��Ȳ ]" << endl;
	for (nRow = 0; nRow < nRowMax; nRow++)
	{
		if (nRow == 0)
		{
			for (nCol = 0; nCol < nColMax ; nCol++)
			{
				if (nCol == 0)cout << "\t";
				else cout << "[" << nCol << "]";
			}
		}
		else 
		{
			for (nCol = 0; nCol < nColMax ; nCol++)
			{
				if (nCol == 0)cout << "[" << nRow << "]\t";
				else
				{
					cout << "[" << pSeatArray[nRow][nCol].getCheck() << "]";
				}
			}
		}
		cout << endl;
	}
}

void Screen::reserveTicket()
{
	int rRow=0, rCol=0;

	cout << "   [ �¼� ���� ]" << endl;
	cout << "�¼� �� ��ȣ �Է� (1 - " << nRowMax-1 << ") : ";
	cin >> rRow;
	cout << "�¼� �� ��ȣ �Է� (1 - " << nColMax-1 << ") : ";
	cin >> rCol;

	if (rRow < nRowMax && rCol < nColMax)
	{
		cout << endl;
		cout << "��[" << rRow << "] ��[" << rCol << "]" << nCurrentReservedId << " ���� ��ȣ�� �����Ǿ����ϴ�." << endl;

		pSeatArray[rRow][rCol].setSeat(rRow, rCol);
		pSeatArray[rRow][rCol].setCheck(SEAT_RESERVED_MARK);
		pSeatArray[rRow][rCol].setReservedID(nCurrentReservedId);
		pSeatArray[rRow][rCol].getCheck();
		nCurrentReservedId++;
	}
	else
	{
		cout << endl;
		cout << "�Է��Ͻ� �ڸ��� �����ϴ�. " << endl;
	}
	
}

void Screen::cancelReservation()
{
	int ReservedNum;
	cout << endl;
	cout << "   [ �¼� ���� ��� ]" << endl;
	cout << "���� ��ȣ �Է� : ";
	cin >> ReservedNum;
	if (checkReservedID(ReservedNum)->getCheck() == SEAT_COMPLETION_MARK)
	{
		cout << endl;
		cout << "�����Ͻ� �¼��� ��Ұ� �Ұ��մϴ�." << endl;
	}
	else if(checkReservedID(ReservedNum)->getCheck() == SEAT_RESERVED_MARK)
	{
		cout << endl;
		cout << ReservedNum << " ���� ��ȣ�� ��� ó���Ǿ����ϴ�." << endl;
		checkReservedID(ReservedNum)->setCheck(SEAT_EMPTY_MARK);
		checkReservedID(ReservedNum)->getCheck();
	}
	else
	{
		cout << endl;
		cout << "�����Ͻ� ��ȣ�� �ƴմϴ�." << endl;
	}
	
}

void Screen::Payment()
{
	int id,menu,payment;
	string Num,name;
	Pay* pay = NULL;

	cout << "   [ �¼� ���� ���� ]" << endl;
	cout << "���� ��ȣ �Է� : ";
	cin >> id;
	cout << endl;
	if (checkReservedID(id)->getCheck() == SEAT_RESERVED_MARK)
	{
		cout << "----------------------------------------------------" << endl;
		cout << "                   ���� ��� ����" << endl;
		cout << "----------------------------------------------------" << endl;
		cout << " 1. ����� ����" << endl;
		cout << " 2. ���� ��ü ����" << endl;
		cout << " 3. ī�� ���� " << endl;
		cout << endl;
		cout << " ���� ��� (1~3) : ";
		cin >> menu;

		switch (menu)
		{
		case 1:
			cout << endl;
			cout << "\t[ ����� ���� ]" << endl;
			cout << "�ڵ��� ��ȣ �Է� (11 �ڸ��� ) : ";
			cin >> Num;
			if (Num.length() == 11)
			{
				cout << "�̸� : ";
				cin >> name;
				cout << name << "�� ����� ������ �Ϸ�Ǿ����ϴ� : ";
				pay = new MobilePay(MOBILE_PHONE_INTEREST_RATE);
				payment = MOBILE_PHONE_PAYMENT;
			}
			else
			{
				cout << endl;
				cout << "ī�� ��ȣ�� ���� �ʽ��ϴ�." << endl;
			}

			break;
		case 2:
			cout << endl;
			cout << "\t[ KPU ���� ���� ]" << endl;
			cout << "���� ��ȣ �Է� (12 �ڸ��� ) : ";
			cin >> Num;
			if (Num.length() == 12)
			{
				cout << "�̸� : ";
				cin >> name;
				cout << name << "�� KPU ���� ������ �Ϸ�Ǿ����ϴ� : ";
				pay = new BankTransfer(BANK_TRANSFER_INTEREST_RATE);
				payment = BANK_TRANSFER_PAYMENT;
			}
			else
			{
				cout << endl;
				cout << "ī�� ��ȣ�� ���� �ʽ��ϴ�." << endl;
			}
			break;
		case 3:
			cout << endl;
			cout << "\t[ �ſ�ī�� ���� ]" << endl;
			cout << "ī�� ��ȣ �Է� (12 �ڸ��� ) : ";
			cin >> Num;
			if (Num.length() == 12)
			{
				cout << "�̸� : ";
				cin >> name;
				cout << name << "�� �ſ�ī�� ������ �Ϸ�Ǿ����ϴ� : ";
				pay = new CardPay(CREDIT_CARD_INTEREST_RATE);
				payment = CREDIT_CARD_PAYMENT;
			}
			else
			{
				cout << endl;
				cout << "ī�� ��ȣ�� ���� �ʽ��ϴ�." << endl;
			}
			
			break;

		default:
			break;
		}
		if (pay != NULL)
		{
			cout << pay->charge(nTicketPrice) << endl;
			checkReservedID(id)->setCheck(SEAT_COMPLETION_MARK);
			checkReservedID(id)->getCheck();
			checkReservedID(id)->setPayAmount(pay->charge(nTicketPrice));
			checkReservedID(id)->getPayAmount();
			checkReservedID(id)->setPayMethod(payment);
		}
	}
	else
	{
		cout << endl;
		cout << "�Է��Ͻ� �����ȣ�� �����ϴ�." << endl;
	}
	
}

void EuropeScreen :: showMovieInfo()
{
	cout << "----------------------------------------------------" << endl;
	cout << "               [ "<< strMovieName <<" ]" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "   ��ȭ�� : ������ȭ 1��" << endl;
	cout << "   ���ΰ� : ���� ȣũ, �ٸ� ����" << endl;
	cout << "   �ٰŸ� : ���ÿ� �������� ���� Ⱦ�� �����ȿ��� �쿬�� ..." << endl;
	cout << "   ���� : "<<nTicketPrice << endl;
}

void AsiaScreen::showMovieInfo()
{
	cout << "----------------------------------------------------" << endl;
	cout << "               [ " << strMovieName << " ]" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "   ��ȭ�� : �ƽþƿ�ȭ 2��" << endl;
	cout << "   ���ΰ� : �屹��, ����" << endl;
	cout << "   �ٰŸ� : ����� ������ �Բ� ����� �ؿ� ������ ���� ..." << endl;
	cout << "   ���� : " << nTicketPrice << endl;
}

void  PremiumScreen::showMovieInfo()
{
	cout << "----------------------------------------------------" << endl;
	cout << "               [ " << strMovieName << " ]" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "   ��ȭ�� : �����̾���ȭ 3��" << endl;
	cout << "   ���ΰ� : �ٴϿ� ���� Ŭ����" << endl;
	cout << "   �ٰŸ� : �αǿ�� ���� ��Ƽ���� ����� �ǰ�� �����ȴ� ..." << endl;
	cout << "   ���� : " << nTicketPrice << endl;
}