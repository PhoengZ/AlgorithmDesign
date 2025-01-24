#include <iostream>
#include <vector>

using namespace std;

int mcs(vector<int>&v, vector<int>&s, int start, int stop , int w){
    if (start == stop)return v[start];
    int mid = start + (stop-start)/2;
    int left = mcs(v,s,start,mid,w);
    int right = mcs(v,s,mid+1,stop,w);
    int real_l,l;
    l = real_l = max(start,mid-w+1);
    int max_l = s[mid] - s[l-1];
    for (int i = l;i<=mid;i++){
        int m = s[mid] - s[i-1];
        if (m > max_l){max_l = m;real_l = i;}
    }
    real_l = mid-real_l + 1;
    int r = min(mid-real_l+w,stop);
    int max_r = s[r]-s[mid];
    for (int i = r;i >= mid+1;i--){
        int m = s[i] - s[mid];
        if (m > max_r){max_r = m;}
    }
    int start_left = max_l + max_r;
    l = real_l = min(stop,mid+w);
    max_r = s[l] -s[mid];
    for (int i = l;i>=mid+1;i--){
        int m = s[i] - s[mid];
        if (m > max_r){max_r = m;real_l = i;}
    }
    real_l = real_l - mid;
    r = max(mid-w + real_l + 1,start);
    max_l = s[mid]-s[r];
    for (int i = r;i <= mid;i++){
        int m = s[mid] - s[i-1];
        if (m > max_l){max_l = m;}
    }
    int start_right = max_l + max_r;
    int c = start_left > start_right ? start_left : start_right;
    int out = left > right ? left :right;
    return max(out,c);
}

int main(){
    int n,w;
    cin >> n >> w;
    vector<int>v(n+1);
    vector<int>s(n+1);
    for (int i =1;i<=n;i++){
        cin >> v[i];
        s[i]+= s[i-1]+v[i];
    }
    int a;
    if (w == 0)a = 0;
    else a = mcs(v,s,1,n,w);
    cout << a;
    return 0;
}