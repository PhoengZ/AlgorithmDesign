#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <climits>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>>g(n),w(n,vector<int>(n));
    vector<bool>sel(n,false);
    vector<int>dis(n,INT_MAX);
    for (int i = 0;i<n;i++){
        for (int j = i+1;j<n;j++){
            cin >> w[i][j];
            w[j][i] = w[i][j];
            g[i].push_back(j);
            g[j].push_back(i);
        }
    }
    set<pair<int,int>>s;
    s.insert({0,0});
    sel[0] = true;
    dis[0] = 0;
    int total = 0;
    while(!s.empty()){
        auto it = s.begin();
        pair<int,int>p = *it;
        s.erase(it);
        sel[p.second] = true;
        total+= dis[p.second];
        for (auto &e:g[p.second]){
            if (!sel[e] && w[p.second][e] < dis[e]){
                s.erase({dis[e],e});
                dis[e] = w[p.second][e];
                s.insert({dis[e],e});
            }
        }
    }
    cout << total;
    return 0;
}