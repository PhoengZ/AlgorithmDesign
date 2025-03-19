#include <iostream>
#include <vector>
#include <set>
#include <climits>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int>ci(n),co(n),dis(n,INT_MAX);
    vector<bool>sel(n);
    vector<vector<int>>g(n);
    for (int i = 0;i<n;i++){
        cin >> ci[i];
    }
    for (int i = 0;i<n;i++){
        cin >> co[i];
    }
    for (int i = 0;i<m;i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    set<pair<int,int>>s;
    s.insert({0,0});
    dis[0] = 0;
    while (!s.empty()){
        auto it = s.begin();
        pair<int,int> p = *it;
        s.erase(it);
        sel[p.second] = true;
        for (auto & e:g[p.second]){
            if (!sel[e] && dis[e] > p.first + co[p.second] + ci[e]){
                s.erase({dis[e],e});
                dis[e] = p.first + co[p.second] + ci[e];
                s.insert({dis[e],e});
            }
        }
    }
    for (int i  =0;i<n;i++){
        if (!sel[i])cout << -1 << " ";
        else cout << dis[i] << " ";
    }
    return 0;
}