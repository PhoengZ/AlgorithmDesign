#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,e,s;
    cin >> n >> e >> s;
    vector<vector<int>>w(n,vector<int>(n)),g;
    vector<int>sol(n,1000000000);
    for (int i = 0;i<e;i++){
        int a,b,c;
        cin >> a >> b >> c;
        g.push_back({a,b});
        w[a][b] = c;
    }
    sol[s] = 0;
    for (int i = 0;i<n;i++){
        for (auto &e:g){
            sol[e[1]] = min(sol[e[1]], sol[e[0]] + w[e[0]][e[1]]);
        }
    }
    bool check = true;
    for (auto &e:g){
        if (sol[e[1]] > sol[e[0]] + w[e[0]][e[1]]){
            check = false;
            break;
        }
    }
    if (!check)cout << -1;
    else {
        for (int i =0;i<n;i++)cout << sol[i] << " ";
    }
    return 0;
}