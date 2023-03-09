#include <iostream>
#include <string>
#include "Screen.hpp"
#include "TicketBox.hpp"
using namespace std;

int main() {
   TUKoreaTBox tBox;
   Screen* screen = NULL;     // NULL로 초기화
   bool bScreenMenu = true;   // bScreenMenu를 true로 저장
   int select = 0;            // 사용자가 입력한 번호를 저장할 공간
   tBox.Initialize(); // 3개의 스크린 객체 생성
   while (1) {       // while반복문으로 영화 메뉴화면 출력 후 번호 입력 받기
      if (bScreenMenu) {      // bScreenMenu가 true이므로 

         screen = tBox.selectMenu();   // TUKoreaTBox의 serlectMenu() 실행
         bScreenMenu = false;    // 실행 후 bScreenMenu를 false로 저장하여 if문 탈출
         if (!screen) return 0;  // 만약 selectMenu()에서 1,2,3이 아닌 다른 값을 입력하여
                                 // default를 통해 NULL이 리턴될 경우 프로그램 종료
      }
      screen->showMovieMenu();   // NULL이 리턴된 경우가 아닐 경우 선택한 영화 메뉴 출력
      cout << "메뉴를 선택하세요: ";   // 출력된 정보애서 사용자가 입력한 번호를 선언한 공간에 저장
      cin >> select; cout << endl;  // 가독성을 위해 다음 줄로 이동
      switch (select) {       // switch()문을 통해 사용자가 입력한 반호에 따라 다른 함수 실행
      case 1: // 영화 정보
         screen->showMovieInfo();   // 1번을 선택한 경우 영화 정보 출력
         break;               // 다시 while()문으로 이동
      case 2: // 좌석 현황
         //screen->showSeatMap();     // 2번을 선택한 경우 좌석 예약 정보 출력
         break;               // 다시 while()문으로 이동
      case 7: // 스크린 메인 메뉴
         bScreenMenu = true;        //   bScreenMenu()을 true로 저장하여 다시 while()반복문의 if()문으로 돌아감
         break;      // while()문으로 돌아감
   
      }
   }
   return 0;
}