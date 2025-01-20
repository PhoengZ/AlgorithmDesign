#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long sum_value(long long check,vector<int> &v){
    long long sum = 0;
    for (auto & e:v){
        sum += check/e;
    }
    return sum;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i =0;i<n;i++)cin >> v[i];
    sort(v.begin(),v.end());
    for (int i =0;i<m;i++){
        long long a;
        cin >> a;
        if (a-n <= 0){cout << 0 <<endl;continue;}
        long long t = a-n;
        long long left = 1;
        long long right = v[0] * t;
        while (left < right){
            long long mid = left + (right-left)/2;
            long long val = sum_value(mid,v);
            if (t <= val){
                right = mid;
            }else{
                left = mid+1;
            }
        }
        cout << left <<endl;
        
    }
    return 0;
}