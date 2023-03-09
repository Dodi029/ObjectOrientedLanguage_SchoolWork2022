// 사용자 정의 조작자 만들기
#include <iostream>
using namespace std;

ostream& fivestar(ostream& outs){
    return outs << "*****";
}
ostream& rightarrow(ostream& outs){
    return outs << "--->";
}
ostream& beep (ostream& outs){
    return outs << '\a';    // 시스템 beep(삑 소리) 발생
}

int main(){
    cout << "벨이 울립니다" << beep << endl;
    cout << "C" << rightarrow << "C++" << rightarrow << "Java" << endl;
    cout << "Visual" << fivestar << "C++" << endl;
}