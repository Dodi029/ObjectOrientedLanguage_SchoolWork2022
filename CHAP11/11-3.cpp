// get(char*, int)을 이용한 문자열 입력
#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char cmd[80];
    cout << "cin.get(char*,int)로 문자열을 읽습니다." << endl;
    while(true){
        cout << "종료하려면 exit을 입력하세요 >>";
        cin.get(cmd,80);        // 80개까지의 영어 문자 읽음    38개까지의 한글 문자 읽을 수 있음 // '\n'은 입력 스트림 버퍼에 남겨둠
        if(strcmp(cmd,"exit")==0){
            cout << "프로그램을 종료합니다...";
            return 0;
        }
        else
            cin.ignore(1);      // 버퍼에 남아있는 <Enter>키 ('\n') 제거    입력 퍼버에 남아있는 '\n' 제거
            // 이 부분을 제거하면 무한 루프에 빠짐
            // 
    }
}