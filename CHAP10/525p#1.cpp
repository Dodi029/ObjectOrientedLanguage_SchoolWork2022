// 배열에서 가장 큰 값을 출력하는 코드
#include <iostream>
using namespace std;

template <class T>
T biggest(T data[], int n){
    T max = 0;
    max=data[0];

    for(int i=0; i<n;i++){
      if(max<data[i]){
          max = data[i];
        }
    }
    return max;
}
int main(){
    int x[] = {1, 10, 100, 5, 4};
    cout << biggest(x, 5) << endl;
}