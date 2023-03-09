#pragma once
#ifndef SCREEN_H
#define SCREEN_H
#include <string>
#include "Ticket.hpp"
using namespace std;

class Screen {
protected:
	int nTicketPrice;
	int nRowMax, nColMax;
	int nCurrentReservedid;
	Ticket** pSeatArray;
	string strMovieName;
public:
	Screen(string name, int price, int row, int col);
	~Screen();
	void showSeatMap();
	virtual void showMovieMenu();
	virtual void showMovieInfo() = 0;
};

class EuropeScreen : public Screen {
public:
	EuropeScreen(string name, int price, int row, int col) : Screen(name, price, row, col) {};
	void showMovieInfo();
		
};

class AsiaScreen : public Screen {
public:
	AsiaScreen(string name, int price, int row, int col) : Screen(name, price, row, col) {};
	void showMovieInfo();
};

class PremiumScreen : public Screen {
public:
	PremiumScreen(string name, int price, int row, int col) : Screen(name, price, row, col) {};
	void showMovieInfo();
};
#endif // ! SCREEN_H
