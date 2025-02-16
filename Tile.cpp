#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int>v(n+1);
    vector<vector<int>>dp(n+1,vector<int>(m+1));
    vector<bool>c(m+1);
    for (int i =1;i<=n;i++)cin >> v[i];
    for (int i = 1;i<=m;i++)dp[0][i] = 100000000;
    for (int i = 1;i<=n;i++){
        for (int j = 0;j<=m;j++){
            dp[i][j] = 100000000;
            for (int k = 1;k<=m;k++){
                if (j - (k*k) < 0)break;
                if (dp[i-1][j-k*k] + abs(v[i]-k)*abs(v[i]-k) < dp[i][j]){
                    dp[i][j] = dp[i-1][j-k*k] + abs(v[i]-k)*abs(v[i]-k);
                }
            }
        }
    }
    if (dp[n][m] == 100000000)cout << -1;
    else cout << dp[n][m];
    return 0;
}