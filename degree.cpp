#include <iostream>
#include <vector>
using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>>g(n+1,vector<int>(n+1));
    vector<int>ans(n);
    for (int i = 1;i<=n;i++){
        for (int j = 1;j<=n;j++)cin >> g[i][j];
    }
    for (int i = 1;i<=n;i++){
        int count = 0;
        for (int j = 1;j<=n;j++){
            if (g[i][j] == 1)count++;
        }
        ans[count]++;
    }
    int idx = n-1;
    while (ans[idx] == 0 && idx >= 0)idx--;
    for (int i = 0;i<=idx;i++)cout << ans[i] << " ";
    return 0;
}