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
	cout << "      영화 메뉴 - " << strMovieName <<endl;
	cout << "----------------------------------------------------" << endl;
	cout << "1. 상영 영화 정보" << endl;
	cout << "2. 좌석 예약 현황" << endl;
	cout << "3. 예약 하기" << endl;
	cout << "4. 예약 취소" << endl;
	cout << "5. 결제 하기" << endl;
	cout << "7. 메인 메뉴 이동" << endl;
}

void Screen::showSeatMap()
{
	int nRow = 0, nCol = 0;
	cout << "\t[ 좌석 예약 현황 ]" << endl;
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

	cout << "   [ 좌석 예약 ]" << endl;
	cout << "좌석 행 번호 입력 (1 - " << nRowMax-1 << ") : ";
	cin >> rRow;
	cout << "좌석 열 번호 입력 (1 - " << nColMax-1 << ") : ";
	cin >> rCol;

	if (rRow < nRowMax && rCol < nColMax)
	{
		cout << endl;
		cout << "행[" << rRow << "] 열[" << rCol << "]" << nCurrentReservedId << " 예약 번호로 접수되었습니다." << endl;

		pSeatArray[rRow][rCol].setSeat(rRow, rCol);
		pSeatArray[rRow][rCol].setCheck(SEAT_RESERVED_MARK);
		pSeatArray[rRow][rCol].setReservedID(nCurrentReservedId);
		pSeatArray[rRow][rCol].getCheck();
		nCurrentReservedId++;
	}
	else
	{
		cout << endl;
		cout << "입력하신 자리가 없습니다. " << endl;
	}
	
}

void Screen::cancelReservation()
{
	int ReservedNum;
	cout << endl;
	cout << "   [ 좌석 예약 취소 ]" << endl;
	cout << "예약 번호 입력 : ";
	cin >> ReservedNum;
	if (checkReservedID(ReservedNum)->getCheck() == SEAT_COMPLETION_MARK)
	{
		cout << endl;
		cout << "결제하신 좌석은 취소가 불가합니다." << endl;
	}
	else if(checkReservedID(ReservedNum)->getCheck() == SEAT_RESERVED_MARK)
	{
		cout << endl;
		cout << ReservedNum << " 예약 번호가 취소 처리되었습니다." << endl;
		checkReservedID(ReservedNum)->setCheck(SEAT_EMPTY_MARK);
		checkReservedID(ReservedNum)->getCheck();
	}
	else
	{
		cout << endl;
		cout << "예약하신 번호가 아닙니다." << endl;
	}
	
}

void Screen::Payment()
{
	int id,menu,payment;
	string Num,name;
	Pay* pay = NULL;

	cout << "   [ 좌석 예약 결제 ]" << endl;
	cout << "예약 번호 입력 : ";
	cin >> id;
	cout << endl;
	if (checkReservedID(id)->getCheck() == SEAT_RESERVED_MARK)
	{
		cout << "----------------------------------------------------" << endl;
		cout << "                   결제 방식 선택" << endl;
		cout << "----------------------------------------------------" << endl;
		cout << " 1. 모바일 결제" << endl;
		cout << " 2. 은행 이체 결제" << endl;
		cout << " 3. 카드 결제 " << endl;
		cout << endl;
		cout << " 결제 방식 (1~3) : ";
		cin >> menu;

		switch (menu)
		{
		case 1:
			cout << endl;
			cout << "\t[ 모바일 결제 ]" << endl;
			cout << "핸드폰 번호 입력 (11 자리수 ) : ";
			cin >> Num;
			if (Num.length() == 11)
			{
				cout << "이름 : ";
				cin >> name;
				cout << name << "님 모바일 결제가 완료되었습니다 : ";
				pay = new MobilePay(MOBILE_PHONE_INTEREST_RATE);
				payment = MOBILE_PHONE_PAYMENT;
			}
			else
			{
				cout << endl;
				cout << "카드 번호가 맞지 않습니다." << endl;
			}

			break;
		case 2:
			cout << endl;
			cout << "\t[ KPU 은행 결제 ]" << endl;
			cout << "은행 번호 입력 (12 자리수 ) : ";
			cin >> Num;
			if (Num.length() == 12)
			{
				cout << "이름 : ";
				cin >> name;
				cout << name << "님 KPU 은행 결제가 완료되었습니다 : ";
				pay = new BankTransfer(BANK_TRANSFER_INTEREST_RATE);
				payment = BANK_TRANSFER_PAYMENT;
			}
			else
			{
				cout << endl;
				cout << "카드 번호가 맞지 않습니다." << endl;
			}
			break;
		case 3:
			cout << endl;
			cout << "\t[ 신용카드 결제 ]" << endl;
			cout << "카드 번호 입력 (12 자리수 ) : ";
			cin >> Num;
			if (Num.length() == 12)
			{
				cout << "이름 : ";
				cin >> name;
				cout << name << "님 신용카드 결제가 완료되었습니다 : ";
				pay = new CardPay(CREDIT_CARD_INTEREST_RATE);
				payment = CREDIT_CARD_PAYMENT;
			}
			else
			{
				cout << endl;
				cout << "카드 번호가 맞지 않습니다." << endl;
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
		cout << "입력하신 예약번호가 없습니다." << endl;
	}
	
}

void EuropeScreen :: showMovieInfo()
{
	cout << "----------------------------------------------------" << endl;
	cout << "               [ "<< strMovieName <<" ]" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "   영화관 : 유럽영화 1관" << endl;
	cout << "   주인공 : 에단 호크, 줄리 델피" << endl;
	cout << "   줄거리 : 제시와 셀린느는 유럽 횡단 열차안에서 우연히 ..." << endl;
	cout << "   가격 : "<<nTicketPrice << endl;
}

void AsiaScreen::showMovieInfo()
{
	cout << "----------------------------------------------------" << endl;
	cout << "               [ " << strMovieName << " ]" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "   영화관 : 아시아영화 2관" << endl;
	cout << "   주인공 : 장국영, 공리" << endl;
	cout << "   줄거리 : 어렸을 때부터 함꼐 경극을 해온 두지와 시투 ..." << endl;
	cout << "   가격 : " << nTicketPrice << endl;
}

void  PremiumScreen::showMovieInfo()
{
	cout << "----------------------------------------------------" << endl;
	cout << "               [ " << strMovieName << " ]" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "   영화관 : 프리미엄영화 3관" << endl;
	cout << "   주인공 : 다니엘 래드 클리프" << endl;
	cout << "   줄거리 : 인권운동가 팀과 스티븐은 억울한 판결로 투옥된다 ..." << endl;
	cout << "   가격 : " << nTicketPrice << endl;
}