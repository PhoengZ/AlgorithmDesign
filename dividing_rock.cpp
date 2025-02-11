#include <iostream>
#include <vector>
using namespace std;


int f(int n, int k, vector<vector<int>>&table){
    if (k == 1)return 1;
    if (n == k)return 1;
    if (table[n][k] != 0)return table[n][k];
    int go = f(n-1,k,table);
    int g = f(n-1,k-1,table);
    table[n][k] = ((k*go)%1997 + g%1997)%1997;
    return table[n][k];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int n,k;
    cin >> n >> k;
    vector<vector<int>>table(n+1);
    if (k == 1){cout << 1;return 0;}
    if (k > n){cout << 0;return 0;}
    for (int i = 1;i<=n;i++){
        vector<int>b(k+1);
        table[i] = b;
    }
    int ans = f(n,k,table);
    cout << ans;
    return 0;
}