#include <iostream>
#include <vector>

using namespace std;

int mcs(vector<int>&v, vector<int>&prefix_sum, int start, int stop,int n){
    if (start == stop)return v[start];
    int mid = start + (stop-start)/2;
    int left = mcs(v,prefix_sum,start,mid,n);
    int right = mcs(v,prefix_sum,mid+1,stop,n);
    int max_l = prefix_sum[mid] - prefix_sum[start-1];
    int max_r = prefix_sum[mid] - prefix_sum[mid];
    int l = left > right ? left : right;
    for (int i = start;i<=mid;i++){
        int m = prefix_sum[mid] - prefix_sum[i-1];
        if (m > max_l){
            max_l = m;
        }
    }
    for (int i = mid;i<=stop;i++){
        int m = prefix_sum[i] - prefix_sum[mid];
        if (m > max_r)max_r = m;
    }
    l = l > max_l + max_r ? l : max_l + max_r;
    if (start == 1 && stop == n){
        int s = 0;
        max_l = prefix_sum[stop] - prefix_sum[0];
        max_r = 0;
        for (int i = start;i<=stop;i++){
            int m = prefix_sum[stop] - prefix_sum[i-1];
            if (m > max_l){
                max_l = m;
                s = i;
            }
        }
        for (int i = start;i<=s;i++){
            int m = prefix_sum[i] - prefix_sum[start-1];
            if (m > max_r)max_r = m;
        }
        l = l > max_l + max_r ? l : max_l + max_r;
        bool first = true;
        for (int i = start; i<=stop;i++){
            int m = prefix_sum[i] - prefix_sum[start-1];
            if (first){
                max_l = m;
                first = false;
                s = i;
            }else{
                if (m > max_l){
                    max_l = m;
                    s = i;
                }
            }
        }
        first = true;
        for (int i = s;i<=stop;i++){
            int m = prefix_sum[stop] - prefix_sum[i];
            if (first){
                max_r = m;
                first = false;
            }else{
                if (m > max_r)max_r = m;
            }
        }
        l = l > max_l + max_r ? l : max_l + max_r;
        
    }
    
    return l;
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
    //for (int i =1;i<=n;i++){
    //    v.push_back(v[i]);
    //    prefix_sum.push_back(prefix_sum.back() + v.back());
    //}
    int a = mcs(v,prefix_sum,1,n,n);
    cout << a;
    return 0;
}

