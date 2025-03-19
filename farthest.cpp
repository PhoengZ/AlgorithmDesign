#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>>e(n+1);
    vector<vector<long long>>w(n+1,vector<long long>(n+1));
    vector<bool>sel(n+1);
    vector<long long>dis(n+1,1000000);
    for (int i = 1;i<=n;i++){
        for (int j = 1;j<=n;j++){
            cin >> w[i][j];
            if (w[i][j] == 0 || w[i][j] == -1)continue;
            e[i].push_back(j);
        }
    }
    set<pair<long long,int>>s;
    s.insert({0,1});
    dis[1] = 0;
    while (!s.empty()){
        auto it = s.begin();
        pair<long long,int>p = *it;
        sel[p.second] = true;
        s.erase(it);
        for (auto &t:e[p.second]){
            if (!sel[t] && dis[t] > p.first + w[p.second][t]){
                s.erase({dis[t],t});
                dis[t] = p.first + w[p.second][t];
                s.insert({dis[t],t});
            }
        }
    }
    long long ans = 0;
    for (int i = 2;i<=n;i++){
        if (!sel[i]){
            ans = -1;
            break;
        }
        ans = max(ans,dis[i]);
    }
    cout << ans;
    return 0;
}