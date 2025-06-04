#include <bits/stdc++.h>
using namespace std;

string s, ret;
char mid;
int flag;
int cnt[200];

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> s;
    for (int c : s) cnt[c]++;
    for(int i='Z'; i>='A'; i--){
        if(cnt[i]){
            if (cnt[i] % 2 == 1){
                flag++;
                mid = char(i);
                cnt[i] --;
            }
            if (flag == 2) break;
            for(int j = 0; j < cnt[i]; j+=2){
                ret = char(i) + ret;
                ret += char(i);
            }
        }
    }
    if (flag == 2) cout << "I'm Sorry Hansoo\n";
    else{
        if (mid) ret.insert(ret.begin() + ret.size()/2, mid);
        cout << ret << "\n";
    }
    return 0;
}