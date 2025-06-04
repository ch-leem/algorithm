#include <bits/stdc++.h>
using namespace std;

int a, b, c;
int start, finish;
int arr[100];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> a >> b >> c;

    for(int i=0; i<3; i++){
        cin >> start >> finish;
        for(int j=start; j<finish; j++){
            arr[j]++;
        }
    }

    int fee = 0;

    for(int i : arr){
        if(i==0) continue;
        else if(i==1) fee += a;
        else if(i==2) fee += 2*b;
        else fee+= 3*c;
    }

    cout << fee << "\n";
}