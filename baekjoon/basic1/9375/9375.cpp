#include <bits/stdc++.h>
using namespace std;

int t, n;
string w, wt;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n;
        map<string, int> mp;
        for(int j=0; j<n; j++){
            cin >> w >> wt;
            mp[wt] += 1;
        }
        int result = 1;
        for(auto i : mp){
            result *= (i.second+1);
        }
        cout << (result-1) << "\n";
    }
}