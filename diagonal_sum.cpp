#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>>v(n,vector<int>(n));
    for (int i =0;i<n;i++){
        for (int j = 0;j<n;j++)cin >> v[i][j];
    }
    int ans = -1000;
    for (int i = n-1;i>=0;i--){
        int row,col,current;
        row = 0;
        col = i;
        current = v[row][col];
        row++;
        col++;
        ans = max(ans,current);
        while (col < n && row < n){
            current = max(current+v[row][col],v[row][col]);
            ans = max(ans,current);
            col++;
            row++;
        }
    }
    for (int i =1;i<n;i++){
        int row,col,current;
        row = i;
        col = 0;
        current = v[row][col];
        row++;
        col++;
        ans = max(ans,current);
        while (col < n && row < n){
            current = max(current + v[row][col],v[row][col]);
            ans = max(ans,current);
            row++;
            col++;
        }
    }
    cout << ans;
    return 0;
}