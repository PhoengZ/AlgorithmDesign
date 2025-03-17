#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int n,e,k;
    cin >> n >> e >> k;
    vector<vector<int>>g(n+1);
    vector<bool>sel(n+1);
    sel[0] = true;
    for (int i = 0;i<e;i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    queue<pair<int,int>>q;
    q.push({0,0});
    int total = 0;
    while(!q.empty()){
        pair<int,int> p = q.front();
        q.pop();
        if (p.second+1 > k)continue;
        for (auto &e:g[p.first]){
            if(!sel[e]){
                if (p.second+1 == k)total++;
                sel[e] = true;
                q.push({e,p.second+1});
            }
        }
    }
    cout << total;
    return 0;
}