#include <iostream>
#include <vector>

using namespace std;

void solve(vector<int>& x,int l,int r,int& k) {
  if(k <= 0 || l == r-1) 
    return;
  else {
    int m = ((l+r) >> 1);
    if(k > 0) { swap(x[m-1],x[m]); k--; }
    solve(x,l,m,k);
    solve(x,m,r,k);
  }
}

int main(){
    int n,k;
    cin >> n >> k;
    if (k%2 == 0 || k  > 2*n - 1)cout << -1;
    else{
        vector<int>v(n);
        for (int i =0;i<n;i++)v[i] = i+1;
        int count = (k-1)/2;
        solve(v,0,n,count);
        for (auto & e:v)cout << e<< " ";
    }
    return 0;
}