#include <iostream>
#include <vector>

using namespace std;

int n;

void f(int now, int target, int total, int node, vector<bool>&sel, vector<vector<int>>&sol, int &ans,vector<int>&start){
    if (now == target){
        ans = min(ans,total);
        return ;
    }
    for (auto &e:start){
        if (!sel[e] && e != node){
            sel[e] = true;
            f(now+1,target,total+sol[node][e],e,sel,sol,ans,start);
            sel[e] = false;
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int m,ki;
    cin >> n >> m  >> ki;
    vector<int>s(ki);
    vector<vector<int>>sol(n,vector<int>(n,1000000000));
    for (int i = 0;i<ki;i++){
        cin >> s[i];
        s[i]--;
    }
    for (int i = 0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        a--;
        b--;
        sol[a][b] = sol[b][a] = c;
    }
    for (int i = 0;i<n;i++){
        sol[i][i] = 0;
    }
    for (int k = 0;k<n;k++){
        for (int i = 0;i<n;i++){
            for (int j = 0;j<n;j++){
                sol[i][j] = min(sol[i][j],sol[i][k]+ sol[k][j]);
            }
        }
    }
    int ans = 1000000000;
    vector<bool>sel(n);
    for (int i = 0;i<ki;i++){
        sel[s[i]] = true;
        f(1,ki,0,s[i],sel,sol,ans,s);
        sel[s[i]] = false;
    }
    cout << ans;
    return 0;
}