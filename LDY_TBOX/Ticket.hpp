#ifndef TICKET_H
#define TICKET_H

#define SEAT_EMPTY_MARK '-'         // 비어있는 좌석은 '-'로 표시
#define SEAT_RESERVED_MARK 'R'      // 예약된 좌석은 'R'로 표시
#define SEAT_COMPLETION_MARK '$'    // 결제된 좌석은 '$'로 표시

class Ticket {
   int nRow; // 좌석 행
   int nCol; // 좌석 열
   char charCheck; // 예약 여부
   int nReservedID; // 예약 번호
   int nPayAmount; // 결제 금액
   int nPayMethod; // 결제 수단
public:
   Ticket() {}
   void setCheck(char check) { charCheck = check; }
   char getCheck() { return charCheck; }
};

#endif