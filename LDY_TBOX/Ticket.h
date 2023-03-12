#ifndef TICKET_H
#define TICKET_H

#define SEAT_EMPTY_MARK '-'         // ����ִ� �¼��� '-'�� ǥ��
#define SEAT_RESERVED_MARK 'R'      // ����� �¼��� 'R'�� ǥ��
#define SEAT_COMPLETION_MARK '$'    // ������ �¼��� '$'�� ǥ��

class Ticket {
	int nRow; // �¼� ��
	int nCol; // �¼� ��
	char charCheck; // ���� ����
	int nReservedID; // ���� ��ȣ
	int nPayAmount = 0; // ���� �ݾ�
	int nPayMethod; // ���� ����
public:
	Ticket() {}
	void setCheck(char check) { charCheck = check; }
	char getCheck() { return charCheck; }
	// �¼� ��ȣ ����
	void setSeat(int row, int col) { nRow = row; nCol = col; }
	// �¼� ���� ��ȣ ����
	void setReservedID(int reserved) { nReservedID = reserved; }
	// �¼� ���� ��ȣ �б�
	int getReservedID() { return nReservedID; }
	void setPayAmount(int amount) { nPayAmount = amount; }
	int getPayAmount() { return nPayAmount; }
	void setPayMethod(int method) { nPayMethod = method; }
};

#endif