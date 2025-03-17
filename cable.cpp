#include <iostream>
#include <vector>
#include <stack>
#include <set>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>>w(n,vector<int>(n));
    vector<vector<int>>g(n);
    vector<int>cost(n,1000000);
    vector<bool>sel(n);
    set<pair<int,int>>s;
    for (int i = 0;i<n;i++){
        for (int j = i+1;j<n;j++){
            cin >> w[i][j];
            w[j][i] = w[i][j];
            g[i].push_back(j);
            g[j].push_back(i);
        }
    }
    int total = 0;
    s.insert({0,0});
    while(!s.empty()){
        pair<int,int> p = {s.begin()->first,s.begin()->second};
        sel[p.second] = true;
        s.erase(s.begin());
        total += p.first;
        for (auto & e:g[p.second]){
            if (!sel[e] && cost[e] > w[p.second][e]){
                if (s.count({cost[e],e}))s.erase({cost[e],e});
                cost[e] = w[p.second][e];
                s.insert({cost[e],e});
            }
        }
    }
    cout << total;
    return 0;
}