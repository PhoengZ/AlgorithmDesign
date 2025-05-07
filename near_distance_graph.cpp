#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
    int n,m,p,k;
    cin >> n >> m >> p >> k;
    vector<int>start(p);
    vector<vector<pair<int,int>>>g(n+1);
    // vector<vector<int>>w(n+1,vector<int>(n+1));
    for (int i = 0;i<p;i++){
        cin >> start[i];
    }
    for (int i = 0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
        // w[a][b] = w[b][a] = c;
    }
    vector<vector<bool>>sel(p,vector<bool>(n+1));
    vector<vector<int>>dis(p,vector<int>(n+1,10000000));
    for (int i = 0;i<p;i++){
        set<pair<int,int>>s;
        dis[i][start[i]] = 0;
        s.insert({0,start[i]});
        while(!s.empty()){
            auto it = s.begin();
            pair<int,int> t = *it;
            sel[i][start[i]] = true;
            s.erase(it);
            for (auto & e:g[t.second]){
                if (!sel[i][e.first] && dis[i][e.first] > dis[i][t.second] + e.second){
                    s.erase({dis[i][e.first],e.first});
                    dis[i][e.first] = dis[i][t.second] +e.second;
                    s.insert({dis[i][e.first],e.first});
                }
            }
        }
    }
    vector<int>ms(n+1,10000000);
    for (int i = 1;i<=n;i++){
        for(int j = 0;j<p;j++){
            ms[i] = min(ms[i],dis[j][i]);
        }
    }
    int ans = 0;
    for (int i = 1;i<=n;i++){
        bool check = true;
        for (int j = 0;j<p;j++){
            if (abs(dis[j][i] - ms[i]) > k){
                check = false;
                break;
            }
        }
        if (check){
            ans++;
        }
    }
    cout << ans;
    return 0;
}