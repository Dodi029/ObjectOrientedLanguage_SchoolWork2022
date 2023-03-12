#pragma once
#include <iostream>
#include "Account.h"
#ifndef STATISTCIS_H
#define STATISTCIS_H

class Statistics {
public:
	static int sum(Account* pArray, int size); // °èÁÂ ÀÜ°í ÃÑÇÕ
	static int average(Account* pArray, int size); // °èÁÂ ÀÜ°í Æò±Õ
	static int max(Account* pArray, int size); // °èÁÂ ÀÜ°í ÃÖ°í
	static void sort(Account* pArray, int size); // ³»¸²Â÷¼ø Á¤·Ä
};

#endif
