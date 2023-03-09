#include <iostream>
#include <string>
#include "Screen.hpp"
using namespace std;

Screen::Screen(string name, int price, int row, int col) {
	strMovieName = name;
	nRowMax = row;
	nColMax = col;
	nTicketPrice = price;
	pSeatArray = new Ticket*[nRowMax];
	for (int r = 0; r < nRowMax; r++)
	{
		pSeatArray[r] = new Ticket[nColMax];
	}
	for (int i = 0; i < nRowMax; i++)
	{
		for (int j = 0; j < nColMax; j++) {
			pSeatArray[i][j].setCheck(SEAT_EMPTY_MARK);
		}
	}
}

Screen::~Screen()
{
	delete [] pSeatArray;
}

void Screen::showSeatMap()
{
	cout << "\t[ 좌석 예약 현황 ]" << endl;
	cout << "\t";
	for (int i = 0; i < this->nRowMax; i++)
	{
		cout << "[" << i+1 << "] ";
	}
	cout << endl;
	for (int i = 0; i < this->nRowMax; i++)
	{
		cout << "[" << i + 1 << "] ";
		cout << "\t";
		for (int j = 0; j < this->nColMax; j++)
		{
			cout << "[" << pSeatArray[i][j].getCheck() << "] ";
		}
		cout << endl;
	}

}

void Screen::showMovieMenu()
{
	cout << "----------------" << endl;
	cout << "영화 메뉴 -" << this->strMovieName << endl;
	cout << "----------------" << endl;
	cout << "1. 상영 영화 정보" << endl;
	cout << "2. 좌석 예약 현황" << endl;
	cout << "7. 메인 메뉴 이동" << endl;
}

void EuropeScreen::showMovieInfo() {
	cout << "-----------" << endl;
	cout << "[" << this->strMovieName << "]" << endl;
	cout << "-----------" << endl;
	cout << "영화관 : 유럽영화 1관" << endl;
	cout << "주인공 : 오웬 윌슨, 레이첼 맥 아담스" << endl;
	cout << "줄거리 : 약혼자 이네즈를 두고 홀로 파리의 밤거리를 배화하던 길은..." << endl;
	cout << "가격 : " << this->nTicketPrice << "원" << endl; cout << endl;
}

void AsiaScreen::showMovieInfo() {
	cout << "-----------" << endl;
	cout << "[" << this->strMovieName << "]" << endl;
	cout << "-----------" << endl;
	cout << "영화관 : 아시아영화 2관" << endl;
	cout << "주인공 : 짱깨" << endl;
	cout << "줄거리 : 코로나..." << endl;
	cout << "가격 : " << this->nTicketPrice << "원" << endl; cout << endl;
}

void PremiumScreen::showMovieInfo() {
	cout << "-----------" << endl;
	cout << "[" << this->strMovieName << "]" << endl;
	cout << "-----------" << endl;
	cout << "영화관 : 프리미엄영화 1관" << endl;
	cout << "주인공 : 토니스타크" << endl;
	cout << "줄거리 : 아임 아이언맨" << endl;
	cout << "가격 : " << this->nTicketPrice << "원" << endl; cout << endl;
}