// 백준 15686 : 치킨 배달 (https://www.acmicpc.net/problem/15686)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
int a[54][54];
int ans = 1e5;
vector<pair<int, int>> home, chicken, selected;

int chicken_street(pair<int, int> p, vector<pair<int, int>> &selected){
    int ret = 1e5;
    int street = 0;
    for(pair<int, int> i : selected){
        street = abs(i.first - p.first) + abs(i.second - p.second);
        ret = min(ret, street);
    }
    return ret;
}

int city_chicken(vector<pair<int, int>> &home, vector<pair<int, int>> &selected){
    int ret = 0;
    for(pair<int, int> i : home){
        ret += chicken_street(i, selected);
    }
    return ret;
}

void combi(int start, vector<pair<int, int>> &selected){
    if(selected.size() == m){
        // logic : 도시의 치킨 거리 return : 최솟값 업데이트
        ans = min(ans, city_chicken(home, selected));
        return;
    }
    for(int i = start + 1; i < chicken.size(); i++){
        selected.push_back(chicken[i]);
        combi(i, selected);
        selected.pop_back();
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
            if(a[i][j] == 1) home.push_back({i, j});
            if(a[i][j] == 2) chicken.push_back({i, j});
        }
    }

    combi(-1, selected);
    cout << ans << "\n";

    return 0;
}