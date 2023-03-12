#include <iostream>
#include "Screen.h"
#include "TicketBox.h"
#include "Statistics.h"
using namespace std;

KpuTicketBox::KpuTicketBox()
{
	pEuropeScreen = NULL;
	pAsiaScreen = NULL;
	pPremiumScreen = NULL;
}

KpuTicketBox::~KpuTicketBox()
{
	delete pEuropeScreen;
	delete pAsiaScreen;
	delete pPremiumScreen;
}

// 스크린 객체 생성
void KpuTicketBox::Initialize() {
	// Screen(영화제목, 티켓가격, 좌석(nRowMax), 좌석(nColMax))
	pEuropeScreen = new EuropeScreen("비포 선 라이즈", 10000, 10, 10);
	pAsiaScreen = new AsiaScreen("패왕별희", 12000, 10, 10);
	pPremiumScreen = new PremiumScreen("프리즌 이스케이프", 30000, 6, 6);
}

Screen* KpuTicketBox :: selectMenu()
{
	int menu = 0;
	cout << "-----------------------------" << endl;
	cout << "    상영관 메인 메뉴" << endl;
	cout << "-----------------------------" << endl;
	cout << "1.   유럽   영화 1관" << endl;
	cout << "2.  아시아  영화 2관" << endl;
	cout << "3. 프리미어 영화 3관" << endl;
	cout << "9.   통계   관리" << endl << endl;
	cout << " 선택(1~3,9) 그외 종료 : ";
	cin >> menu;

	switch (menu)
	{
	case 1:
		return pEuropeScreen; 
	case 2:
		return pAsiaScreen;
	case 3:
		return pPremiumScreen;
	case 9:
		Manage();
		return NULL;
	default:
		return NULL;
	}
}

void KpuTicketBox::Manage()
{
	string PWD;
	Statistics sta;
	int totalcount=0;
	cout << "-----------------------------" << endl;
	cout << "        관리자 메뉴" << endl;
	cout << "-----------------------------" << endl;
	cout << "관리자 비밀번호 입력 : ";
	cin >> PWD ;

	if (PWD == TICKETBOX_MANAGER_PWD)
	{
		totalcount += sta.totalCount(pEuropeScreen);
		totalcount += sta.totalCount(pAsiaScreen);
		totalcount += sta.totalCount(pPremiumScreen);
		cout << endl;
		cout << "1. 유럽영화 상영관 결제금액 : " << sta.totalSum(pEuropeScreen) << " 원"<< endl;
		cout << "2. 아시아영화 상영관 결제금액 : " << sta.totalSum(pAsiaScreen) << " 원" << endl;
		cout << "3. 프리미엄영화 상영관 결제금액 : " << sta.totalSum(pPremiumScreen) << " 원" << endl;
		cout << "4. 전체 티켓 판매량 : " << totalcount << " 장" << endl;
	}
	else
	{
		cout << endl;
		cout << "관리자가 아닙니다" << endl;
	}

}