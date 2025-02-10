#include <iostream>
#include <vector>

#define ll long long

using namespace std;

ll f(ll n, vector<ll> &table)
{
    if (table[n] != 0 || n == 0)
        return table[n];
    ll zero_1 = f(n - 1, table) % 100000007;
    ll one_1 = f(n - 3, table) % 100000007;
    ll one_2 = f(n - 4, table) % 100000007;
    table[n] = (2 * zero_1 - one_1 + one_2) % 100000007;
    return table[n];
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> table(n+1);
    table[0] = 0;
    table[1] = 0;
    table[2] = 0;
    table[3] = 1;
    long long ans = f(n, table);
    cout << ans;
    return 0;
}