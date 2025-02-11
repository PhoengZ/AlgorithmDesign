#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>>v(n+1);
    vector<int>t(n+2);
    for (int i = 1;i<=n;i++){
        vector<int>b(n+1);
        cin >> t[i];
        v[i] = b;
    }
    cin >> t[n+1];
    int count = 1;
    for (int i = 2;i<=n;i++){
        int col = i;
        for (int k = 1;k<=n-count;k++){
            int m = INT_MAX;
            int r = k+1;
            for (int j = k ;j<col;j++){
                m = min(v[k][j] + v[r][col] + (t[k]*t[r]*t[col+1]),m);
                r++;
            }
            v[k][col] = m;
            col++;
        }
        count++;
    }
    cout << v[1][n];
    return 0;
}