#include <iostream>
#include <vector>
using namespace std;
int r;
int f(int row, int col, vector<vector<int>>&v, vector<vector<int>>&table){
    if (row == r)return v[row][col];
    if (table[row][col] != 0)return table[row][col];
    int left = f(row+1,col,v,table);
    int right = f(row+1,col+1,v,table);
    table[row][col] = max(left,right) + v[row][col];
    return table[row][col];
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>>v(n);
    vector<vector<int>>table(n);
    for (int i =0;i<n;i++){
        vector<int>b(n);
        table[i] = b;
        v[i] = b;
    }
    r = n-1;
    for (int i = 0;i<n;i++){
        for (int j = 0;j<=i;j++){
            cin >> v[i][j];
        }
    }
    int total  = f(0,0,v,table);
    cout << total;
    return 0;
}