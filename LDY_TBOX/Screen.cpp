#include <iostream>
#include <string>
#include "Screen.h"
#include "pay.h"
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

void Screen::showMovieMenu() {       // 사용자가 선택한 영화의 메뉴 출력
    cout << "------------------------" << endl;
    cout << "     영화 메뉴 - " << this->strMovieName << endl;     // 선택한 영화 이름을 출력하도록 함
    cout << "------------------------" << endl;
    cout << "1. 상영 영화 정보" << endl;      // 1번 영화 메뉴 출력
    cout << "2. 좌석 예약 현황" << endl;      // 2번 좌석 정보 출력
    cout << "3. 좌석 예약 하기" << endl;      // 3번 예약 하기 출력
    cout << "4. 좌석 예약 취소" << endl;      // 4번 좌석 예약 취소
    cout << "5. 결제 하기" << endl;           // 5번 결제하기 실행
    cout << "7. 메인 메뉴 이동" << endl;      // 7번 메인 메뉴 이동
}

void ThrillerScreen::showMovieInfo() {    // 스릴러 영화 정보 출력
    cout << "------------------------------------" << endl;
    cout << "    [ " << this->strMovieName << " ]" << endl;     // 유렵 영화 제목 출력
    cout << "------------------------------------" << endl;
    cout << "영화관 : 스릴러 영화 1관" << endl;    // 영화관 정보 출력
    cout << "주인공 : 휴 잭맨, 크리스찬 베일, 스칼렛 요한슨" << endl;      // 영화 주인공 출력
    cout << "줄거리 : 순간이동 마술로 런던에서 대대적으로 인기를 끌던 마술사 '위대한 단톤' 앤지어가 물탱크에 빠뜨려져 살해당하는 사건이 발생한다." << endl;
    cout << "사건 현장에서 발견되어 유력한 용의자로 지목된 건 라이벌 마술사이자 순간 이동 마술로 이전에 유명세를 얻었다가 지금은 앤지어에게 자리를 내준 보든." << endl;
    cout << "재판 결과 보든은 투옥되어 사형 선고를 받고, 자신을 콜드로 경의 대리인이라고 밝힌 남자가 찾아와 고아원에 가게 된 그의 딸을 돌봐주는 대가로 그의 순간이동 마술의 비법을 알려 달라 청한다." << endl;
    cout << "보든은 그에게서 앤지어가 남긴 일기를 건네받아 읽게 되고, 숨겨져 있던 진실이 드러나는데..." << endl;      // 영화 줄거리 출력
    cout << "가격 : " << this->nTicketPrice << "원" << endl;      // 저장된 영화 가격 출력
}

void ActionScreen::showMovieInfo() {      // 액션 영화 정보 출력
    cout << "------------------------------------" << endl;
    cout << "    [ " << this->strMovieName << " ]" << endl;     // 아시아 영화 제목 출력
    cout << "------------------------------------" << endl;
    cout << "영화관 : 액션 영화 2관" << endl;     // 영화관 정보 출력
    cout << "주인공 : 크리스찬 베일, 히스 레저, 에런 엑하트" << endl;      // 영화 주인공 출력
    cout << "줄거리 : 살아남기 위해 발버둥치던 범죄 조직들은 배트맨을 제거하기 위해 광기어린 악당 ‘조커’를 끌어들이고" << endl;
    cout << "정체를 알 수 없는 조커의 등장에 고담시 전체가 깊은 혼돈 속으로 빠져든다." << endl;
    cout << "급기야 배트맨을 향한 강한 집착을 드러낸 조커는 그가 시민들 앞에 정체를 밝힐 때까지" << endl;
    cout << "매일 새로운 사람들을 죽이겠다 선포하고 배트맨은 사상 최악의 악당 조커를 막기 위해 자신의 모든 것을 내던진 마지막 대결을 준비하게 된다." << endl;         // 영화 줄거리 출력
    cout << "가격 : " << this->nTicketPrice << "원" << endl;      // 저장된 영화 가격 출력
}

void SFScreen::showMovieInfo() {      // SF 영화 정보 출력
    cout << "------------------------------------" << endl;
    cout << "    [ " << this->strMovieName << " ]" << endl;     // 프리미엄 영화 제목 출력
    cout << "------------------------------------" << endl;
    cout << "영화관 : SF 영화 3관" << endl;      // 영화관 정보 출력
    cout << "주인공 : 클라이브 오언,아만다 사이프리드,콜므 포어" << endl;      //영화 주인공 출력
    cout << "줄거리 : 비밀을 지우는 것이 업인 익명의 여자 '아논'. 그녀 주변에서 연쇄 살인이 발생한다." << endl;
    cout << "모두가 연결되어 오히려 취약한 미래. 범인을 잡으려면 눈에 보이는 것을 믿지 마라." << endl;         // 영화 줄거리 출력
    cout << "가격 : " << this->nTicketPrice << "원" << endl;      // 저장된 영화 가격 출력
}

