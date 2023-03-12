#include<iostream>
#include<cstring>

using namespace std;

class Person {												// Person 클래스 선언
	char* name;
	int id;
public:
	Person(int id, char* name);								// 생성자
	~Person();
	void changeName(char* name);
	void show() { cout << id << ',' << name << endl; }
};
Person::Person(int id, char* name) {						// 생성자
	this->id = id;
	int len = strlen(name);									// name의 문자 개수
	this->name = new char[len + 1];							// name 문자열 공간 할당
	strcpy(this->name, name);								// name에 문자열 복사
}
Person::~Person() {											// 소멸자
	if (name)												// 만약 name에 동적 할당된 배열이 있으면
		delete[]name;										// 동적 할당 메모리 소멸
}
void Person::changeName(char* name) {						// 이름 변경
	if (strlen(name) > strlen(this->name)) return;
	strcpy(this->name, name);
}
int main() {
	Person father(1, "Kitae");								// (1) father 객체 생성
	Person daughter(father);								// (2) daughter 객체 복사 생성, 복사 생성자 호출

	cout << "daughter 객체 생성 직후 ---" << endl;
	father.show();											// (3) father 객체 출력
	daughter.show();										// (4) daughter 객체 출력

	daughter.changeName("Grace");
	cout << "daughter 이름을 Grace로 변경한 후---"endl;
	father.show();											// (5) father 객체 출력
	daughter.show();										// (6) daughter 객체 출력

	return 0;												// (6), (7) daughter, father 객체 소멸
}