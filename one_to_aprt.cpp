#include <iostream>
#include <vector>
using namespace std;
long long f(int n, vector<long long>&table){
    if (n<0)return 1;
    if (n == 0)return 3;
    if (table[n]!= 0)return table[n];
    long long first = f(n-1,table);
    long long second = f(n-3,table);
    long long thrid = f(n-1,table);
    table[n] = (first+second+thrid)%100000007;
    return table[n];
}
int main(){
    int n;
    cin >> n;
    vector<long long>table(n);
    table[0] = 3;
    long long ans = f(n-1,table);
    cout << ans;
    return 0;
}