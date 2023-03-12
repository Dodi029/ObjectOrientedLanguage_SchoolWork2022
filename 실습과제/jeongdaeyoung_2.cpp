#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Skill {
public:
	virtual void load() { cout << "스킬을 적재함" << endl; }
	virtual void use() { cout << "스킬을 사용함" << endl; }
};

class Shop {
public:
	virtual Skill* selectMenu() { return NULL; }
};

class Obilviate : public Skill {
public:
	void load() { cout << "오블리비에이트 스킬 적재 완료" << endl; }
	void use() { cout << "상대방 기억을 삭제함" << endl; }
};

class Expelliarmus : public Skill {
public:
	void load() { cout << "엑스펠리아르무스 스킬 적재함" << endl; }
	void use() { cout << "마법을 부릴수 없도록 무장해제함" << endl; }
};

class Stupefy : public Skill {
public:
	void load() { cout << "스루페파이 스킬 적재함" << endl; }
	void use() { cout << "상대방을 기절시킴" << endl; }
};

class MagicShop : public Shop {
public:
	Skill* selectMenu() {
		cout << endl << "----------------------------------" << endl;
		cout << "         마법 아이템 선택         " << endl;
		cout << "----------------------------------" << endl;
		cout << "1. Obilviate(오블리비에이트)" << endl;
		cout << "2. Expelliarmus(엑스펠리아르무스)" << endl;
		cout << "3. Stupefy(스루페파이)" << endl << endl;
		cout << "아이템 선택(1~3) 그외 종료 : ";
		int num;
		cin >> num;
		cout << endl;
		Obilviate* skill;
		Expelliarmus* skill2;
		Stupefy* skill3;
		switch (num)
		{
		case 1:
			skill = new Obilviate();
			return skill;
		case 2:
			skill2 = new Expelliarmus();
			return skill2;
		case 3:
			skill3 = new Stupefy();
			return skill3;
		default:
			cout << "종료합니다." << endl;
			return 0;
		}
	}
};



int main() {
	MagicShop shop;
	Skill* skill;
	while (true) {
		skill = shop.selectMenu();

		if (skill == 0) break;
		else {
			skill->load();
			skill->use();
			delete skill;
		}
	}



	return 0;
}
