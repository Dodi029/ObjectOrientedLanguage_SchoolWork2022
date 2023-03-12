#ifndef STATISTCIS_H
#define STATISTCIS_H
#include "Screen.h"

class Statistics {
public: // Static 함수 구현
	static int totalRevenue(Screen* pScreen);		// 총 수입을 저장할 함수
	static int totalSalesCount(Screen* pScreen);		// 총 티켓 판매량을 저장할 함수
};

#endif