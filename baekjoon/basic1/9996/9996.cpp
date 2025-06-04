#include <bits/stdc++.h>
using namespace std;

int n;
string patt, s, pre, suf;

int main(){
    cin >> n;
    cin >> patt;
    auto star = patt.find("*");
    
    pre = patt.substr(0, star);
    suf = patt.substr(star+1);

    for(int i=0; i<n; i++){
        cin >> s;
        string ans = "NE\n";
        
        if (s.size() >= pre.size() + suf.size()){
            if (s.substr(0, pre.size()) == pre){
                if(s.substr(s.size() - suf.size()) == suf) ans = "DA\n";
            }
        }
        cout << ans;
    }
}