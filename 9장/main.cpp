#include<iostream>
#include "Shape.h"
#include "Circle.h"
#include "Rect.h"
#include "Line.h"
using namespace std;

int main() {
	Shape* pStart = NULL;
	Shape* pLast;
	pStart = new Circle();	// ó���� �� ������ ����
	pLast = pStart;

	pLast = pLast->add(new Rect());		// �簢�� ����
	pLast = pLast->add(new Circle());	// �� ����
	pLast = pLast->add(new Line());		// �� ����
	pLast = pLast->add(new Rect());		// �簢�� ����

	// ���� ����� ��� ������ ȭ�鿡 �׸�
	Shape* p = pStart;
	while (p != NULL) {
		p->paint();		// ������ �׸��� �׷���
		p = p->getNext();
	}
	// ���� ����� ��� ������ ������
	p = pStart;
	while (p != NULL) {
		// ���� ���� �ּ� ���
		Shape* q = p->getNext();
		// �⺻ Ŭ������ ���� �Ҹ��� ȣ��
		delete p;

		p = q;		// ���� ���� �ּҸ� p�� ����
	}
}