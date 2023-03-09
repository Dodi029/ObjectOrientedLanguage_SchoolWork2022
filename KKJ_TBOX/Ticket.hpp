#pragma once
#ifndef TICKET_H
#define TICKET_H

#define SEAT_EMPTY_MARK '-'
#define SEAT_RESERVED_MARK 'R'
#define SEAT_COMPLETION_MARK '$'

class Ticket {
	int nRow;
	int nCol;
	char charCheck;
	int nReservedID;
	int nPayAmount;
	int nPayMethod;
public:
	Ticket(){
		nRow;
		nCol;
		charCheck;
		nReservedID;
		nPayAmount;
		nPayMethod;
	}
	void setCheck(char check) { charCheck = check; }
	char getCheck() { return charCheck; }
};
#endif // !TICKET_H
