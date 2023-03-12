#pragma once
#ifndef TICKET_H
#define TICKET_H
#define SEAT_EMPTY_MARK '-'
#define SEAT_RESERVED_MARK 'R'
#define SEAT_COMPLETION_MARK '$'

class Ticket {
	int nRow; // �¼� ��
	int nCol; // �¼� ��
	char charCheck; // ���� ����
	int nReservedID; // ���� ��ȣ
	int nPayAmount; // ���� �ݾ�
	int nPayMethod; // ���� ����
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

	// �¼� ��ȣ ����
	void setSeat(int r, int c) { nRow = r; nCol = c; }
	// �¼� ���� ��ȣ ����
	void setReservedID(int reserved) { nReservedID = reserved; }

	// �¼� ���� ��ȣ �б�
	int getReservedID() { return nReservedID; }

	void setPayAmount(int amount) { nPayAmount = amount; }
	int getPayAmount() { return nPayAmount; }
	void setPayMethod(int method) { nPayMethod = method; }
};
#endif


