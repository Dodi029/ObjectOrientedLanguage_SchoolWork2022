#include <iostream>
#include "Screen.h"
#include "TicketBox.h"
#include "Statistics.h"
using namespace std;

KpuTicketBox::KpuTicketBox()
{
	pEuropeScreen = NULL;
	pAsiaScreen = NULL;
	pPremiumScreen = NULL;
}

KpuTicketBox::~KpuTicketBox()
{
	delete pEuropeScreen;
	delete pAsiaScreen;
	delete pPremiumScreen;
}

// ��ũ�� ��ü ����
void KpuTicketBox::Initialize() {
	// Screen(��ȭ����, Ƽ�ϰ���, �¼�(nRowMax), �¼�(nColMax))
	pEuropeScreen = new EuropeScreen("���� �� ������", 10000, 10, 10);
	pAsiaScreen = new AsiaScreen("�пպ���", 12000, 10, 10);
	pPremiumScreen = new PremiumScreen("������ �̽�������", 30000, 6, 6);
}

Screen* KpuTicketBox :: selectMenu()
{
	int menu = 0;
	cout << "-----------------------------" << endl;
	cout << "    �󿵰� ���� �޴�" << endl;
	cout << "-----------------------------" << endl;
	cout << "1.   ����   ��ȭ 1��" << endl;
	cout << "2.  �ƽþ�  ��ȭ 2��" << endl;
	cout << "3. �����̾� ��ȭ 3��" << endl;
	cout << "9.   ���   ����" << endl << endl;
	cout << " ����(1~3,9) �׿� ���� : ";
	cin >> menu;

	switch (menu)
	{
	case 1:
		return pEuropeScreen; 
	case 2:
		return pAsiaScreen;
	case 3:
		return pPremiumScreen;
	case 9:
		Manage();
		return NULL;
	default:
		return NULL;
	}
}

void KpuTicketBox::Manage()
{
	string PWD;
	Statistics sta;
	int totalcount=0;
	cout << "-----------------------------" << endl;
	cout << "        ������ �޴�" << endl;
	cout << "-----------------------------" << endl;
	cout << "������ ��й�ȣ �Է� : ";
	cin >> PWD ;

	if (PWD == TICKETBOX_MANAGER_PWD)
	{
		totalcount += sta.totalCount(pEuropeScreen);
		totalcount += sta.totalCount(pAsiaScreen);
		totalcount += sta.totalCount(pPremiumScreen);
		cout << endl;
		cout << "1. ������ȭ �󿵰� �����ݾ� : " << sta.totalSum(pEuropeScreen) << " ��"<< endl;
		cout << "2. �ƽþƿ�ȭ �󿵰� �����ݾ� : " << sta.totalSum(pAsiaScreen) << " ��" << endl;
		cout << "3. �����̾���ȭ �󿵰� �����ݾ� : " << sta.totalSum(pPremiumScreen) << " ��" << endl;
		cout << "4. ��ü Ƽ�� �Ǹŷ� : " << totalcount << " ��" << endl;
	}
	else
	{
		cout << endl;
		cout << "�����ڰ� �ƴմϴ�" << endl;
	}

}