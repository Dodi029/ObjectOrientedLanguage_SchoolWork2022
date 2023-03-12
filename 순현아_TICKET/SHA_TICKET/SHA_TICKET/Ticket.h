#pragma once
#ifndef TICKET_H
#define TICKET_H
#define SEAT_EMPTY_MARK '-'
#define SEAT_RESERVED_MARK 'R'
#define SEAT_COMPLETION_MARK '$'

class Ticket {
	int nRow; // 좌석 행
	int nCol; // 좌석 열
	char charCheck; // 예약 여부
	int nReservedID; // 예약 번호
	int nPayAmount; // 결제 금액
	int nPayMethod; // 결제 수단
public:
	Ticket()
	{
		this->nRow = 0;
		this->nCol = 0;
		this->charCheck = ' ';
		this->nReservedID = 0;
		this->nPayAmount = 0;
		this->nPayMethod = 0;
	}
	void setCheck(char check) { charCheck = check; }
	char getCheck() { return charCheck; }

	// 좌석 번호 저장
	void setSeat(int r, int c) { nRow = r; nCol = c; }
	// 좌석 예약 번호 저장
	void setReservedID(int reserved) { nReservedID = reserved; }

	// 좌석 예약 번호 읽기
	int getReservedID() { return nReservedID; }

	void setPayAmount(int amount) { nPayAmount = amount; }
	int getPayAmount() { return nPayAmount; }
	void setPayMethod(int method) { nPayMethod = method; }
};
#endif


