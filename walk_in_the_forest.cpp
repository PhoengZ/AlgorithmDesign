#include <iostream>
#include <vector>
using namespace std;

int f(int row, int col, int t_row, int t_col, vector<vector<int>>&v, vector<vector<int>>&table){
    if (row > t_row || col > t_col)return 0;
    if (row == t_row && col == t_col)return v[row][col];
    if (table[row][col] != 0)return table[row][col];
    int s1 = f(row+1,col,t_row,t_col,v,table);
    int s2 = f(row,col+1,t_row,t_col,v,table);
    int s3=  f(row+1,col+1,t_row,t_col,v,table);
    if (s3 != 0)s3+=v[row+1][col+1];
    table[row][col] = v[row][col] + max(s1,max(s2,s3));
    return table[row][col];
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>>v(n);
    vector<vector<int>>table(n);
    for (int i = 0;i<n;i++){
        vector<int>b(m);
        v[i] = b;
        table[i] =b;
        for (int j = 0;j<m;j++)cin >> v[i][j];
    }
    int ans = f(0,0,n-1,m-1,v,table);
    cout << ans;
    return 0;
}