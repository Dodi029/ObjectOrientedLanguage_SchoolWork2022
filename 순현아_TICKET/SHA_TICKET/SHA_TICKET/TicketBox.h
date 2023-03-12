#pragma once
#ifndef TICKETBOX_H
#define TICKETBOX_H
#define TICKETBOX_MANAGER_PWD "tnsgusdk"

class TicketBox 
{
public:
	virtual Screen* selectMenu() { return NULL; } // 상영관 선택 메뉴 ( 1관, 2관, 3관)
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


