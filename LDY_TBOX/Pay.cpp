#include <iostream>
#include <string>
#include "pay.h"
using namespace std;

int CardPay::charge(int amount) {		// 카드로 결제할 경우
	int cardpay = amount + (amount * CREDIT_CARD_INTEREST_RATE);	// 카드 수수료만큼 가격 증가
	return cardpay;		// 증가한 가격 리턴
}

int BankTransfer::charge(int amount) {		// 은행 이체로 결제할 경우
	int banktransfer = amount + (amount * BANK_TRANSFER_INTEREST_RATE);		// 은행 이체 결제 수수로만큼 가격 증가
	return banktransfer;		// 증가한 가격 리턴
}

int MobilePay::charge(int amount) {		// 모바일로 결제할 경우
	int mobilepay = amount + (amount * MOBILE_PHONE_INTEREST_RATE);		// 모바일 결제 수수료만큼 가격 증가
	return mobilepay;		// 증가한 가격 리턴
}