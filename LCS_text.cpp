#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    string a,b;
    cin >> a >> b;
    int dp[n+1][m+1];
    for (int i = 0;i<=n;i++){
        for(int j = 0;j<=m;j++)cin >> dp[i][j];
    }
    int row,col;
    row = n;
    col = m;
    string v = "";
    while (dp[row][col] != 0){
        if (dp[row][col] == dp[row-1][col-1] + 1){
            v = a[row-1] + v;
            row--;
            col--;
        }else if (dp[row][col-1] > dp[row-1][col]){
            col--;
        }else{
            row--;
        }
    }
    cout << v;
    return 0;
}