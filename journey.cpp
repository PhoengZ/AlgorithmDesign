#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int target;
int mpath = 0;


void f(int hap, int node, vector<vector<int>>&w, vector<vector<int>>&g, vector<bool>&v, int c, int& ans,vector<int>&t, int up){
    if (c == 1){
        hap+=w[node][target];
        ans = max(hap,ans);
        return ;
    }
    if (mpath*c + hap <= ans)return ;
    if (up + hap <= ans)return;
    if (node == target)return ;
    for (auto & e:g[node]){
        if (!v[e] && e != target){
            v[e] = true;
            f(hap+w[node][e],e,w,g,v,c-1,ans,t,up-t[node]);
            v[e] =false;
        }
    }
}

int main(){
    int n;
    cin >> n;
    target = n-1;
    vector<vector<int>>w(n,vector<int>(n)),g(n);
    vector<bool>s(n);
    vector<int>t(n,-100000000);
    s[0] = true;
    for (int i = 0;i<n;i++){
        for (int j =0;j<n;j++){
            cin >> w[i][j];
            t.push_back(w[i][j]);
            if (w[i][j] != 0)g[i].push_back(j);
            if (i != j){
                t[i] = max(t[i],w[i][j]);
            }
            mpath = max(mpath,w[i][j]);
        }
    }
    int up = 0;
    for (int i = 0;i<n-1;i++)up+=t[i];
    int ans = -100000000;
    s[0] = true;
    f(0,0,w,g,s,n-1,ans,t,up);
    cout << ans;
    return 0;
}