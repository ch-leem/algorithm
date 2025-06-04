#include <iostream>
#include <stdio.h>
using namespace std;

int n, ret, cnt;

int main(){
    while(scanf("%d", &n) != EOF){
        ret = 1;
        cnt = 1;
        while(ret % n != 0){
            ret = (ret * 10) + 1;
            ret %= n;
            cnt++;
        }
        cout << cnt << "\n";
    }

    return 0;
}