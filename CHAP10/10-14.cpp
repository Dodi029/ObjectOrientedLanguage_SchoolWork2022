// auto를 이용한 변수 선언
#include <iostream>
#include <vector>
using namespace std;

int square(int x) {return x*x;}

int main(){
    auto c = 'a';
    auto pi = 3.14;
    auto ten = 10;
    auto *p = &ten;
    cout << c << " " << pi << " " << ten << " " << *p << endl;


    auto ret = square(3);
    cout << *p << " " << ret << endl;

    vector<int> v = {1,2,3,4,5};
    vector<int>::
}