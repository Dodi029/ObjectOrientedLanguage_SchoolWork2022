#include <iostream>
#include "Screen.hpp"
#include "TicketBox.hpp"
using namespace std;

void TUKoreaTBox::Initialize() {
	pEuropeScreen = new EuropeScreen("미드나잇 인 파리", 10000, 10, 10);
	pAsiaScreen = new AsiaScreen("무간도", 12000, 10, 10);
	pPremiumScreen = new PremiumScreen("어벤저스", 30000, 6, 6);
}

TUKoreaTBox::TUKoreaTBox()
{
}

TUKoreaTBox::~TUKoreaTBox()
{
}

Screen* TUKoreaTBox::selectMenu()
{
	int select;
	cout << "-----------" << endl;
	cout << "-상영관 메인 메뉴-" << endl;
	cout << "-----------" << endl;
	cout << "1. 유럽 영화 1관" << endl;
	cout << "2. 아시아 영화 2관" << endl;
	cout << "3. 프리미엄 영화 3관" << endl; cout << endl;
	cout << "선택(1~3) 그외 종료: ";
	cin >> select; cout << endl;
	switch (select) {
	case 1:
		return pEuropeScreen;
	case 2:
		return pAsiaScreen;
	case 3:
		return pPremiumScreen;
	default:
		return NULL;
	}
	
}
