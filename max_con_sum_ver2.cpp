#include <iostream>
#include <vector>

using namespace std;

pair<int,int> mcs(vector<int>&v, vector<int>&prefix_sum, int start, int stop,int n){
    if (start == stop)return {v[start],start};
    int mid = start + (stop-start)/2;
    pair<int,int> left = mcs(v,prefix_sum,start,mid,n);
    pair<int,int> right = mcs(v,prefix_sum,mid+1,stop,n);
    int max_l = prefix_sum[mid] - prefix_sum[mid-1];
    int count = mid;
    for (int i = start;i<mid-1;i++){
        int m =prefix_sum[mid] - prefix_sum[i-1];
        if (max_l < m){
            max_l = m;
            count = i;
        }
    }
    int max_r = left.second == 1 ? 0:prefix_sum[mid+1] - prefix_sum[mid];
    int r = start == 1 && stop == 2*n - 1 ? mid+count-1:stop;
    for (int i = r;i>mid+1;i--){
        int m = prefix_sum[i] - prefix_sum[mid];
        if (max_r < m)max_r = m;
    }
    int real = max_l + max_r;
    pair<int,int> out = left.first > right.first ? left:right;
    if (out.first < real){
        out.first = real;
        out.second = count;
    }
    return out;
}

int main(){
    int n;
    cin >> n;
    vector<int> v(1+n);
    vector<int> prefix_sum(n+1);
    for (int i = 1;i<=n;i++){
        cin >> v[i];
        prefix_sum[i]+= prefix_sum[i-1]+v[i];
    }
    for (int i =1;i<=n-1;i++){
        v.push_back(v[i]);
        prefix_sum.push_back(prefix_sum.back() + v.back());
    }
    pair<int,int> a = mcs(v,prefix_sum,1,2*n-1,n);
    cout << a.first;
    return 0;
}

