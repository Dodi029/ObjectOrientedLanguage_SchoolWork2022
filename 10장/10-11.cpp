// iterator�� ����Ͽ� vector�� ��� ���ҿ� 3 ���ϱ�
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int>v;	// ���� ���� ����
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	vector<int>::iterator it;		// ���� v�� ���ҿ� ���� ������ it ����

	for (it = v.begin(); it != v.end(); it++) {
		// v.end()�� NULL�� �� �ݺ����� NULL�� ������ ������ �ݺ���
		int n = *it;		// it�� ����Ű�� ���� �� ����
		n = n * 3;		// ���ϱ� 3
		*it = n;		// it�� ����Ű�� ���ҿ� �� ����
	}
	for (it = v.begin(); it != v.end(); it++)		// ���� v�� ��� ���� ���
		cout << *it << ' ';
	cout << endl;
}