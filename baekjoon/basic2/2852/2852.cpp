// 백준 2852 : NBA 농구 (https://www.acmicpc.net/problem/2852)
#include <iostream>
#include <string>
#include <utility>
using namespace std;
int n, tn, s, cnt;
string m1, m2, s1, s2;
char last;
int end_time = 48 * 60;
int ret_a, ret_b, draw;
string tmp;

int change_s(string tmp){
    string m = tmp.substr(0, 2);
    string s = tmp.substr(3);
    int sec = stoi(m) * 60 + stoi(s);
    return sec;
}

string to_format(int ret){
    string m = to_string(ret / 60);
    string s = to_string(ret % 60);
    if(m.size() == 1) m = "0" + m;
    if(s.size() == 1) s = "0" + s;
    string result = m + ":" + s;
    return result;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n; 
    while(n--){
        cin >> tn >> tmp;

        if(tn == 1) cnt++; // a win
        else cnt--; // b win

        s = change_s(tmp);

        if(cnt > 0){
            if(last != 'a') ret_a += end_time - s;
            last = 'a';
        }
        else if(cnt == 0){
            draw = end_time - s;
            if(last == 'a') ret_a -= draw;
            else if(last == 'b') ret_b -= draw;
            last = 'd';
        }
        else{
            if(last != 'b') ret_b += end_time - s;
            last = 'b';
        }   
    }
    
    cout << to_format(ret_a) << '\n';
    cout << to_format(ret_b) << '\n';

    return 0;
}

/*
#include <iostream>
#include <string>
using namespace std;
int n, t, a_sum, b_sum, a, b;
string s, pre;

string print(int sum){
    string m = "00" + to_string(sum / 60);
    string s = "00" + to_string(sum % 60);
    return m.substr(m.size()-2, 2) + ":" + s.substr(s.size()-2, 2);
}

int change_sec(string s){
    return atoi(s.substr(0, 2).c_str()) * 60 + atoi(s.substr(3, 2).c_str());
}

void go(int &sum, string s){
    sum += change_sec(s) - change_sec(pre);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    while(n--){
        cin >> t >> s;
        if(a > b) go(a_sum, s);
        else if(b > a) go(b_sum, s);
        t == 1 ? a++ : b++;
        pre = s;
    }
    if(a > b) go(a_sum, "48:00");
    else if(b > a) go(b_sum, "48:00");
    cout << print(a_sum) << '\n';
    cout << print(b_sum) << '\n';
    return 0;
}
*/