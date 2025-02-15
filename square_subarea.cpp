#include <iostream>
#include <vector>
using namespace std;

int f(int row, int col, vector<vector<int>>&table, vector<string>&matrix ,vector<vector<bool>>&check){
    if (row == 0 || col == 0)return 0;
    if  (check[row][col])return table[row][col];
    int answer;
    if (matrix[row][col] == '0'){
        answer = 0;
    }else{
        int u = f(row-1,col,table,matrix,check);
        int l = f(row,col-1,table,matrix,check);
        int lu = f(row-1,col-1,table,matrix,check);
        answer = 1 + min(u,min(l,lu));
    }
    table[row][col] = answer;
    check[row][col] = true;
    return table[row][col];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<string>matrix(n+1);
    vector<vector<int>>table(n+1,vector<int>(m+1));
    vector<vector<bool>>check(n+1,vector<bool>(m+1));
    string e = "";
    for (int i = 0;i<=m;i++)e+= '0';
    matrix[0] = e;
    for (int i = 1;i<=n;i++){
        string e;
        cin >> e;
        e = '0' + e;
        matrix[i] = e;
    }
    int total = 0;
    for (int i = 1;i<=n;i++){
        for (int j = 1;j<=m;j++){
            int answer = f(i,j,table,matrix,check);
            total = max(total,answer); 
        }
    }
    cout << total;
    return 0;
}
    
