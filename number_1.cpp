#include <iostream>
#include <vector>

using namespace std;

long long len(int n){
    if (n <= 1)return 1;
    return 1+2*(len(n/2));
}

long long f(int n, int l, int r){
    if (n == 1)return 1;
    if (n == 0)return 0;
    if (l > r)return 0;
    int m = len(n/2);
    if (r < m+1)return f(n/2,l,r);
    if (l > m+1)return f(n/2,l-m-1,r-m-1);
    if (r == m+1)return n%2 + f(n/2,l,r-1);
    if (l == m+1)return n%2 + f(n/2,1,r-m-1);
    return n%2 + f(n/2,l,m) + f(n/2,1,r-m-1);
}

int main(){
    int n,l,r;
    cin >> n >> l >> r;
    long long le = len(n);
    cout << f(n,l,r);    
    return 0;
}