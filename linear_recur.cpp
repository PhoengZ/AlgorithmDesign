#include <iostream>
#include <vector>
using namespace std;

long long f(vector<long long>&table, vector<int>&c, vector<int>&a, vector<bool>&check,int k, int n){
    if (check[n])return table[n];
    long long total = 0;
    for (int i = 1;i <= k;i++){
        total += ((c[i-1]%32717)*(f(table,c,a,check,k,n-i)%32717))%32717;
    }
    table[n] = total;
    check[n] = true;
    return total;
}

int main(){
    int n,k;
    cin >> k >> n;
    vector<int> c(k);
    vector<int> a(k);
    vector<long long> table(n+1,-1);
    vector<bool> check(n+1);
    for (int i = 0;i<k;i++)cin >> c[i];
    for (int i = 0;i<k;i++){
        cin >> a[i];
        table[i] = a[i];
        check[i] = true;
    }
    long long ans = f(table,c,a,check,k,n);
    cout << ans%32717;
    return 0;
}