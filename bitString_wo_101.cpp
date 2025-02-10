#include <iostream>
#include <vector>

#define  ll long long

using namespace std;
ll y;
ll f(ll n, vector<ll>&table){
    if (n < 0)return 1;
    if (n == 0){
        return 2;
    }
    if (table[n] != 0)return table[n];
    ll zero_1;
    if (n == y)zero_1 = f(n-1,table)%100000007;
    else zero_1 = f(n-2,table)%100000007;
    ll one_1 = f(n-1,table)%100000007;
    table[n] = (zero_1 + one_1)%100000007;
    return table[n];
}

int main(){
    ll n;
    cin >> n;
    y = n-1;
    vector<ll>table(n);
    table[0] = 2;
    long long ans = f(n-1,table);
    cout << ans;
    return 0;
}