void Screen::showSeatMap() {            // 좌석 현황 출력 
    cout << "	[ 좌석 예약 현황 ]" << endl;
    cout << "	";

    for (int i = 0; i < this->nColMax; i++) {       // 열 정보 출력
        cout << "[" << i + 1 << "] ";       // i=0부터 시작하기 때문에 i+1을 통해 숫자를 맞춰줌
    }
    cout << endl;

    for (int j = 0; j < this->nRowMax; j++) {       // 행 정보 출력
        cout << "[" << j + 1 << "] ";       // j=0부터 시작하기 때문에 j+1을 통해 숫자를 맞춰줌
        cout << "	";

        for (int k = 0; k < this->nColMax; k++) {   // 현재 행에 열의 수만큼 좌석 생성
            cout << "[" << pSeatArray[j][k].getCheck() << "] ";     // 좌석 정보 저장
        }
        cout << endl;
    }
}

void Screen::reserveTicket() {          // 좌석 예악 함수
    int row=0;      // 행을 저장할 공간
    int col=0;      // 열을 저장할 공간

    cout << "   [ 좌석 예약 ]" << endl;
    cout << "좌석 행 번호 입력 (1 - " << nRowMax << ") : ";    // 1부터 영화관의 행 수만큼 출력
    cin >> row;     // 입력한 행 번호 저장
    cout << "좌석 열 번호 입력 (1 - " << nColMax << ") : ";    // 1부터 영화관의 열 수만큼 출력
    cin >> col;     // 입력한 열 번호 저장

    if (row < nRowMax && col < nColMax) {       // 입력한 행과 열이 존재할 때
        cout << endl;
        cout << "행[" << row << "] " << "열[" << col << "] " << nCurrentReservedId << " 예약 번호로 접수되었습니다." << endl;
        //  예약한 정보를 사용자에게 출력
        row = row - 1;      // 좌석 현황에서 행이 0부터 시작하기 때문에 -1을 하여 숫자를 맞춰줌
        col = col - 1;      // 좌석 현황에서 열이 0부터 시작하기 때문에 -1을 하여 숫자를 맞춰줌

        pSeatArray[row][col].setSeat(row, col);     // 예약한 좌석 정보 저장
        pSeatArray[row][col].setCheck(SEAT_RESERVED_MARK);      // 예약한 좌석을 'R' 표시
        pSeatArray[row][col].setReservedID(nCurrentReservedId); // 예약 번호 출력 후 이 번호를 저장
        nCurrentReservedId++;       // 예약 번호 증가
        pSeatArray[row][col].getCheck();        // 예약한 정보 확인
    }
    else {      // 그 외의 경우
        cout << endl;
        cout << "잘못된 좌석입니다." << endl;   // 잘못된 값이라고 출력
        
    }
}

Ticket* Screen::checkReservedID(int id) {       // 예약 번호 확인하는 함수
    for (int i = 0; i < nRowMax; i++) {     // 영화의 최대 행 수만큼 반복하면서
        for (int j = 0; j < nColMax; j++) {     // 영화의 최대 열 수만큼 반복
            if (pSeatArray[i][j].getReservedID() == id) {       // 그 중 예약 번호와 같은 id인 행과 열 정보를 저장
                return pSeatArray[i] + j;       // 저장한 정보를 리턴
            }
        }
    }
    return NULL;        // 함수가 끝나면 아무것도 리턴하지 않음
}

void Screen::cancelReservation() {      // 예약 취소하는 함수

    int reservationNumber = 0;      // 입력한 예약 번호를 저장할 공간
    cout << endl << "   [ 좌석 예약 취소 ]" << endl;
    cout << "예약 번호 입력 : ";
    cin >> reservationNumber;       // 입력한 예약 번호를 저장

    if (checkReservedID(reservationNumber)->getCheck() == SEAT_RESERVED_MARK) {     // 만약 예약 번호의 행과 열이 있는 곳에 예약 표시가 있다면
        cout << endl;       // 가독성을 위해 
        cout << reservationNumber << "번 예약 번호가 취소 처리되었습니다." << endl;    // 사용자에게 예약이 취소되었음을 출력
        checkReservedID(reservationNumber)->setCheck(SEAT_EMPTY_MARK);      // 취소한 자리에 예약 가능 표시
        checkReservedID(reservationNumber)->getCheck();     // 자리 정보 저장
    }
    
    else if (checkReservedID(reservationNumber)->getCheck() == SEAT_COMPLETION_MARK) {
        cout << endl << "이미 결제하신 좌석은 취소가 불가합니다." << endl;
    }
    else {      // 그 외의 경우
        cout << endl << "예약 번호가 잘못되었습니다." << endl;      // 잘못되었다고 출력
    }
    
}

