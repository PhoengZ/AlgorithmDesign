#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int target;
int mpath = 0;



void f(int hap, int node, vector<vector<int>>&w, vector<vector<int>>&g, vector<bool>&v, int c, int& ans){
    if (node < 0 || node > target)return ;
    if (c == 0){
        ans = max(hap,ans);
        return ;
    }
    if (mpath*c + hap < ans)return;
    if (node == target)return ;
    if ( node != 0  && !v[node-1] ){
        v[node-1] = true;
        f(hap+w[node][node-1],node-1,w,g,v,c-1,ans);
        v[node-1] = true;
    }
    if (node != target && !v[node+1]){
        v[node+1] = true;
        f(hap+w[node][node+1],node+1,w,g,v,c-1,ans);
        v[node+1] = false;
    }
    if (node != 0){
        f(hap,node-1,w,g,v,c,ans);
    }
    if (node != target){
        f(hap,node+1,w,g,v,c,ans);
    }
    // for (auto & e:g[node]){
    //     if (!v[e]){
    //         v[e] = true;
    //         f(hap+w[node][e],e,w,g,v,c-1,ans);
    //         v[e] =false;
    //     }
    // }
}

int main(){
    int n;
    cin >> n;
    target = n-1;
    vector<vector<int>>w(n,vector<int>(n)),g(n);
    vector<bool>s(n);
    s[0] = true;
    for (int i = 0;i<n;i++){
        for (int j =0;j<n;j++){
            cin >> w[i][j];
            if (w[i][j] != 0)g[i].push_back(j);
            mpath = max(mpath,w[i][j]);
        }
    }
    int ans = 0;
    s[0] = true;
    f(0,0,w,g,s,n-1,ans);
    cout << ans;
    return 0;
}