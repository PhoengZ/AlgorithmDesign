#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    int dp[33][33][33];
    for (int i = 1;i<=m;i++)dp[1][0][i] = 1;
    for (int i = 2;i<=n;i++){
        for(int j = 0;j<=k;j++){
            for(int c = 1;c<=m;c++){
                dp[i][j][c] = dp[i-1][j-1][1] + dp[i-1][j][c+1];
            }
        }
    }
    cout << dp[n][k][1];
    return 0;
}