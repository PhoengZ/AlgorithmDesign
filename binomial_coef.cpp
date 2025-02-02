#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int>v(n);
    for (int i = 0;i<n;i++)cin >> v[i];
    sort(v.begin(),v.end());
    for (int i =0;i<m;i++){
        long long q;
        cin >> q;
        if (q <= n){cout << 0 <<endl;continue;}
        long long left = 1;
        long long right = (q-1)*v[0];
        while (left < right){
            long long mid = left + (right - left)/2;
            long long total = n;
            for (int j =0;j<n;j++){
                total+= mid/v[j]; 
            }
            if (total >= q)right = mid;
            else left = mid+1;
        }
        cout << right <<endl;
    }
}