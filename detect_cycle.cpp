#include <iostream>
#include <vector>
#include <stack>

using namespace std;



int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1;i<=t;i++){
        int n,e;
        cin >> n >> e;
        vector<vector<int>>g(n);
        vector<bool>sel(n);
        vector<int>from(n);
        for (int j =0;j<e;j++){
            int a,b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        stack<int>s;
        bool l = false;
        for (int i = 0;i<n;i++){
            if (l)break;
            if (sel[i])continue;
            sel[i] = true;
            s.push(i);
            while (!s.empty() && !l){
                int v = s.top();
                s.pop();
                for (auto &e:g[v]){
                    if (from[v] != e && sel[e]){
                        l = true;
                        break;
                    }
                    if (!sel[e]){
                        from[e] = v;
                        sel[e] = true;
                        s.push(e);
                    }
                }
            }
        }
        if (l)cout << "YES" <<endl;
        else cout << "NO" <<endl;
    }
    return 0;
}