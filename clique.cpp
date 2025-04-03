#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int target;

int predict(vector<int>&b, vector<bool>&sel,int node){
    int total = 0;
    for (int i = node;i<target;i++){
        if (!sel[i])total+=b[i];
    }return total;
}

void f(vector<int>&b, vector<bool>&sel, vector<int>&sol, vector<vector<int>>&g,int total, int&ans, int c){
    if (c == target){
        ans = max(ans,total);
        return ;
    }
    if (sol.size() != 0 && predict(b,sel,c) + total <= ans)return ;
    int start = c;
    bool check = true;
    for (auto &e:sol){
        if (g[start][e] == 0 || g[e][start] == 0){
            check = false;
            break;
        }
    }
    if (check){
        sel[start] = true;
        sol.push_back(start);
        f(b,sel,sol,g,total+b[start],ans,c+1);
        sel[start] = false;
        sol.pop_back();
    }
    f(b,sel,sol,g,total,ans,c+1);
}   

int main(){
    int n;
    cin >> n;
    target = n;
    vector<int>b(n),sol;
    vector<bool>sel(n);
    int ans = 0;
    for (int i = 0;i<n;i++){
        cin >> b[i];
        ans = max(b[i],ans);
    }
    vector<vector<int>>g(n,vector<int>(n));
    for (int i  =0;i<n;i++){
        for (int j = 0;j<n;j++)cin >> g[i][j];
    }
    f(b,sel,sol,g,0,ans,0);
    cout << ans;
    return 0;
}