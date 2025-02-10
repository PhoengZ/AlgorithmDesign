#include <iostream>
#include <vector>
using namespace std;

int f(int n, int target, vector<int>&v, vector<int>&table){
    if (n == target || n == target+1){
        return v[n];
    }
    if (table[n]!=0)return table[n];
    int left_1 = f(n-1,target,v,table);
    int left_2 = f(n-2,target,v,table);
    if (n-target >=3){
        int left_3 = f(n-3,target,v,table);
        table[n] = max(left_1,max(left_2+v[n],left_3+v[n]));
    }else table[n] = max(left_1,left_2+v[n]);
    return table[n];
}

int main(){
    int n;
    cin >> n;
    vector<int>v(n);
    vector<int>table(n);
    for (int i = 0;i<n;i++)cin >> v[i];
    int ans = f(n-1,0,v,table);
    cout << ans;
    return 0;
}