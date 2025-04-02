#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;


int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(0);
    int n,q;
    cin >> n >> q;
    for (int i = 0;i<q;i++){
        vector<int>g(n+1);
        vector<vector<int>>t(n+1);
        queue<pair<int,int>>q;
        map<int,int>m;
        vector<bool>sel(n+1);
        for (int j = 1;j<=n;j++){
            cin >> g[j];
            if (g[j] != -1){
                t[g[j]].push_back(j);
            }else{
                q.push({j,j});
                m[j] = 1;
                sel[j] = true;
            }
        }
        int ans = 0;
        bool check = true;
        while (!q.empty() && check){
            pair<int,int> v =q.front();
            q.pop();
            for (auto &e :t[v.second]){
                if (!sel[e]){
                    sel[e] = true;
                    m[v.first]++;
                    q.push({v.first,e});
                }else{
                    check = false;
                    break;
                }
            }
        }
        for (int i = 1;i<=n;i++){
            if (!sel[i]){
                check = false;
                break;
            }
        }
        if (!check)cout << 0 << " " << 0 << "\n";
        else{
            for (auto & e:m){
                ans = max(ans,e.second);
            }
            cout << 1 << " " << ans << "\n";
        } 
    }
    return 0;
}