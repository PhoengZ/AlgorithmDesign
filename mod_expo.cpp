#include <iostream>

using namespace std;

int mod(int a, int k, int n){
    if (n == 1)return a%k;
    int temp = mod(a,k,n/2);
    temp = (temp*temp)%k;
    if (n%2 == 0)return temp;
    return (temp * (a%k))%k;
}

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    int b = mod(n,k,m);
    cout << b;
    return 0;
}