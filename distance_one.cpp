#include <iostream>
#include <vector>
using namespace std;

long long f(int n,int k, vector<int>&v){
    if (n < 0)return 1;
    if (v[n] != 0)return v[n];
    long long zero = f(n-1,k,v)% 100000007;
    long long one = f(n-k,k,v)% 100000007;
    v[n] = (zero + one)%100000007;
    return v[n];
}

int main(){
    int n,k;
    cin >> n >> k;
    vector<int>v(n);
    v[0] = 2;
    long long ans = f(n-1,k,v);
    cout << ans;
    return 0;
}