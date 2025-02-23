#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector<vector<int>>v(n+1,vector<int>(n+1));
    for (int i = 0;i<=n;i++){
        v[i][i] = 1;
        v[i][0] = 1;
    }
    for (int i = 2;i<=n;i++){
        for (int j = 1;j<i;j++){
            v[i][j] = v[i-1][j-1] + v[i-1][j];
        }
    }
    cout << v[n][k];
    return 0;
}