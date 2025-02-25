#include <iostream>
#include <vector>
using namespace std;

int f(int n, int target, vector<int>&v, vector<int>&table){
    if (n < 0)return 0;
    if (n == 0 || n == 1){
        return target-1 > 1 ? max(v[0],v[1]):v[n];
    }
    if (table[n]!=0)return table[n];
    int left_2 = f(n-2,n,v,table);
    int left_1 = f(n-1,n,v,table);
    table[n] = max(left_1,left_2+v[n]);
    return table[n];
}

int main(){
    int n;
    cin >> n;
    vector<int>v(n);
    vector<int>table(n);
    for (int i = 0;i<n;i++)cin >> v[i];
    int ans = f(n-1,n-1,v,table);
    cout << ans;
    return 0;
}