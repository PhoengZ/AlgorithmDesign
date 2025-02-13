#include <iostream>
#include <vector>

#define ll long long

using namespace std;



int main()
{
    ll n;
    cin >> n;
    ll S0 = 1;
    ll S1 = 1;
    ll S2 = 0;
    ll s0,s1,s2;
    for (ll i = 1;i<n;i++){
        s0 = (S2%100000007 + S0%100000007)%100000007;
        s1 = (S0%100000007 + S1%100000007)%100000007;
        s2 = S1%100000007;
        S0 = s0;
        S1 = s1;
        S2 = s2;
    }
    ll ans = (s0 + s1 + s2)%100000007;
    cout << ans;
    return 0;
}