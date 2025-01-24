#include <iostream>
#include <vector>
using namespace std;

void matrix(vector<vector<int>>&v, int a, int b, int row, int col, int n){
    if (a == 0){
        v[row][col] = b;
        return ;
    }
    matrix(v,a-1,b,row,col,n/2);
    matrix(v,a-1,b-1,row,col+n/2,n/2);
    matrix(v,a-1,b+1,row+n/2,col,n/2);
    matrix(v,a-1,b,row+n/2,col+n/2,n/2);
}

int main(){
    int a,b;
    cin >> a >> b;
    int row = 1<<a;
    vector<vector<int>>v(row);
    for (int i = 0;i<row;i++){
        vector<int>x(row);
        v[i] =x;
    }
    matrix(v,a,b,0,0,row);
    for (int i = 0;i<row;i++){
        for (int j = 0;j<row;j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}