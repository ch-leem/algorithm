// 백준 2910 : 빈도 정렬 (https://www.acmicpc.net/problem/2910)

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int n, c, tmp;
map<int, int> mp, mp_first;
vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second){
        return mp_first[a.first] < mp_first[b.first];
    }
    return a.second > b.second;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> c;
    for(int i=0; i<n; i++){
        cin >> tmp;
        mp[tmp]++;
        if(mp_first[tmp] == 0) mp_first[tmp] = i+1;
    }
    for(auto i : mp) v.push_back({i.first, i.second});
    sort(v.begin(), v.end(), cmp);

    for(auto i : v){
        for(int j=0; j<i.second; j++){
            cout << i.first << " ";
        }
    }
    return 0;
}