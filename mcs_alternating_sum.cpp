#include <iostream>
#include <vector>
using namespace std;

int f(int start, int stop, vector<int>&v, vector<int>&p){
    if (start == stop)return v[start];
    int mid = start + (stop-start)/2;
    int left = f(start,mid,v,p);
    int right = f(mid+1,stop,v,p);
    int max_l = p[mid] - p[start - 1];
    bool neg = false;
    bool first = true;
    if (start %2 == 0){
        neg = true;
        max_l *= -1;
    }
    int max_r = 0;
    if ((mid+1)%2 == 0)max_r = -1 * v[mid+1];
    for (int i = start;i<=mid;i++){
        if (i%2 == 0){
            if (-1 * (p[mid] - p[i-1]) > max_l){
                max_l = -1 * (p[mid] - p[i-1]);
                neg = true;
            }else{
                max_l = max_l;
            }
        }else{
            if (p[mid] -  p[i-1] > max_l){
                neg =false;
                max_l = p[mid] -  p[i-1];
            }else{
                max_l = max_l;
            }
        }
    }
    for (int i = mid+1;i<=stop;i++){
        if (first){
            if (neg) max_r = -1 * (p[i] - p[mid]);
            else max_r = (p[i] - p[mid]);
            first = false;
        }else{
            if (neg)max_r = max(max_r,-1 * (p[i] - p[mid]));
            else max_r = max(max_r,(p[i] - p[mid]));
        }
        
    }
    return max(max_l+max_r,max(left,right));
}


int main(){
    int n;
    cin >> n;
    vector<int>v(n+1);
    vector<int>p(n+1);
    int count_1 = 0;
    for (int i = 1;i<=n;i++){
        cin >> v[i];
        if (count_1 == 0){
            p[i] = p[i-1] + v[i];
        }else{
            p[i] = p[i-1] - v[i];
        }
        count_1++;
        count_1 = count_1%2;
    }
    int ans = f(1,n,v,p);
    cout << ans;
    return 0;
}