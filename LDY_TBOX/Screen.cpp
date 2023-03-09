#include <iostream>
#include <string>
#include "Screen.hpp"
using namespace std;

Screen::Screen(string name, int price, int row, int col) {     // 스크린 객체 생성
   strMovieName = name;    // 영화의 이름을 strMovieName에 저장
   nRowMax = row;          // 저장된 행 값을 nRowMax에 저장
   nColMax = col;          // 저장된 열 값을 nColMax에 저장
   nTicketPrice = price;   // 영화의 가격을 nTicketPrice에 저장
   pSeatArray = new Ticket * [nRowMax];      // 좌석 정보를 동적생성함
   for (int r = 0; r < nRowMax; r++) {    // 행의 수만큼 반복하여
      pSeatArray[r] = new Ticket[nColMax];   // 열의 수만큼 생성. 총 행 X 열 만큼 좌석 생성
   }
   for (int i = 0; i < nRowMax; i++) {    // 행의 수만큼 반복하여
      for (int j = 0; j < nColMax; j++) {    // 열의 수만큼
         pSeatArray[i][j].setCheck(SEAT_EMPTY_MARK);  // 좌석 정보를 저장. 전부 비어있는 정보이므로 '-'로 표시
      }
   }
}
Screen::~Screen() {
	delete [] pSeatArray;      // 좌석 정보를 생성자를 통해 생성했으므로 소멸자를 통해 소멸시킴
}

void Screen::showMovieMenu(){       // 사용자가 선택한 영화의 메뉴 출력
   cout << "------------------------" << endl;
   cout << "     영화 메뉴 - " << this->strMovieName << endl;     // 선택한 영화 이름을 출력하도록 함
   cout << "------------------------" << endl;
   cout << "1. 상영 영화 정보" << endl;      // 1번 영화 메뉴 출력
   cout << "2. 좌석 예약 현황" << endl;      // 2번 영화 메뉴 출력
   cout << "7. 메인 메뉴 이동" << endl;      // 3번 영화 메뉴 출력
}

void ThrillerScreen::showMovieInfo(){    // 스릴러 영화 정보 출력
   cout << "------------------------" << endl;
   cout << "    [ " << this->strMovieName << " ]" << endl;     // 유렵 영화 제목 출력
   cout << "------------------------" << endl;
   cout << "영화관 : 스릴러 영화 1관" << endl;    // 영화관 정보 출력
   cout << "주인공 : 휴 잭맨, 크리스찬 베일, 스칼렛 요한슨" << endl;      // 영화 주인공 출력
   cout << "줄거리 : 순간이동 마술로 런던에서 대대적으로 인기를 끌던 마술사 '위대한 단톤' 앤지어가 물탱크에 빠뜨려져 살해당하는 사건이 발생한다." << endl;
   cout << "사건 현장에서 발견되어 유력한 용의자로 지목된 건 라이벌 마술사이자 순간 이동 마술로 이전에 유명세를 얻었다가 지금은 앤지어에게 자리를 내준 보든." << endl;
   cout << "재판 결과 보든은 투옥되어 사형 선고를 받고, 자신을 콜드로 경의 대리인이라고 밝힌 남자가 찾아와 고아원에 가게 된 그의 딸을 돌봐주는 대가로 그의 순간이동 마술의 비법을 알려 달라 청한다." << endl;
   cout << "보든은 그에게서 앤지어가 남긴 일기를 건네받아 읽게 되고, 숨겨져 있던 진실이 드러나는데..." << endl;      // 영화 줄거리 출력
   cout << "가격 : " << this-> nTicketPrice << "원" << endl;      // 저장된 영화 가격 출력
}

void ActionScreen::showMovieInfo(){      // 액션 영화 정보 출력
   cout << "------------------------" << endl;
   cout << "    [ " << this->strMovieName << " ]" << endl;     // 아시아 영화 제목 출력
   cout << "------------------------" << endl;
   cout << "영화관 : 액션 영화 2관" << endl;     // 영화관 정보 출력
   cout << "주인공 : 크리스찬 베일, 히스 레저, 에런 엑하트" << endl;      // 영화 주인공 출력
   cout << "줄거리 : 살아남기 위해 발버둥치던 범죄 조직들은 배트맨을 제거하기 위해 광기어린 악당 ‘조커’를 끌어들이고" << endl;
   cout << "정체를 알 수 없는 조커의 등장에 고담시 전체가 깊은 혼돈 속으로 빠져든다." << endl;
   cout << "급기야 배트맨을 향한 강한 집착을 드러낸 조커는 그가 시민들 앞에 정체를 밝힐 때까지" << endl;
   cout << "매일 새로운 사람들을 죽이겠다 선포하고 배트맨은 사상 최악의 악당 조커를 막기 위해 자신의 모든 것을 내던진 마지막 대결을 준비하게 된다." << endl;         // 영화 줄거리 출력
   cout << "가격 : " << this-> nTicketPrice << "원" << endl;      // 저장된 영화 가격 출력
}

void SFScreen::showMovieInfo(){      // SF 영화 정보 출력
   cout << "------------------------" << endl;
   cout << "    [ " << this->strMovieName << " ]" << endl;     // 프리미엄 영화 제목 출력
   cout << "------------------------" << endl;
   cout << "영화관 : SF 영화 3관" << endl;      // 영화관 정보 출력
   cout << "주인공 : 클라이브 오언,아만다 사이프리드,콜므 포어" << endl;      //영화 주인공 출력
   cout << "줄거리 : 비밀을 지우는 것이 업인 익명의 여자 '아논'. 그녀 주변에서 연쇄 살인이 발생한다." << endl;
   cout << "모두가 연결되어 오히려 취약한 미래. 범인을 잡으려면 눈에 보이는 것을 믿지 마라." << endl;         // 영화 줄거리 출력
   cout << "가격 : " << this-> nTicketPrice << "원" << endl;      // 저장된 영화 가격 출력
}