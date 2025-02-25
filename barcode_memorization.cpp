#include <iostream>
#include <vector>

using namespace std;

long long f(int n, int m, int k, int color, int cur_n, int cur_m, int curr_k,vector<vector<vector<int>>>&dp){
    if (cur_m > m || curr_k > k || k - curr_k > n - cur_n)return 0;
    if (dp[cur_n][cur_m][curr_k] != -1)return dp[cur_n][cur_m][curr_k];
    if (cur_n == n && k == curr_k)return 1;
    int total = f(n,m,k,color,cur_n+1,cur_m+1,curr_k,dp) + f(n,m,k,abs(color-1),cur_n+1,1,curr_k+1,dp);
    dp[cur_n][cur_m][curr_k] = total;
    return total;
}
int main(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(k+1,-1)));
    long long answer = f(n,m,k,0,1,1,0,dp);
    cout <<answer;
    return 0;
}