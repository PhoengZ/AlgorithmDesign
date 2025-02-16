#include <iostream>
#include <vector>
using namespace std;

#define ll long long

int tn,tm;

ll f(int r, int c, int door, vector<vector<int>>&v, vector<vector<vector<ll>>>&table){
    if (r> tn || r <= 0)return 0;
    if (v[r][c] == 1)return 0;
    if (c == tm)return 1;
    if (door != 0 && table[r][c][door-1] != 0)return table[r][c][door-1];
    long long first,second,third;
    if (door == 1){
        first = f(r,c+1,2,v,table)%100000007;
        second= f(r+1,c+1,3,v,table)%100000007;
        table[r][c][door-1] = (first + second)%100000007;
    }else if (door == 2){
        first = f(r-1,c+1,1,v,table);
        second = f(r+1,c+1,3,v,table);
        table[r][c][door-1] = (first + second)%100000007;
    }else if (door == 3){
        first = f(r-1,c+1,1,v,table)%100000007;
        second= f(r,c+1,2,v,table)%100000007;
        table[r][c][door-1] = (first + second)%100000007;
    }else{
        first = f(r-1,c+1,1,v,table)%100000007;
        second= f(r,c+1,2,v,table)%100000007;
        third = f(r+1,c+1,3,v,table)%100000007;
        if (door == 0){
            return (first + second + third)%100000007;
        }else{
            table[r][c][door-1] = (first + second + third)%100000007;
        }
    }
    return table[r][c][door-1];
}

int main(){
    int n,m;
    cin >> n >> m;
    tn = n;
    tm = m;
    vector<vector<int>>room(n+1,vector<int>(m+1));
    vector<vector<vector<ll>>>table(n+1,vector<vector<ll>>(m+1,vector<ll>(3)));
    for (int i = 1;i<=n;i++){
        for (int j =1;j<=m;j++)cin >> room[i][j];
    }
    ll total = 0;
    for (int i = 1;i<=n;i++){
        ll ans = f(i,1,0,room,table);
        total+= ans;
    }
    cout << total%100000007;
    return 0;
}