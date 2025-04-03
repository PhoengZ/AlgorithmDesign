#include <iostream>
#include <vector>
using namespace std;

int target;

bool c(vector<bool>&sel, vector<int>&p, int now){
    int s = p.size();
    for (int i = 0;i<=now - s;i++){
        int idx = 0;
        bool check =true;
        for (int j = i;j<p.size()+i;j++){
            if (sel[j] != p[idx++]){
                check =false;
                break;
            }
        }
        if (check)return false;
    }
    return true;
}

void f(vector<int>&v, vector<int>&p, vector<int>&p0, vector<bool>&sel,int now, int total, int &ans, bool state){
    if (now == target){
        if (c(sel,p,now))ans = max(ans,total);
        return;
    }
    if (!c(sel,p,now))return ;
    if (p0.back() - p0[now] + total < ans)return ;
    if (!state){
        sel[now] = true;
        f(v,p,p0,sel,now+1,total+v[now],ans,true);
        sel[now] = false;
    }
    f(v,p,p0,sel,now+1,total,ans,false);

}

int main(){
    int n,k;
    cin >> n >> k;
    target = n;
    vector<int>v(n),p0(n+1);
    vector<int>p(k);
    vector<bool>sel(n);
    for (int i = 0;i<n;i++){
        cin >> v[i];
        p0[i+1]+=p0[i]+v[i];
    }
    for(int i = 0;i<k;i++)cin >> p[i];
    int ans = 0;
    f(v,p,p0,sel,0,0,ans,false);
    cout << ans;
    return 0;
}