void Screen::Payment() {        // 결제하는 함수
    Pay* pay = NULL;        // pay 초기화
    int reservationNumber;  // 입력한 예약 번호를 저장할 공간
    int select;             // 선택한 번호를 저장할 공간
    int money, payment;   
    string phoneNum, name1;
    string accountNum, name2;
    string cardNum, name3;

    cout << "   [ 좌석 예약 결제 ]" << endl;
    cout << "예약 번호 입력 : "; 
    cin >> reservationNumber;       // 예약 번호를 저장함

    if (checkReservedID(reservationNumber)->getCheck() == SEAT_RESERVED_MARK) {     // 예약 번호가 예약표시가 있는 곳일 때 
        cout << "------------------------------------" << endl;
        cout << "             결제 방식 선택          " << endl;
        cout << "------------------------------------" << endl;
        cout << "1. 모바일 결제" << endl;
        cout << "2. 은행 이체 결제" << endl;
        cout << "3. 카드 결제" << endl;
        cout << "결제 방식(1~3) : ";
        cin >> select;      // 선택한 번호 저장

        switch (select) {   // 선택한 번호에 따라 다른 함수 실행

        case 1:	// 모바일 결제를 선택한 경우
            cout << "         [ 모바일 결제 ]        " << endl;
            cout << "핸드폰 전화번호 입력(11자리수) : ";
            cin >> phoneNum;     // 입력한 전화번호 저장
            cout << "이름 : "; 
            cin >> name1;    // 이름 저장
            if (phoneNum.length() == 11) {	//입력한 번호가 11자리 일 때 

                pay = new MobilePay(MOBILE_PHONE_INTEREST_RATE);    // 모바일 결제 수수료만큼 계산하여 동적 생성
                cout << "모바일 결제가 완료되었습니다. : ";
                payment = MOBILE_PHONE_PAYMENT;

            }
            else {						//입력한 번호가 11자리가 아닐 때
                cout << endl;
                cout << "전화번호를 다시 입력해 주세요." << endl;    // 전화번호 다시 입력받기
            }
            break;

        case 2:							//은행 이체 결제를 선택한 경우
            cout << "      [ TUKorea 은행 결제 ]      " << endl;
            cout << "은행 번호 입력(12자리수) : "; 
            cin >> accountNum;     // 
            cout << "이름 : ";
            cin >> name2;

            if (accountNum.length() == 12) {	//은행 번호가 12자리일 경우

                pay = new BankTransfer(BANK_TRANSFER_INTEREST_RATE);
                cout << "TUKorea 은행 결제가 완료되었습니다. : ";
                payment = BANK_TRANSFER_PAYMENT;

            }
            else {						//은행 번호가 12자리가 아닐경우
                cout << endl;
                cout << "은행 번호를 다시 입력해 주세요." << endl;
            }
            break;

        case 3:							//신용카드 결제를 선택한 경우
            cout << "        [ 신용카드 결제 ]        " << endl;
            cout << "카드 번호 입력(12자리수) : ";
            cin >> cardNum;
            cout << "이름 : ";
            cin >> name3;
            if (cardNum.length() == 12) {	//카드번호가 12자리일 경우

                pay = new CardPay(CREDIT_CARD_INTEREST_RATE);
                cout << "카드 결제가 완료되었습니다. : ";
                payment = CREDIT_CARD_PAYMENT;
            }
            else {						//카드번호가 12자리가 아닐경우
                cout << endl;
                cout << "카드 번호를 다시 입력해 주세요." << endl;
            }
            break;

        default:    // 그 외의 번호를 입력한 경우
            break;
        }
        if (pay != NULL) {			//pay가 NULL이 아닐경우
            cout << pay->charge(nTicketPrice) << endl;      // 가격 출력

            checkReservedID(reservationNumber)->setCheck(SEAT_COMPLETION_MARK);
            checkReservedID(reservationNumber)->getCheck();
            checkReservedID(reservationNumber)->setPayAmount(pay->charge(nTicketPrice));
            checkReservedID(reservationNumber)->getPayAmount();
            checkReservedID(reservationNumber)->setPayMethod(payment);
        }
        else {					// 입력한 예약번호가 존재하지 않는 경우
            cout << endl;
            cout << "입력하신 예약번호가 없습니다." << endl;
        }

    }

}