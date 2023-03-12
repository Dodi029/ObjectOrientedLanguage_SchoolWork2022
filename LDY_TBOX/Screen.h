#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include "Ticket.h"

using namespace std;
class Screen {
protected:
	int nTicketPrice; // Ƽ�� ����
	int nRowMax, nColMax; // �¼� ��� �� �ִ� ��
	int nCurrentReservedId = 100; // �߱޵� ������ ���� ��ȣ
	Ticket** pSeatArray; // ��ũ�� �¼��� ���� Ƽ�� �迭
	string strMovieName; // ��ũ�� ������ ��ȭ ����
	Ticket* checkReservedID(int id); // ���� ��ȣ Ȯ��
public:
	Screen(string name, int price, int row, int col);
	~Screen();
	void showSeatMap(); // �¼� ���� ���� ������ ����
	virtual void showMovieMenu(); // ��ȭ ���� �޴�
	virtual void showMovieInfo() = 0; // ��ȭ �Ұ� ����
	void reserveTicket();				// �¼� �����ϱ�
	void cancelReservation(); // �¼� ���� ����ϱ�
	int getTicketPrice() { return nTicketPrice; }
	void Payment(); // �����ϱ�
	int getRowMax() { return nRowMax; }		// �࿡ �ִ� ��� ��
	int getColMax() { return nColMax; }		// ���� �ִ� ��� ��
	Ticket** getTicketArray() { return pSeatArray; }

};
class ThrillerScreen : public Screen {      // �Ļ�Ŭ���� ����
public:
	ThrillerScreen(string name, int price, int row, int col) : Screen(name, price, row, col) {}    // ��ȭ�� �Ļ��Լ� ����
	void showMovieInfo();		// ��ȭ ����
};
class ActionScreen : public Screen {		// �Ļ�Ŭ���� ����
public:
	ActionScreen(string name, int price, int row, int col) : Screen(name, price, row, col) {}
	void showMovieInfo();
};
class SFScreen : public Screen {		// �Ļ� Ŭ���� ����
public:
	SFScreen(string name, int price, int row, int col) : Screen(name, price, row, col) {}
	void showMovieInfo();
};


#endif
