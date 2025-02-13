#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int>v(n+1);
    vector<int> tmp(n+1);
    vector<vector<int>> table(n+1);
    vector<int>p(n+1);
    table[0] = p;
    for (int i = 1;i <= n;i++){
        cin >> v[i];
        tmp[i] =v[i];
        table[i] = p;
    }
    sort(tmp.begin(),tmp.end());
    for (int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if (tmp[j] == v[i])table[i][j] = table[i-1][j-1] + 1;
            else table[i][j] = max(table[i][j-1],table[i-1][j]);
        }
    }
    cout << table[n][n];
    return 0;
}
