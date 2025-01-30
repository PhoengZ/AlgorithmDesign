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

/*#include <iostream>
#include <unordered_map>

using namespace std;

pair<long long,long long> f(unordered_map<int,int>&u, int l, int r,int A, int B){
    if (l == r)return u[l] == 0 ? make_pair(A,0): make_pair(B*u[l],u[l]);  
    long long number = 0;
    bool found = false;
    long long mid = l + (r-l)/2;
    pair<long long,long long> left = f(u,l,mid,A,B);
    pair<long long,long long> right = f(u,mid+1,r,A,B);
    long long MAX = left.second + right.second != 0 ? (left.second + right.second)*(r-l+1)*B:A;
    return right.first+left.first < MAX ? make_pair(right.first+left.first,left.second + right.second):make_pair(MAX,left.second + right.second);
}

int main(){
    int p,k,a,b;
    cin >> p >> k >> a >> b;
    int stop = 1<<p;
    unordered_map<int,int>u;
    for (int i = 0;i<k;i++){
        int idx;
        cin >> idx;
        u[idx]++;
    }
    pair<long long,long long> A = f(u,1,stop,a,b);
    cout << A.first;
    return 0;
}*/

