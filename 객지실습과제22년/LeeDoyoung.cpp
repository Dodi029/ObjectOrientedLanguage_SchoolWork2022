#include<iostream>
using namespace std;


class Bomb {
	string title;
public:
	Bomb() {}
	Bomb(string title) { this->title = title; }
	string getTitle() { return title; }
};

class Weapon {			// ���� �����Լ� ����
public:
	virtual void load(Bomb bomb) = 0;
	virtual void use() = 0;
};

class Shop {
public:
	virtual Weapon* selectitem() = 0;
};


class Tank :public Weapon{		// ���� �����Լ� ����
public:
	void load(Bomb bomb) { 
		cout << "��ũ " << bomb.getTitle() << " �� ������" << endl; }		// �������̵�
	void use() { cout << "��ũ ����ź(hydrogen) �� �߻���" << endl; }		// �������̵�
};

class Aircraft :public Weapon {		// ���� �����Լ� ����
public:
	void load(Bomb bomb) {
		cout << "������ " << bomb.getTitle()<< " �� ������" << endl;}		// �������̵�
	void use() { cout << "������ ����ź(hydrogen) �� �߻���" << endl; }	// �������̵�
};

class Rocket : public Weapon {		// ���� �����Լ� ����
public:
	void load(Bomb bomb) {
		cout << "�̻��� " << bomb.getTitle() << " �� ������" << endl;}		// �������̵�
	void use() { cout << "�̻��� ����ź(hydrogen) �� �߻���" << endl; }		// �������̵�
};

class BattleShop : public Shop {
public:
	Weapon* selectitem() {
		cout << endl;
		cout << "----------------------" << endl;
		cout << "	 ���� ������ ����	   " << endl;
		cout << "----------------------" << endl;
		cout << "1. ��ũ" << endl;
		cout << "2. ������" << endl;
		cout << "3. �̻���" << endl << endl;
		cout << "������ ����(1~3) �׿� ���� : ";
		
		int num;
		cin >> num;
		cout << endl;

		Tank* bomb1;
		Aircraft* bomb2;
		Rocket* bomb3;

		switch (num) {
		case 1:
			bomb1 = new Tank();
			return bomb1;
		case 2:
			bomb2 = new Aircraft();
			return bomb2;
		case 3:
			bomb3 = new Rocket();
			return bomb3;
		default:
			cout << "�����մϴ�." << endl;
			return NULL;
		}
	}
};

int main() {
	BattleShop shop;
	Weapon* weapon;
	while (true) {
		weapon = shop.selectitem();		// ��ȯ���� ���� UpCasting
		Bomb bomb("����ź(hydrogen bomb)");


		if (weapon == NULL)
			break;
		else {
			weapon->load(bomb);
			weapon->use();

			delete weapon;
		}
	}

	return 0;
}