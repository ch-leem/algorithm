#include <bits/stdc++.h>
using namespace std;

int n, k, current, max_sum;
int a[100000];

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
    
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<k; i++){
        current += a[i];
    } 

    max_sum = current;

    for(int i=k; i<n; i++){
        current = current - a[i-k] + a[i];
        if (max_sum < current) max_sum = current; 
    }

    cout << max_sum << "\n";
}