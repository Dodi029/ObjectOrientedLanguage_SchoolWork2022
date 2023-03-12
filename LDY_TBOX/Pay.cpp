#include <iostream>
#include <string>
#include "pay.h"
using namespace std;

int CardPay::charge(int amount) {		// ī��� ������ ���
	int cardpay = amount + (amount * CREDIT_CARD_INTEREST_RATE);	// ī�� �����Ḹŭ ���� ����
	return cardpay;		// ������ ���� ����
}

int BankTransfer::charge(int amount) {		// ���� ��ü�� ������ ���
	int banktransfer = amount + (amount * BANK_TRANSFER_INTEREST_RATE);		// ���� ��ü ���� �����θ�ŭ ���� ����
	return banktransfer;		// ������ ���� ����
}

int MobilePay::charge(int amount) {		// ����Ϸ� ������ ���
	int mobilepay = amount + (amount * MOBILE_PHONE_INTEREST_RATE);		// ����� ���� �����Ḹŭ ���� ����
	return mobilepay;		// ������ ���� ����
}