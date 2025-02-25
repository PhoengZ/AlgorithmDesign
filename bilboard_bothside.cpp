#include <iostream>
#include <vector>
using namespace std;

int target;

int f(int n, int row, int w, bool choose, vector<vector<int>>&dp, vector<vector<int>>&table){
    if (n > target)return 0;
    if (n == target)return choose ? table[row][n]:max(table[0][n],table[1][n]);
    if (dp[row][n] != 0)return dp[row][n];
    if (choose){
        dp[row][n] = max(table[row][n] + f(n+w+1,abs(row-1),w,true,dp,table),f(n+1,row,w,choose,dp,table));
    }else{
        dp[row][n] = max(f(n+1,row,w,false,dp,table),max(f(n+w+1,0,w,true,dp,table) + table[1][n],f(n+w+1,1,w,true,dp,table) + table[0][n]));
    }
    return dp[row][n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,w,k;
    cin >> n >> w >> k;
    target = n-1;
    vector<vector<int>>table(2,vector<int>(n));
    vector<vector<int>>dp(2,vector<int>(n));
    for (int i = 0;i<n;i++)cin >> table[0][i];
    for (int i = 0;i<n;i++)cin >> table[1][i];
    int ans1 = f(0,0,w,false,dp,table);
    int ans2 = f(0,1,w,false,dp,table);
    cout << max(ans1,ans2);
    return 0;

}