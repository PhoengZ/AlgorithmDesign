#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,k,target;
    cin >> n >> m >> k;
    cin >> target;
    vector<int>start(k);
    vector<vector<int>>g(n);
    vector<vector<int>>w(n,vector<int>(n));
    for (int i = 0;i<k;i++)cin >> start[i];
    for (int i = 0;i<m;i++){
        int a,b,e;
        cin >> a >> b >> e;
        w[b][a] = e;
        g[b].push_back(a);
    }
    set<pair<int,int>>s;
    vector<int>sel(n),dis(n,100000000);
    s.insert({0,target});
    dis[target] = 0;
    while (!s.empty()){
        auto it = s.begin();
        pair<int,int> p = *it;
        s.erase(it);
        sel[p.second] = true;
        for (auto & e:g[p.second]){
            if (dis[e] > p.first + w[p.second][e]){
                s.erase({dis[e],e});
                dis[e] = p.first + w[p.second][e];
                s.insert({dis[e],e});
            }
        }
    }
    int answer = 100000000;
    for (int i = 0;i<k;i++){
        answer = min(answer,dis[start[i]]);
    }
    cout << answer;
    return 0;
}