#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int>w(n);
    vector<vector<int>>g(n);
    stack<int>s;
    for (int i = 0;i<n;i++)cin >> w[i];
    for (int i = 0;i<m;i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    int ans = 0;
    for(int i = 0;i<n;i++){
        vector<int>sel(n);
        sel[i] = true;
        s.push(i);
        while (!s.empty()){
            int v = s.top();
            s.pop();
            for(auto & e:g[v]){
                if (!sel[e]){
                    ans = max(ans,w[e]-w[i]);
                    sel[e] = 1;
                    s.push(e);
                }
            }
        }
    }
    cout << ans;
    return 0;
}