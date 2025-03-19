#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>>c(n,vector<int>(n)),g(n);
    cin >> c[0][1];
    c[1][0] = c[0][1];
    g[0].push_back(1);
    g[1].push_back(0);
    for (int i = 2;i<n;i++){
        int a;
        cin >> a;
        for (int j = 0;j<a;j++){
            int x,y;
            cin >> x >> y;
            x--;
            g[i].push_back(x);
            g[x].push_back(i);
            c[i][x] = c[x][i] = y;
        }
        set<pair<int,int>>s;
        vector<int>sel(n),dis(n,1000000000);
        s.insert({0,0});
        dis[0] = 0;
        while(!s.empty()){
            auto it = s.begin();
            pair<int,int>p = *it;
            s.erase(it);
            sel[p.second] = true;
            for (auto & e:g[p.second]){
                if (!sel[e] && dis[e] > p.first + c[p.second][e]){
                    s.erase({dis[e],e});
                    dis[e] = p.first + c[p.second][e];
                    s.insert({dis[e],e});
                }
            }
        }
        cout << dis[1] << " ";
    }
    return 0;
}

