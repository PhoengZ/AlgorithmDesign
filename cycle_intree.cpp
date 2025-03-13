#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>>g(n);
    vector<bool>sel(n);
    vector<int>from(n);
    stack<int>s;
    for (int i = 0;i<n;i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int idx = -1;
    int target = -1;
    for (int i =0;i<n;i++){
        if (idx != -1)break;
        if (sel[i])continue;
        sel[i] = true;
        s.push(i);
        from[i] = -1;
        while (!s.empty() && idx == -1){
            int v = s.top();
            s.pop();
            for(auto & e:g[v]){
                if (from[v] != e && sel[e]){
                    idx = v;
                    target = e;
                    from[from[target]] = target;
                    from[target] = idx;
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
    int count = 1;
    while (idx != target){
        idx = from[idx];
        count++;
    }
    cout << count;
    return 0;
}