#include <iostream>
#include <string>
#include "Pay.h"

using namespace std;

int CardPay::charge(int amount)
{
	int cardpay = amount + (amount * interest);
	return cardpay;
}

int BankTransfer::charge(int amount)
{
	int banktransfer = amount + (amount * interest);
	return banktransfer;
}

int MobilePay::charge(int amount)
{
	int mobilepay = amount + (amount * interest);
	return mobilepay;
}
