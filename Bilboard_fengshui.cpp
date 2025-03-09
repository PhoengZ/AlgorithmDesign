#include <iostream>
#include <vector>
using namespace std;

int f(int n, int k, vector<int>&table, vector<int>&a, vector<int>&v){
    if (n <= 0)return -10000000;
    if (n == 1)return a[n];
    
}

int main(){
    int n,k;
    cin >> n >> k;
    vector<int>table(n+1);
    vector<int>a(n+1);
    vector<int>v(k+1);
    for (int i = 1;i<=n;i++)cin >> a[i];
    for (int i = 1;i<=k;i++)cin >> v[i];
    return 0;
}