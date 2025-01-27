#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> v(n+1);
    vector<int>sum(n+1);
    for (int i = 1;i<=n;i++){
        cin >> v[i];
        sum[i]+=sum[i-1]+v[i];
    }
    for (int i =0;i<m;i++){
        long long start,target;
        cin >> start >> target;
        int left = 1;
        int right = n;
        long long total = 0;
        if (target <= k){
            cout << 0 << endl;
            continue;
        }
        if (target >= (right-start + 1)*k + sum[right]-sum[start]){
            cout << sum[right] - sum[start] <<endl;
            continue;
        }
        int count = 0;
        while (left < right){
            int mid = left + (right - left)/2;
            total = sum[mid] - sum[start] + (mid-start+1)*k;
            if (total == target)count = sum[mid] - sum[start];
            if (total >= target)right= mid;
            else{
                count = sum[mid] - sum[start];
                left = mid+1;
            }
        }
        if (left == right){
            total = sum[right] - sum[start] + (right-start)*k;
            if (total <= target){
                count = sum[right] - sum[start];
            }
        }
        cout << count << endl;
    }
    return 0;
}