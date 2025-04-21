#include <bits/stdc++.h>
using namespace std;

int n, m, cnt, num;
vector<int> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    cin >> m;
    for(int i=0; i<n; i++){
        cin >> num; 
        v.push_back(num);
    }

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(v[i]+v[j] == m){
                cnt++;
            } 
        }
    }   
    
    cout << cnt << "\n";
    return 0;
}