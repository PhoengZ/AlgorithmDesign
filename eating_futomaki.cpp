#include <iostream>
#include <vector>
using namespace std;

int f(int left, int right, vector<int>&v, vector<vector<int>>&table){
    if (abs(right-left) == 1){
        return v[right] > v[left] ? v[right]:v[left];
    }
    if (table[left][right] != 0)return table[left][right];
    int lr = f(left+1,right-1,v,table);
    int ll = f(left+2,right,v,table);
    int rr = f(left,right-2,v,table);
    lr+= v[left] > v[right] ? v[left]:v[right];
    ll+= v[left] > v[left+1] ? v[left]:v[left+1];
    rr+= v[right] > v[right-1] ? v[right]:v[right-1];
    table[left][right] = table[right][left] = max(lr,max(ll,rr));
    return table[left][right];
}

int main(){
    int n;
    cin >>n;
    vector<int>v(n);
    vector<vector<int>>table(n);
    for (int i = 0;i<n;i++){
        vector<int>b(n);
        table[i] = b;
    }
    for (int i = 0;i<n;i++)cin >> v[i];
    int ans = f(0,n-1,v,table);
    cout << ans;
    return 0;
}