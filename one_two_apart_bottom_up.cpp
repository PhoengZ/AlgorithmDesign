#include <iostream>
#include <vector>

using namespace std;

const int mod = 100000007;

int main(){
    long long n;
    cin >> n;
    
    vector<vector<long long>> dp(5,vector<long long>(n+1));

    dp[0][1] = 1;
    dp[1][1] = 1;
    dp[2][1] = 0;
    dp[3][1] = 1;
    dp[4][1] = 0;
    for(int i=2; i<=n; i++){
        dp[0][i] = (dp[2][i-1] + dp[4][i-1] + dp[0][i-1]) % mod;
        dp[1][i] = (dp[0][i-1] + dp[2][i-1] + dp[1][i-1]) % mod;
        dp[2][i] = (dp[1][i-1] ) % mod;
        dp[3][i] = (dp[0][i-1] + dp[4][i-1] + dp[3][i-1]) % mod;
        dp[4][i] = (dp[3][i-1] ) % mod;
    }
    cout << (dp[0][n] + dp[1][n] + dp[2][n] + dp[3][n] + dp[4][n])% mod;
    return 0;
}