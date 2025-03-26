#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>>g(n);
    vector<int>c(n),sel(n);
    queue<int>q;
    for (int i = 0;i<n;i++){
        int a;
        cin >> a;
        c[i]=a;
        if (a == 0){
            q.push(i);
            sel[i] = true;
        }
        for (int j =0;j<a;j++){
            int b;
            cin >> b;
            g[b].push_back(i);
        }
    }
    vector<int>sol(n);
    int idx = 0;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        sol[idx++] = t;
        for (auto &e:g[t]){
            if (!sel[e]){
                c[e]--;
                if (c[e] == 0){
                    q.push(e);
                    sel[e] = true;
                }

            }
        }
    }
    for (auto & e:sol)cout << e << " ";
    return 0;
}