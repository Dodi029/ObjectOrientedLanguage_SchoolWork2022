#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include "Ticket.hpp"

using namespace std;
class Screen {
protected:
   int nTicketPrice; // 티켓 가격
   int nRowMax, nColMax; // 좌석 행과 열 최대 값
   int nCurrentReservedId; // 발급된 마지막 예약 번호
   Ticket** pSeatArray; // 스크린 좌석에 대한 티켓 배열
   string strMovieName; // 스크린 상영중인 영화 제목
public:
   Screen(string name, int price, int row, int col);
   ~Screen();
   void showSeatMap(); // 좌석 예약 여부 맵으로 보기
   virtual void showMovieMenu(); // 영화 예매 메뉴
   virtual void showMovieInfo() = 0; // 영화 소개 정보
};
class ThrillerScreen : public Screen {      // 파생클래스 선언
public:
   ThrillerScreen(string name, int price, int row, int col) : Screen(name, price, row, col) {}    // Screen()의 파생
   void showMovieInfo();
};
class ActionScreen : public Screen {
public:
   ActionScreen(string name, int price, int row, int col) : Screen(name, price, row, col) {}
   void showMovieInfo();
};
class SFScreen : public Screen {
public:
   SFScreen(string name, int price, int row, int col) : Screen(name, price, row, col) {}
   void showMovieInfo();
};


#endif