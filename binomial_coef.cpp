#include <iostream>
#include <vector>
using namespace std;



int f(vector<vector<int>>&table, int n, int k){
    if (table[n][k] != -1)return table[n][k];
    int left = f(table,n-1,k-1);
    int right = f(table,n-1,k);
    table[n][k] = left + right;
    return table[n][k]; 
}

int main(){
    int n,k;
    cin >> n >> k;
    vector<vector<int>> v(n+1);
    for (int i = 1;i<=n;i++){
        vector<int>b(n+1,-1);
        v[i] = b;
    }
    for (int i = 1;i<=n;i++){
        v[i][i] = 1;
        v[i][0] = 1;
    }
    int ans = f(v,n,k);
    cout << ans;
    return 0;
}