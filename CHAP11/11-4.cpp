// getline()으로 한 줄 단위로 문장 읽기
#include <iostream>
using namespace std;

int main(){
    char line[80];
    cout << "cin.getline() 함수로 라인을 읽습니다." << endl;
    cout << "exit를 입력하면 루프가 끝납니다." << endl;

    int no=1;       // 라인 번호
    while(true){
        cout << "라인" << no << ">>";
        cin.getline(line,80);       // 79개까지의 문자 읽음
        if(strcmp(line,"exit")==0)
            break;
        cout << "echo-->";;
        cout << line << endl;       // 읽은 라인을 화면에 출력
        no++;    // 라인 번호 증가
    }
}