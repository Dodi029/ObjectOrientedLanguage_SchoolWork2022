#include <iostream>
using namespace std;


class Bomb {
	string title;
public:
	Bomb() {}
	Bomb(string title) { this->title = title; }
	string getTitle() { return title; }
};

class Weapon {			// 순수 가상함수 선언
public:
	virtual void load(Bomb bomb) = 0;
	virtual void use() = 0;
};

class Shop {
public:
	virtual Weapon* selectitem() = 0;
};


class Tank :public Weapon{		// 순수 가상함수 구현
public:
	void load(Bomb bomb) { 
		cout << "탱크 " << bomb.getTitle() << " 을 적재함" << endl; }		// 오버라이딩
	void use() { cout << "탱크 수소탄(hydrogen) 을 발사함" << endl; }		// 오버라이딩
};

class Aircraft :public Weapon {		// 순수 가상함수 구현
public:
	void load(Bomb bomb) {
		cout << "전투기 " << bomb.getTitle()<< " 을 적재함" << endl;}		// 오버라이딩
	void use() { cout << "전투기 수소탄(hydrogen) 을 발사함" << endl; }	// 오버라이딩
};

class Rocket : public Weapon {		// 순수 가상함수 구현
public:
	void load(Bomb bomb) {
		cout << "미사일 " << bomb.getTitle() << " 을 적재함" << endl;}		// 오버라이딩
	void use() { cout << "미사일 수소탄(hydrogen) 을 발사함" << endl; }		// 오버라이딩
};

class BattleShop : public Shop {
public:
	Weapon* selectitem() {
		cout << endl;
		cout << "-------------------------------" << endl;
		cout << "	 무기 아이템 선택	   " << endl;
		cout << "-------------------------------" << endl;
		cout << " 1. 탱크" << endl;
		cout << " 2. 전투기" << endl;
		cout << " 3. 미사일" << endl << endl;
		cout << " 아이템 선택(1~3) 그외 종료 : ";
		
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
			cout << "종료합니다." << endl;
			return NULL;
		}
	}
};

int main() {
	BattleShop shop;
	Weapon* weapon;
	while (true) {
		weapon = shop.selectitem();		// 반환값을 통한 UpCasting
		Bomb bomb("수소탄(hydrogen bomb)");


		if (weapon == NULL)
			break;
		else {
			weapon->load(bomb);
			weapon->use();

			delete weapon;              // 기본클래스의 포인트를 delete하면 하위 클래스 객체를
                                        // 소멸하지 않는 문제가 생김
		}
	}

	return 0;
}