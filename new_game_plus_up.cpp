#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<vector<long long>>>dp(n+1,vector<vector<long long>>(m+1,vector<long long>(3)));
    vector<vector<int>>v(n+1,vector<int>(m+1));
    for (int i = 1;i<=n;i++){
        for (int j = 1;j<=m;j++)cin >> v[i][j];
    }
    int mod = 100000007;
    for (int i = 2;i<=m;i++){
        for (int j = 1;j<=n;j++){
            for (int k=0;k<3;k++){
                if (v[j][i])continue;
                if (i == 2){
                    if (k == 0){
                        if (j + 1 >n)continue;
                        dp[j][i][0] = (abs(v[j+1][i-1] - 1))%mod;
                    }
                    else if (k == 1){
                        dp[j][i][1] = (abs(v[j][i-1]-1))%mod;
                    }
                    else{
                        if (j - 1 < 1)continue;
                        dp[j][i][2] = (abs(v[j-1][i-1]-1))%mod;
                    }
                }else{
                    if (k == 0){
                        if (j + 1 >n)continue;
                        dp[j][i][0] = (dp[j+1][i-1][1] + dp[j+1][i-1][2])%mod;
                    }
                    else if (k == 1){
                        dp[j][i][1] = (dp[j][i-1][2] + dp[j][i-1][0])%mod;
                    }
                    else{
                        if (j - 1 < 1)continue;
                        dp[j][i][2] = (dp[j-1][i-1][0] + dp[j-1][i-1][1])%mod;
                    } 
                }
                
            }
        }
    }
    long long total = 0;
    for (int i = 1;i<=n;i++){total += (dp[i][m][0] + dp[i][m][1] + dp[i][m][2]);}
    cout << total % mod;
    return 0;
}