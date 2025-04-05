#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int target;
int mpath = 0;

int upper(int node, vector<bool>&v, vector<vector<int>>&w,int c,vector<int>&t){
    int bound = 0;
    // Sum of maximum outgoing edges from remaining unvisited cities
    for (int i = 0; i <= target-1; i++) {
        if (!v[i] || i == node) {
            bound += t[i];
        }
    }
    // Add maximum edge from last city to target (city N-1)
    if (c > 1) {
        int last_city_max = 0;
        for (int i = 0; i <= target; i++) {
            if (!v[i] && i != node) {
                last_city_max =max(w[i][target],last_city_max);
            }
        }
        bound += last_city_max;
    }
    return bound;
}


void f(int hap, int node, vector<vector<int>>&w, vector<vector<int>>&g, vector<bool>&v, int c, int& ans,vector<int>&t){
    if (c == 0){
        ans = max(hap,ans);
        return ;
    }
    if (upper(node,v,w,c,t) + hap <= ans)return;
    if (node == target)return ;
    for (auto & e:g[node]){
        if (!v[e]){
            v[e] = true;
            f(hap+w[node][e],e,w,g,v,c-1,ans,t);
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
    // for (int i = 0;i<n;i++){
    //     cout << t[i] << " ";
    // }
    // cout << endl;
    int ans = -100000000;
    s[0] = true;
    f(0,0,w,g,s,n-1,ans,t);
    cout << ans;
    return 0;
}