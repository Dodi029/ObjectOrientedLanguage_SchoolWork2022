#include "Bank.h"
#include <conio.h>

int main() {
	Bank b;

	char menu;
	
	do {
		system("cls");
		cout << "=======================" << endl;
		cout << "메뉴" << endl;
		cout << "=======================" << endl;
		cout << "1. 계좌 가입" << endl;
		cout << "2. 계좌 해지" << endl;
		cout << "3. 전체 계좌정보 출력" << endl;
		cout << "4. 단일 계좌정보 출력" << endl;
		cout << "5. 입금" << endl;
		cout << "6. 출금" << endl;
		cout << "7. 종료" << endl;
		cout << "=======================" << endl;
		cout << "메뉴 선택 : ";
		cin >> menu;

		switch(menu) {
			case '1':
				b.계좌가입();
				break;
			case '2':
				b.계좌해지();
				break;
			case '3':
				b.전체계좌출력();
				break;
			case '4':
				b.단일계좌출력();
				break;
			case '5':
				b.입금();
				break;
			case '6':
				b.출금();
				break;
			default:
				;
		}
		cout << "=======================" << endl;
		cout << "아무 키나 누르십시오...";
		getch();
	} while(menu >= '1' && menu <= '6');

	return 0;
}