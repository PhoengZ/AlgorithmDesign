#include <iostream>
#include <vector>
using namespace std;

int f(int n, vector<int>&table, vector<int>&v){
    if (n < 0)return 0;
    if (n == 0)return v[0];
    if (table[n] != 0)return table[n];
    int nc = f(n-1,table,v);
    int c = f(n-3,table,v);
    table[n] = max(c+v[n],nc);
    return table[n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int n;
    cin >> n;
    vector<int>v(n);
    vector<int>table(n);
    for (int i =0;i<n;i++)cin >> v[i];
    int ans = f(n-1,table,v);
    cout << ans;
    return 0;
}