#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


long long len(int n, unordered_map<long long, long long>&u){
    if (n <= 1){u[n] = 1;return 1;}
    long long l = 1+ 2*(len(n/2,u));
    u[n] = l;
    return u[n];
}

long long f(int n, int l, int r, unordered_map<long long, long long>&u){
    if (n == 1)return 1;
    if (n == 0)return 0;
    if (l > r)return 0;
    long long m = u[n/2];    
    if (r < m+1)return f(n/2,l,r,u);
    if (l > m+1)return f(n/2,l-m-1,r-m-1,u);
    if (r == m+1)return n%2 + f(n/2,l,r-1,u);
    if (l == m+1)return n%2 + f(n/2,1,r-m-1,u);
    return n%2 + f(n/2,l,m,u) + f(n/2,1,r-m-1,u);
}

int main(){
    int n,l,r;
    cin >> n >> l >> r;
    unordered_map<long long,long long> u;
    long long le = len(n,u);
    cout << f(n,l,r,u);    
    return 0;
}