#include <iostream>
#include <vector>

#define ll long long

using namespace  std;

void f(int n, vector<vector<int>>&table){
    if (n == 0)return ;
    if (table[0][n] != 0 && table[1][n] != 0)return ;
    f(n-1,table);
    table[0][n] = (table[0][n-1]+table[1][n-1] + table[2][n-1])%100000007;
    table[1][n] = (table[0][n-1] + table[1][n-1])%100000007;
    table[2][n] = (table[0][n-1] + table[2][n-1])%100000007;
    return;
}

int main(){
    ll n;
    cin >> n;
    vector<vector<int>>v(3);
    vector<int>a(n);
    v[0] = a;
    v[1] = a;
    v[2] = a;
    v[0][0] = 1;
    v[1][0] = 1;
    v[2][0] = 1;
    f(n-1,v);
    int ans = (v[0][n-1] +v[1][n-1] + v[2][n-1])%100000007;
    cout << ans;
    return 0;
}