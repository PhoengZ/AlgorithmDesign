#include <iostream>
#include <vector>
using namespace std;


int f(int i, int j, vector<vector<int>>&table, vector<int>&v, vector<vector<bool>>&check){
    if (i >= j )return 0;
    if (check[i][j])return table[i][j];
    //cout << "i: " << i << " j: " << j << endl;
    int n_choose = f(i+1,j,table,v,check);
    int total = 0;
    for (int k = i+1;k<=j;k++){
        total = max(total,f(i+1,k-1,table,v,check) + v[i]*v[k] + f(k+1,j,table,v,check));
    }
    table[i][j] = max(n_choose,total);
    check[i][j] = true;
    return table[i][j];
}
  

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >>n;
    vector<int>v(n+1);
    vector<vector<int>>table(n+1,vector<int>(n+1));
    vector<vector<bool>>check(n+1,vector<bool>(n+1));
    for (int i = 1;i<=n;i++)cin >> v[i];
    int answer = f(1,n,table,v,check);
    cout << answer;
    return 0;
}
