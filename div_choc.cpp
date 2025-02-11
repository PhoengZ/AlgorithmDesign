#include <iostream>
#include <vector>

using namespace std;

int f(int n, vector<int>&table, vector<int>&v){
    if (n < 0)return 0;
    if (n == 0)return 1;
    if (table[n] != 0)return table[n];
    int total = 0; 
    for (auto &e:v){
        total += (f(n-e,table,v)%1000003);
    }
    table[n] = total%1000003;
    return table[n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int n,k;
    cin >> n >> k;
    vector<int>table(n+1);
    vector<int>v(k);
    for (int i =0;i<k;i++)cin >> v[i];
    int ans = f(n,table,v);
    cout << ans;
    return 0;
}