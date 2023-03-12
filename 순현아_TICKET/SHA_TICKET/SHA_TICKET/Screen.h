#pragma once
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
	Screen(string name, int price, int r, int c);
	~Screen();
	void showSeatMap(); // �¼� ���� ���� ������ ����
	virtual void showMovieMenu(); // ��ȭ ���� �޴�
	virtual void showMovieInfo() = 0; // ��ȭ �Ұ� ����

	void reserveTicket(); // �¼� �����ϱ�

	void cancelReservation(); // �¼� ���� ����ϱ�

	int getTicketPrice() { return nTicketPrice; }
	void Payment(); // �����ϱ�

	int getRowMax() { return nRowMax; }
	int getColMax() { return nColMax; }
	Ticket** getTicketArray() { return pSeatArray; }

};

class EuropeScreen : public Screen {
public:
	EuropeScreen(string name, int price, int r, int c) : Screen(name, price, r, c) {}
	void showMovieInfo();
};

class AsiaScreen : public Screen {
public:
	AsiaScreen(string name, int price, int r, int c) : Screen(name, price, r, c) {}
	void showMovieInfo();
};

class PremiumScreen : public Screen {
public:
	PremiumScreen(string name, int price, int r, int c) : Screen(name, price, r, c) {}
	void showMovieInfo();
};
#endif

