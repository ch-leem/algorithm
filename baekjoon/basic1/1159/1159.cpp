#include <bits/stdc++.h>
using namespace std;

int n, PREDAJA;
map<char, int> mp;
string name, answer;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for(char i : "abcdefghijklmnopqrstuvwxyz") mp[i] = 0; 

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> name;
        mp[name[0]] += 1;
    }

    for(auto i : mp){
        if(i.second >= 5){
            answer += i.first;    
            PREDAJA = 1;
        } 
    }

    if(PREDAJA == 0) cout << "PREDAJA" << "\n";
    else cout << answer << "\n";
}