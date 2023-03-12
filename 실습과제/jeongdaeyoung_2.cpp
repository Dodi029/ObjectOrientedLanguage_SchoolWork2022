#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Skill {
public:
	virtual void load() { cout << "��ų�� ������" << endl; }
	virtual void use() { cout << "��ų�� �����" << endl; }
};

class Shop {
public:
	virtual Skill* selectMenu() { return NULL; }
};

class Obilviate : public Skill {
public:
	void load() { cout << "��������Ʈ ��ų ���� �Ϸ�" << endl; }
	void use() { cout << "���� ����� ������" << endl; }
};

class Expelliarmus : public Skill {
public:
	void load() { cout << "�����縮�Ƹ����� ��ų ������" << endl; }
	void use() { cout << "������ �θ��� ������ ����������" << endl; }
};

class Stupefy : public Skill {
public:
	void load() { cout << "���������� ��ų ������" << endl; }
	void use() { cout << "������ ������Ŵ" << endl; }
};

class MagicShop : public Shop {
public:
	Skill* selectMenu() {
		cout << endl << "----------------------------------" << endl;
		cout << "         ���� ������ ����         " << endl;
		cout << "----------------------------------" << endl;
		cout << "1. Obilviate(��������Ʈ)" << endl;
		cout << "2. Expelliarmus(�����縮�Ƹ�����)" << endl;
		cout << "3. Stupefy(����������)" << endl << endl;
		cout << "������ ����(1~3) �׿� ���� : ";
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
			cout << "�����մϴ�." << endl;
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
