#pragma once
#ifndef TICKETBOX_H
#define TICKETBOX_H
#define TICKETBOX_MANAGER_PWD "tnsgusdk"

class TicketBox 
{
public:
	virtual Screen* selectMenu() { return NULL; } // �󿵰� ���� �޴� ( 1��, 2��, 3��)
	void Initialize() {}
};

class KpuTicketBox : public TicketBox {
	EuropeScreen* pEuropeScreen;
	AsiaScreen* pAsiaScreen;
	PremiumScreen* pPremiumScreen;

public:
	KpuTicketBox();
	~KpuTicketBox();
	Screen* selectMenu();
	void Initialize();

	void Manage();
};
#endif


