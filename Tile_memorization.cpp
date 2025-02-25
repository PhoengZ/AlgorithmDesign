#include <iostream>
#include <vector>

using namespace std;

int f(int n, int area, vector<vector<int>>&dp, vector<int>&v){
    if (area < 0)return 10000000;
    if (n == 0)return area == 0 ? 0:10000000;
    if (dp[n][area] != 0)return dp[n][area];
    int total = 10000000;
    for (int i = 1;i*i<=area;i++){
        total = min(total,f(n-1,area - i*i,dp,v) + abs(v[n] - i)*abs(v[n]-i));
    }
    dp[n][area] = total;
    return dp[n][area];
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<int>v(n+1);
    vector<vector<int>>dp(n+1,vector<int>(m+1));
    for(int i = 1;i<=n;i++)cin >> v[i];
    int answer=  f(n,m,dp,v);
    if (answer == 10000000)cout << -1;
    else cout << answer;
    return 0;
}