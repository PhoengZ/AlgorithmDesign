#include <iostream>
#include <vector>
#include <climits>
using namespace std;


int f(int now, int target, vector<int>&v, vector<int>&table, vector<bool>&check){
    if (now < target)return INT_MIN;
    if (check[now]){
        return table[now];
    }
    if (now == target){
        check[now] = true;
        table[now] = v[now];
        return table[now];
    }
    int first = f(now-1,target,v,table,check);
    int second = f(now-2,target,v,table,check);
    int third = f(now-3,target,v,table,check);
    check[now] = true;
    table[now] =  max(first,max(second,third)) + v[now];
    return table[now];
}

int main(){
    int n;
    cin >> n;
    vector<int>v(n);
    vector<int>table(n);
    vector<bool>check(n);
    for (int i =0;i<n;i++)cin >> v[i];
    int ans = f(n-1,0,v,table,check);
    cout << ans;
    return 0;
}