#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long f(vector<long long>&u, long long l, long long r,int A, int B){
    long long number = (upper_bound(u.begin(),u.end(),r) - u.begin()) - (lower_bound(u.begin(),u.end(),l) - u.begin());
    if (number == 0)return A;
    long long MAX = number*(r-l+1)*B;
    if (l == r)return MAX;
    long long mid = l + (r-l)/2;
    long long left = f(u,l,mid,A,B);
    long long right = f(u,mid+1,r,A,B);
    return MAX < left + right ? MAX:left+right;
}

int main(){
    long long p,k,a,b;
    cin >> p >> k >> a >> b;
    int stop = 1<<p;
    vector<long long>u(k+1);
    for (int i = 1;i<=k;i++){
        long long idx;
        cin >> idx;
        u[i] = idx;
    }
    sort(u.begin(),u.end());
    long long A = f(u,1,stop,a,b);
    cout << A;
    return 0;
}

