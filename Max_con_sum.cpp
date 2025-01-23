#include <iostream>
#include <vector>
using namespace std;

int subSequence(vector<int>&v, vector<int>& sum, int start, int stop){
    if (start == stop)return v[start];
    int mid = start + (stop-start)/2;
    int left = subSequence(v,sum,start,mid);
    int right = subSequence(v,sum,mid+1,stop);
    int m = max(left,right);
    int max_l = sum[mid] - sum[mid-1];
    for (int i = 1;i<=mid-1;i++){
        int m = sum[mid] - sum[i-1];
        if (m > max_l)max_l = m;
    } 
    int max_r = sum[mid+1] - sum[mid];
    for (int i = stop;i>= mid+1;i--){
        int m = sum[i] - sum[mid];
        if (m > max_r)max_r = m;
    }
    int real = max_r+max_l;
    return max(m,real);
}

int main(){
    int n;
    cin >> n;
    vector<int>v(n+1);
    vector<int> sum(n+1);
    for (int i =1;i<=n;i++)cin >> v[i];
    for (int i = 1;i<=n;i++)sum[i]+= sum[i-1] + v[i];
    cout << subSequence(v,sum,1,n);
    return 0;
}