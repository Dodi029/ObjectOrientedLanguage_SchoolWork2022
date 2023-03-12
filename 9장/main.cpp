#include<iostream>
#include "Shape.h"
#include "Circle.h"
#include "Rect.h"
#include "Line.h"
using namespace std;

int main() {
	Shape* pStart = NULL;
	Shape* pLast;
	pStart = new Circle();	// 처음에 원 도형을 생성
	pLast = pStart;

	pLast = pLast->add(new Rect());		// 사각형 생성
	pLast = pLast->add(new Circle());	// 원 생성
	pLast = pLast->add(new Line());		// 선 생성
	pLast = pLast->add(new Rect());		// 사각형 생성

	// 현재 연결된 모든 도형을 화면에 그림
	Shape* p = pStart;
	while (p != NULL) {
		p->paint();		// 각각의 그림이 그려짐
		p = p->getNext();
	}
	// 현재 연결된 모든 도형을 삭제함
	p = pStart;
	while (p != NULL) {
		// 다음 도형 주소 기억
		Shape* q = p->getNext();
		// 기본 클래스의 가상 소멸자 호출
		delete p;

		p = q;		// 다음 도형 주소를 p에 저장
	}
}