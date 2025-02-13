#include <iostream>
#include <vector>
using namespace std;

int t;

int f1(int n, int row, int w, int k, bool h,vector<vector<pair<int,int>>>&table, vector<vector<int>>&v){
    if (n < 0)return 0;
    if (n == 0)return v[row][n];
    if (table[row][n].first != 0)return table[row][n].first;
    if (k == 0){
        return 0;
    }else{
        int c;
        if (row == 0)c = f1(n-w-1,1,w,k-1,true,table,v);
        else c = f1(n-w-1,0,w,k-1,true,table,v);
        int nc;
        if (h){
            nc = f1(n-1,row,w,k,h,table,v);
        }else if (n == t || !h){
            int nc_1 = f1(n-1,0,w,k,false,table,v);
            int nc_2 = f1(n-1,1,w,k,false,table,v);
            nc = max(nc_1,nc_2);
        }
        if (v[row][n] + c > nc && n-w-1 >= 0 && table[(row+1)%2][n-w-1].second < k){
            table[row][n].first = v[row][n] + c;
            table[row][n].second = table[(row+1)%2][n-w-1].second + 1;
        }else if (v[row][n] + c > nc && n-w-1 < 0){
            table[row][n].first = v[row][n] + c;
            table[row][n].second = 1;
        }else{
            table[row][n].first = nc;
            if (n == t || ! h){
                if (table[0][n-1].first == table[1][n-1].first){
                    table[row][n].second = table[0][n-1].second < table[1][n-1].second ? table[0][n-1].second:table[1][n-1].second;
                }else{
                    table[row][n].second = table[0][n-1].first > table[1][n-1].first ? table[0][n-1].second:table[1][n-1].second;
                }
            }else if (h){
                table[row][n].second = table[row][n-1].second;
            }
        }
    }
    return table[row][n].first;
}


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
    if (k == n){
        int u1 = f(n-1,0,w,true,v,vp);
        int u2 = f(n-1,1,w,true,v,vp);
        cout << max(u1,u2);
    }else{
        vector<vector<pair<int,int>>>table(2);
        vector<pair<int,int>>pre(n);
        table[0] = table[1] = pre;
        table[0][0].second = 1;
        table[1][0].second = 1;
        int u1 = f1(n-1,0,w,k,true,table,vp);
        int u2 = f1(n-1,1,w,k,true,table,vp);
        cout << max(u1,u2);
    }
    return 0;
}