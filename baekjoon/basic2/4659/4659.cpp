// 백준 4659 : 비밀번호 발음하기 (https://www.acmicpc.net/problem/4659)

#include <iostream>
#include <string>
using namespace std;
string s;
int cnt_m, cnt_j;
bool condi;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while(true){
        condi = false;
        cnt_m = 0; cnt_j = 0;    
        cin >> s; 
        if(s == "end") break;
        for(int i=0; i<s.size(); i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                cnt_m++;
                cnt_j = 0;
                condi = true;
            }
            else{
                cnt_j++;
                cnt_m = 0;
            }

            if(cnt_m == 3 or cnt_j == 3){
                condi = false;
                break;
            }

            if(i != 0){
                if(s[i] == 'e' || s[i] == 'o') continue;
                if(s[i-1] == s[i]){
                    condi = false;
                    break;
                }
            }
        }
        if(condi) cout << '<' << s << "> " << "is acceptable.\n";
        else cout << '<' << s << "> " << "is not acceptable.\n";
    }

    return 0;
}