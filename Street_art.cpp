#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int p(vector<long long>&vp, long long a, long long b, long long c){
    long long u = (c-b+1)/3;
    long long v = (c-b+2)/3;
    auto low_1 = lower_bound(vp.begin(),vp.end(),b);
    auto up_1 = upper_bound(vp.begin(),vp.end(),c);
    int total = up_1 - low_1;
    if (total == 0)return 0;
    if (c-b+1 < 3)return total;
    int ps1 = p(vp,a+1,b,b+u-1);
    int ps2 = p(vp,a+2,b+u,b+u+v-1);
    int ps3 = p(vp,a+3,b+u+v,c);
    return total + ps1 + ps2 + ps3 - min(min(ps1,ps2),ps3);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    long long n,w;
    cin >> w >> n;
    vector<long long> v(n+1);
    for (int i = 1;i<=n;i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    int ans = p(v,0,1,w);
    cout << ans;
    return 0;
}