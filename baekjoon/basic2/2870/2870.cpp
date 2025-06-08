// 백준 2870 : 수학숙제 (https://www.acmicpc.net/problem/2870)
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int t, tmp;
vector<string> v;
string s, tmps;
bool cmp(string a, string b){
    if(a.size() != b.size()) return a.size() < b.size();
    return a < b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;
    while(t--){
        cin >> s;
        tmps = "";
        for(int i=0; i<s.size(); i++){
            tmp = s[i] - '0';
            if(tmp >= 0 and tmp <= 9){
                tmps += s[i];
            }
            else{
                if(tmps != ""){
                    while(tmps[0] == '0' && tmps.size() != 1) tmps.erase(0, 1);
                    v.push_back(tmps);
                    tmps = "";
                }
                else continue;
            }
        }
        while(tmps[0] == '0' && tmps.size() != 1) tmps.erase(0, 1);
        if(tmps != "") v.push_back(tmps);
    }
    sort(v.begin(), v.end(), cmp);
    for(auto i : v){
        cout << i << "\n";
    }
    return 0;
}
/*
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int t;
vector<string> v;
string s, ret;

void go(){
    while(ret.size() && ret.front() == '0') ret.erase(ret.begin());
    if(ret.size() == 0) ret = '0';
    v.push_back(ret);
    ret = "";
}

bool cmp(string a, string b){
    if(a.size() == b.size()) return a < b;
    return a.size() < b.size();
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> t;
    while(t--){
        cin >> s;
        ret = "";
        for(int i=0; i<s.size(); i++){
            if(s[i] < 65) ret += s[i];
            else if(ret.size()) go();
        }
        if(ret.size()) go();
    }
    sort(v.begin(), v.end(), cmp);
    for(auto i : v) cout << i << '\n';
    return 0;
}
*/