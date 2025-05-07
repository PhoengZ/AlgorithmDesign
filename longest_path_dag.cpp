#include <iostream>
#include <vector>
#include <set>
#include <stack>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<pair<int,int>>>g(n+1);
    vector<int>dis(n+1);
    for (int i = 0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        g[a].push_back({b,c});
    } 
    int ans = 0;
    vector<bool>sel(n+1);
    for (int i = 1;i<=n;i++){
        if (sel[i])continue;
        stack<int>s;
        s.push(i);
        dis[i] = 0;
        sel[i] = true;
        while(!s.empty()){
            int t = s.top();
            s.pop();
            for (auto &e:g[t]){
                if ((sel[e.first] && dis[e.first] < dis[t] + e.second ) || !sel[e.first]){
                    s.push(e.first);
                    sel[e.first] = true;
                    dis[e.first] = dis[t] + e.second;
                    ans = max(ans,dis[e.first]);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}