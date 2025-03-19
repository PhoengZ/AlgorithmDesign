#include <iostream>
#include <set>
#include <vector>

using  namespace std;

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<int>>g(n);
    vector<int>w(n),dis(n,1000000000),t(k);
    vector<bool>sel(n);
    for (int i = 0;i<k;i++)cin >> t[i];
    for (int i =0;i<n;i++)cin >> w[i];
    for (int i =0;i<m;i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    set<pair<int,int>>s;
    int answer = 0;
    for (int i = 0;i<k;i++){
        s.insert({w[t[i]],t[i]});
        dis[t[i]] = w[t[i]];
        answer = max(answer,dis[t[i]]);
    }
    while(!s.empty()){
        auto it = s.begin();
        pair<int,int> p = *it;
        sel[p.second] = true;
        s.erase(it);
        for (auto & e:g[p.second]){
            if (!sel[e] && dis[e] > p.first + w[e]){
                s.erase({dis[e],e});
                dis[e] = p.first + w[e];
                s.insert({dis[e],e});
            }
        }
    }
    for (int i  =0;i<n;i++)answer = max(answer,dis[i]);
    cout << answer;
    return 0;
}