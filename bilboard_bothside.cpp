#include <iostream>
#include <vector>
using namespace std;

int t;

int f(int n, int row, int w, bool h,vector<vector<int>>&table, vector<vector<int>>&v){
    if (n < 0)return 0;
    if(n == 0)return v[row][n];
    if (table[row][n] != 0)return table[row][n];
    int c;
    if (row == 0)c = f(n-w-1,1,w,true,table,v);
    else c = f(n-w-1,0,w,true,table,v);
    int nc;
    if (h){
        nc = f(n-1,row,w,h,table,v);
    }else if (n == t || !h){
        int nc_1 = f(n-1,0,w,false,table,v);
        int nc_2 = f(n-1,1,w,false,table,v);
        nc = max(nc_1,nc_2);
    }
    table[row][n] = max(v[row][n] + c,nc);
    return table[row][n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,w,k;
    cin >> n >> w >>k;
    t = n-1;
    vector<vector<int>>v(2);
    vector<int>p(n);
    vector<vector<int>>vp(2);
    v[0] = v[1] = vp[0] = vp[1] = p;
    for (int i =0;i<n;i++)cin >> vp[0][i];
    for (int i =0;i<n;i++)cin >> vp[1][i];
    int u1 = f(n-1,0,w,true,v,vp);
    int u2 = f(n-1,1,w,true,v,vp);
    cout << max(u1,u2);
    return 0;
}