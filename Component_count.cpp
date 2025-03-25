#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int v,e;
    cin >> v >> e;
    vector<vector<int>>g(v+1);
    vector<bool>sel(v+1);
    for (int i = 0;i<e;i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int total = 0;
    for (int i = 1;i<=v;i++){
        if (sel[i])continue;
        queue<int>q;
        q.push(i);
        sel[i] = true;
        while(!q.empty()){
            int t = q.front();
            q.pop();
            for (auto & e:g[t]){
                if(!sel[e]){
                    sel[e] = true;
                    q.push(e);
                }
            }
        }
        total++;
    }
    cout <<total;
    return 0;
}