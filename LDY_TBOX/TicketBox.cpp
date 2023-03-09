#include <iostream>
#include "Screen.hpp"
#include "TicketBox.hpp"
using namespace std;

// 스크린 객체 생성
void TUKoreaTBox::Initialize() {
   // Screen(영화제목, 티켓가격, 좌석(nRowMax), 좌석(nColMax))
   pThrillerScreen = new  ThrillerScreen("프레스티지", 10000, 10, 10);
   pActionScreen = new ActionScreen("다크나이트", 12000, 10, 10);
   pSFScreen = new SFScreen("아논", 30000, 6, 6);
}

Screen* TUKoreaTBox::selectMenu(){           // TicketBox.h에 있는 selectMenu를 구현
   cout << " ---------------- " << endl;
   cout << "   상영관 메인 메뉴   " << endl;
   cout << " ---------------- " << endl;
   cout << "1.  스릴러  영화 1관" << endl;
   cout << "2.  액션   영화 2관" << endl;
   cout << "3.   SF   영화 3관" << endl;
   cout << endl << "선택(1~3) 그외 종료 : ";
   
   int select;       // 사용자가 선택한 번호를 저장할 공간
   cin >> select;    // 선언한 공간에 사용자가 입력한 번호 저장
   cout << endl;     // 가독성을 위해 다음 줄로 가는 코드

   switch(select){   // 사용자가 입력한 번호에 따라 다른 함수 실행
      case 1:        // 1번 입력 시
         return pThrillerScreen;   // 스릴러 영화로 이동
      case 2:        // 2번 입력 시
         return pActionScreen;     // 액션 영화로 이동
      case 3:        // 3번 입력 시
         return pSFScreen;  // 프리미엄 영화로 이동
      default:       // 그 외 번호 입력 시
         return NULL;            // 프로그램 종료
   }


}
