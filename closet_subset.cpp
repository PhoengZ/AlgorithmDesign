#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int target;
int target1;
int k;

void f(vector<int>&v, vector<bool>&sel, int total, int now, int count, int&ans){
    if (count == target){
        ans = min(ans,abs(total-k));
        return ;
    }
    if (total >= k && ans < abs(total-k))return ;
    if (target1 - now + count < target)return ;
    sel[now] = true;
    f(v,sel,total+v[now],now+1,count+1,ans);
    sel[now] = false;
    f(v,sel,total,now+1,count,ans);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m >> k;
    target = m;
    target1 = n;
    vector<int>v(n);
    vector<bool>sel(n);
    for (int i =0;i<n;i++){
        cin >> v[i];
    }
    sort(v.rbegin(),v.rend());
    int ans = 1000000000;
    f(v,sel,0,0,0,ans);
    cout << ans;
    return 0;
}