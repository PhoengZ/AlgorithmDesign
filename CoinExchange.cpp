#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int f(int coin, int m_left, vector<vector<int>>&table, vector<int>&v){
    if (coin <= 0 || m_left <= 0)return 0;
    if (table[coin][m_left] != 0)return table[coin][m_left];
    int answer;
    if (v[coin] > m_left)answer = answer = f(coin-1,m_left,table,v);
    else answer = min(f(coin,m_left-v[coin],table,v) + 1,f(coin-1,m_left,table,v));
    table[coin][m_left] = answer;
    return answer;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<int>v(n+1);
    vector<vector<int>>table(1+n);
    vector<int>p(m+1);
    for (int i =0;i<n;i++){
        cin >> v[i+1];
        table[i] = p;
    }
    sort(v.begin(),v.end());
    table[n] = p;
    for (int i = 1;i<=m;i++)table[1][i] = table[1][i-1]+1;
    int ans = f(n,m,table,v);
    cout << ans;
    return 0;
}