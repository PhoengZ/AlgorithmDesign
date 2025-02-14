#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int>v(n+1);
    int dp[n+1][m+1];
    for (int i = 0;i<=n;i++)dp[i][0] = 0;
    for (int i = 0;i<=m;i++)dp[0][i] = 0;
    for (int i =1;i<=n;i++)cin >> v[i];
    sort(v.begin(),v.end());
    for (int i = 1;i<=n;i++){
        for (int j =1;j<=m;j++){
            if (v[i] + dp)
            bool first = true;
            for (int k  = m;k>=0;k--){
                int edge = k;
                int money = abs(v[i]-k);
                //cout << "Now edge is "<< edge << " Now money is " << money*money << " From i: "<< i  << " From j: "<< j << endl;
                
                if (first){
                    if (j - (edge * edge) < 0)continue;
                    dp[i][j] = dp[i-1][j-(edge*edge)] + money*money;
                    first = false;
                }else{
                    int value = dp[i-1][j-(edge*edge)] + money*money;
                    dp[i][j] = min(dp[i][j],value);
                }
            }
        }
    }
    cout << dp[n][m];
    return 0;
}