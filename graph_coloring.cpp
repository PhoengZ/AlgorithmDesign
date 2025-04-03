#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int main(){
    int n,e;
    cin >> n >> e;
    vector<vector<int>>g(n,vector<int>(n));
    vector<vector<int>>d(n);
    map<int,int>m;
    vector<pair<int,int>>v(n);
    for (int i =0;i<e;i++){
        int a,b;
        cin >> a >> b;
        g[a][b] = g[b][a] = 1;
        d[a].push_back(b);
        d[b].push_back(a);

    }
    for (int i = 0;i<n;i++){
        int count = 0;
        for (int j =0;j<n;j++){
            if (g[i][j] == 1)count++;
        }
        v[i] = {count,i};
    }
    // vector<int>color(51);
    // for (int i = 1;i<=50;i++)color[i] = i;
    vector<int>sol;
    int ans = 0;
    int c_now = 1;
    sort(v.rbegin(),v.rend());
    for (int i = 0;i<n;i++){
        set<int>s;
        for (auto & e:d[v[i].second]){
            if (m.count(e)){
                s.insert(m[e]);
            }
        }
        bool check = true;
        for (auto &e:sol){
            if (!s.count(e)){
                check = false;
                m[v[i].second] = e;
                break;
            }
        }
        if (check){
            sol.push_back(c_now);
            m[v[i].second] = c_now++;
            ans++;
        }
    }
    cout << ans;
    return 0;
}