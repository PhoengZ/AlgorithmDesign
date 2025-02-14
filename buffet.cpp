#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,m;
    cin  >> n >> k >> m;
    vector<int>v(n+1);
    vector<int>p(n+1);
    for (int i = 1;i<=n;i++){
        cin >> v[i];
        p[i]+= p[i-1]+v[i];
    }
    for (int i =0;i<k;i++){
        int a,b,total,left,right;
        cin >> a >> b;
        left = a;
        right = n;
        while (left < right){
            int mid = left + (right-left)/2;
            total = (p[mid] - p[a-1]) - (mid-a+1)*m;
            if (total >= b)right = mid;
            else left = mid+1;
        }
        cout << right << "\n";
    }
    return 0;
}