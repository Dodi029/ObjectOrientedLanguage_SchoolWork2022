#include <iostream>
#include "Screen.h"
#include "TicketBox.h"
#include "Statistics.h"
using namespace std;

// 스크린 객체 생성
void TUKoreaTBox::Initialize() {
    // Screen(영화제목, 티켓가격, 좌석(nRowMax), 좌석(nColMax))
    pThrillerScreen = new  ThrillerScreen("프레스티지", 10000, 20, 15);      // 영화 정보 동적 생성
    pActionScreen = new ActionScreen("다크나이트", 12000, 20, 20);           // 영화 정보 동적 생성
    pSFScreen = new SFScreen("아논", 30000, 12, 12);                          // 영화 정보 동적 생성
}

TUKoreaTBox::TUKoreaTBox() {
    pThrillerScreen = NULL;     // 초기화
    pActionScreen = NULL;       // 초기화
    pSFScreen = NULL;           // 초기화
}

TUKoreaTBox::~TUKoreaTBox() {
    delete pThrillerScreen;     // 동적 생성한 영화 정보 소멸
    delete pActionScreen;       // 동적 생성한 영화 정보 소멸
    delete pSFScreen;           // 동적 생성한 영화 정보 소멸
}

Screen* TUKoreaTBox::selectMenu() {           // TicketBox.h에 있는 selectMenu를 구현
    cout << "------------------------------------" << endl;
    cout << "         상영관 메인 메뉴   " << endl;
    cout << "------------------------------------" << endl;
    cout << "1.  스릴러  영화 1관" << endl;
    cout << "2.  액션   영화 2관" << endl;
    cout << "3.   SF   영화 3관" << endl;
    cout << "9.  통계   관리" << endl;
    cout << endl << "선택(1~3) 그외 종료 : ";

    int select;       // 사용자가 선택한 번호를 저장할 공간
    cin >> select;    // 선언한 공간에 사용자가 입력한 번호 저장
    cout << endl;     // 가독성을 위해 다음 줄로 가는 코드

    switch (select) {   // 사용자가 입력한 번호에 따라 다른 함수 실행
    case 1:        // 1번 입력 시
        return pThrillerScreen;   // 스릴러 영화로 이동
    case 2:        // 2번 입력 시
        return pActionScreen;     // 액션 영화로 이동
    case 3:        // 3번 입력 시
        return pSFScreen;  // SF 영화로 이동
    case 9:         // 9번 입력 시
        Manage();   // 관리자 모드 함수 실행
        return NULL;       
    default:       // 그 외 번호 입력 시
        return NULL;            // 프로그램 종료
    }

}

void TUKoreaTBox::Manage() {        // 관리자 모드 
    string PWD;         // 입력한 비밀번호를 저장할 공간
    Statistics sta;         // Statistics 형식 선언
    int totalcount = 0;     // 총 티켓 판매량 0으로 초기값 저장

    cout << "------------------------------------" << endl;
    cout << "             관리자 메뉴" << endl;
    cout << "------------------------------------" << endl;
    cout << "관리자 비밀번호 입력 : ";
    cin >> PWD;     // 입력한 관리자 비밀번호 저장

    if (PWD == TICKETBOX_MANAGER_PWD) {     // 기존에 저장된 비밀번호와 입력한 비밀번호가 같을 때
        totalcount += sta.totalSalesCount(pThrillerScreen);     // 스릴려 상영관에서 판매된 티켓당 totalcount 하나씩 증가
        totalcount += sta.totalSalesCount(pActionScreen);       // 액션 상영관에서 판매된 티켓당 totalcount 하나씩 증가
        totalcount += sta.totalSalesCount(pSFScreen);           // SF 상영관에서 판매된 티켓당 totalcount 하나씩 증가

        cout << endl;
        cout << "1. 스릴러 상영관 결제금액 : " << sta.totalRevenue(pThrillerScreen) << " 원" << endl;  // 스릴러 상영관 결제 금액 출력
        cout << "2. 액션 상영관 결제금액 : " << sta.totalRevenue(pActionScreen) << " 원" << endl;      // 액션 상영관 결제 금액 출력
        cout << "3. SF 상영관 결제금액 : " << sta.totalRevenue(pSFScreen) << " 원" << endl;            // SF 상영관 결제 금액 출력
        cout << "4. 전체 티켓 판매량 : " << totalcount << " 장" << endl;        // 증가한 totalcount를 전체 티켓 판매량으로 출력
    }
    else {      // 저장된 비밀번호와 입력한 비밀번호가 다를경우
        cout << endl;  
        cout << "잘못된 비밀번호 입니다." << endl;       // 비밀번호가 잘못되었다고 출력
    }
}