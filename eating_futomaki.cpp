#include <iostream>
#include <vector>
using namespace std;

int f(int left, int right, vector<int>&v, vector<vector<int>>&dp){
    if (right - left == 1)return max(v[right],v[left]);
    if (dp[left][right] != 0)return dp[left][right];
    int s1 = f(left+2,right,v,dp);
    int s2 = f(left,right-2,v,dp);
    int s3 = f(left+1,right-1,v,dp);
    int value = max(s1 + max(v[left],v[left+1]),max(s2 + max(v[right],v[right-1]),s3 + max(v[right],v[left])));
    dp[left][right] = value;
    return value;
}

int main(){
    int n;
    cin >> n;
    vector<int>v(n);
    vector<vector<int>>dp(n,vector<int>(n));
    for (int i = 0;i<n;i++)cin >> v[i];
    int ans = f(0,n-1,v,dp);
    cout << ans;
    return 0;
}