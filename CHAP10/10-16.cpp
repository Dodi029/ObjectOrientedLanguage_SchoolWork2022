// auto로 람다식 만들기
#include <iostream>
#include <string>
using namespace std;

int main(){
    auto love = [](string a, string b){
        cout << a << "보다 " << b << "가 좋아" << endl;
    };      // 람다식

    love("돈", "너");       // 람다식 호출
    love("냉면", "만두");    // 람다식 호출
}
