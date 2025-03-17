#include <iostream>
#include <vector>
using namespace std;

bool check(int n, int k, vector<int>&sel, vector<int>&table,vector<int>&a,vector<int>&v){
    int idx = 1;
    if (n + v.size() - 1 > sel.size())return true;
    bool c = false;
    for (int i = n;i<n + v.size() - 1 && idx < sel.size();i++){
        if (sel[i] != v[idx++])return true;
    }
    return false;
}

int f(int n, int k, vector<int>&sel, vector<int>&table,vector<int>&a,vector<int>&v){
    if (n <= 0){
        if (check(1,k,sel,table,a,v))return 0;
        return -10000000;
    }
    if (n == 1){
        sel[n] = 1;
        if (check(n,k,sel,table,a,v)){sel[n] = 0;return a[n];}
        else{sel[n] = 0;return 0;}
    }
    sel[n] = 1;
    int total = 0;
    if (check(n,k,sel,table,a,v)){
        total = f(n-2,k,sel,table,a,v) + a[n];
    }
    sel[n] = 0;
    if (check(n,k,sel,table,a,v)){
        total = max(f(n-1,k,sel,table,a,v),total);
    }
    return total;
}

int main(){
    int n,k;
    cin >> n >> k;
    vector<int>table(n+1);
    vector<int>a(n+1);
    vector<int>v(k+1);
    vector<int>s(n+1);
    for (int i = 1;i<=n;i++)cin >> a[i];
    for (int i = 1;i<=k;i++)cin >> v[i];
    int answer = f(n,k,s,table,a,v);
    cout << answer;
    return 0;
}