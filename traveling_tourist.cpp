#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n;


void f(int node, int total, int target, int &ans, int k, vector<int>&top, vector<bool>&sel, vector<vector<int>>&w,vector<int>&start, vector<vector<int>>&g){
    if (k == 0){
        ans = min(total,ans);
        return ;
    }
    if (total >= ans)return ;
    set<pair<int,int>>s;
    s.insert({total,node});
    vector<bool>st(n+1);
    vector<int>dis(n+1,10000000);
    dis[node] = total;
    while(!s.empty()){
        auto it = s.begin();
        pair<int,int>p = *it;
        st[p.second] = true;
        s.erase(it);
        if (p.first + top[target] >= ans)return;
        if (p.second == target){
            if (k == 1){
                ans = min(ans,p.first);
                return ;
            }
            sel[target] = true;
            for (auto &e:start){
                if (!sel[e])f(p.second,p.first,e,ans,k-1,top,sel,w,start,g);
            }
            sel[target] = false;
            break;
        }
        for (auto &e:g[p.second]){
            if (!st[e] && dis[e] > p.first + w[p.second][e]){
                s.erase({dis[e],e});
                dis[e] = p.first + w[p.second][e];
                s.insert({dis[e],e});
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int m,k;
    cin >> n >> m >> k;
    vector<int>start(k);
    vector<vector<int>>g(n+1),w(n+1,vector<int>(n+1));
    vector<bool>sel(n+1);
    vector<int>top(n+1);
    set<int>s;
    for (int i = 0;i<k;i++){
        cin >> start[i];
        s.insert(start[i]);
    }
    for (int i = 0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        g[a].push_back(b);
        g[b].push_back(a);
        w[a][b] = w[b][a] = c;
        top[a] = min(top[a],c);
        top[b] = min(top[b],c);
    }
    // int up = 0;
    int ans = 100000000;
    // for (int i = 1;i<=n;i++)up+=top[i];
    for (int i = 0;i<k;i++){
        sel[start[i]] = true;
        for (int j =0;j<k;j++){
            if (i != j){
                f(start[i],0,start[j],ans,k-1,top,sel,w,start,g);
            }
        }
        sel[start[i]] = false;
    }
    cout << ans;
    return 0;
}
