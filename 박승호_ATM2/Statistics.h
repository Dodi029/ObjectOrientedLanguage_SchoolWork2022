#pragma once
#ifndef STATISTICS_H
#define STATISTICS_H

#include <iostream>
#include <string>
#include "ATMachine.h"
#include "Account.h"
#include "Statistics.h"

class Account;

class Statistics {
public:
	static int sum(Account* pArray, int size);
	static int average(Account* pArray, int size);
	static int max(Account* pArray, int size);
	static void sort(Account* pArray, int size);
};

#endif