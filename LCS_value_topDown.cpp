#include <iostream>
#include <vector>
using namespace std;

int f(int n, int m, string & a, string& b, vector<vector<int>>&dp){
    if (n == 0 || m == 0)return 0;
    if (dp[n][m] != 0)return dp[n][m];
    if (a[n-1] == b[m-1])dp[n][m] = f(n-1,m-1,a,b,dp) + 1;
    else dp[n][m] = max(f(n-1,m,a,b,dp),f(n,m-1,a,b,dp));
    return dp[n][m];
}

int main(){
    string a,b;
    cin >> a >> b;
    vector<vector<int>>dp(a.length() + 1,vector<int>(b.length()+1));
    int answer = f(a.length(),b.length(),a,b,dp);
    cout << answer;
    return 0;
}