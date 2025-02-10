#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>>v(n);
    for (int i = 0;i<n;i++){
        vector<int>b(n);
        v[i] = b;
    }
    for (int i = 0;i<n;i++){
        for (int j =0;j<n;j++)cin >> v[i][j];
    }
    int ans = v[0][n-1];
    int now = INT_MIN;
    for (int i = n-2;i>0;i--){
        int col = i;
        now = INT_MIN;
        for (int j = 0;j<n-i;j++){
            if (now ==INT_MIN)now = v[j][col];
            else now = max(now+v[j][col],v[j][col]);
            ans = max(now,ans);
            col++;
        }
    }
    for (int i = 0;i<n;i++){
        int row = i;
        now = INT_MIN;
        for (int j = 0;j<n-i;j++){
            if (now ==INT_MIN)now = v[row][j];
            else now = max(v[row][j],now+v[row][j]);
            ans = max(ans,now);
            row++;
        }
    }
    cout << ans;
    return 0;
}