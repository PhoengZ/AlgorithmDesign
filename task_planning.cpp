#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>>g(n);
    vector<int>c(n),ans(n);
    vector<bool>s(n);
    queue<int>q;
    for (int i = 0;i<n;i++){
        int a;
        cin >> a;
        c[i] = a;
        if (a == 0){
            q.push(i);
            s[i] = true;
        }
        for (int j = 0;j<a;j++){
            int b;
            cin >> b;
            g[b].push_back(i);
        }
    }
    int i = 0;
    while(!q.empty()){
        int f = q.front();q.pop();
        ans[i++] = f;
        for (auto & e:g[f]){
            if (s[e])continue;
            c[e]--;
            if (c[e] == 0){
                s[e] = true;
                q.push(e);
            }
        }
    }
    for (auto & e:ans)cout << e << " ";
    return 0;
}