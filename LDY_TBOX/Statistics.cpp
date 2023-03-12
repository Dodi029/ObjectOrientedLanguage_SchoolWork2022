#include <iostream>
#include <string>
#include "Statistics.h"
using namespace std;

int Statistics::totalRevenue(Screen* pScreen) {     // 총 수입을 계산하는 함수
    int sum = 0;        // 초기값 = 0
    Ticket** ticket = pScreen->getTicketArray();        // 이중포인터를 통해 pScreen->getTicketArray에 접근
    for (int i = 0; i < pScreen->getRowMax(); i++) {        // 반복문을 통해 영화의 최대 행 수 만큼
        for (int j = 0; j < pScreen->getColMax(); j++) {        // 영화의 최대 열 만큼 반복
            sum += ticket[i][j].getPayAmount();    // 결제된 양을 모두 더함
        }
    }
    return sum;     // 결제된 총 양(금액)을 리턴
}

int Statistics::totalSalesCount(Screen* pScreen)        // 총 판매한 티켓수를 구하는 함수
{
    int count = 0;      // 초기값 0
    Ticket** ticket = pScreen->getTicketArray();        // 이중포인터를 통해 pScreen->getTicketArray()에 접근
    for (int i = 0; i < pScreen->getRowMax(); i++) {        // 반복문을 통해 영화의 최대 행 수만큼
        for (int j = 0; j < pScreen->getColMax(); j++) {        // 영화의 최대 열 만큼 반복
            if (ticket[i][j].getCheck() == SEAT_COMPLETION_MARK) {    // 포인터가 가리킨 좌석이 결제된 표시일 때
                count++;        // 개수를 늘려 총 몇 자리가 결제되어 몇 표가 팔렸는지 확인
            }
        }
    }
    return count;       // 총 티켓 수를 리턴
}