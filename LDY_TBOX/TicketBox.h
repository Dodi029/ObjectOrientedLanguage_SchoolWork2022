#ifndef TICKETBOX_H
#define TICKETBOX_H
#define TICKETBOX_MANAGER_PWD "admin"

class TicketBox {
public:
	virtual Screen* selectMenu() { return NULL; } // �󿵰� ���� �޴� ( 1��, 2��, 3��)
	void Initialize() {}
};
class TUKoreaTBox : public TicketBox {
	ThrillerScreen* pThrillerScreen;
	ActionScreen* pActionScreen;
	SFScreen* pSFScreen;
public:
	TUKoreaTBox();
	~TUKoreaTBox();
	Screen* selectMenu();
	void Initialize();
	void Manage();
};

#endif
