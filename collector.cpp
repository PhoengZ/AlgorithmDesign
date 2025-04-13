#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int target;





void f(int now, int &ans, int total, vector<bool>&sel,vector<int>&p, vector<vector<int>>&v, vector<vector<int>>&o){
    if (now == target){
        ans = min(total,ans);
        return ;
    }
    if (sel[now]){
        f(now+1,ans,total,sel,p,v,o);
        return ;
    }
    if (total >= ans)return ;
    for (auto &i:v[now]){
        if (total + p[i] >= ans)continue;
        vector<int>t;
        for (auto &e:o[i]){
            if (!sel[e])t.push_back(e);
            sel[e] = true;
        }
        f(now+1,ans,total+p[i],sel,p,v,o);
        for (auto &e:t){
            sel[e] = false;
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n,k;
    cin >> n >> k;
    target = n+1;
    vector<bool>sel(n+1);
    vector<int>p(k);
    vector<vector<int>>v(n+1),o(k);
    int ans = 100000000;
    for (int i = 0;i<k;i++){
        int a;
        cin >> p[i] >> a;
        for (int j = 0;j<a;j++){
            int b;
            cin >> b;
            v[b].push_back(i);
            o[i].push_back(b);
        }
    }
    f(1,ans,0,sel,p,v,o);
    cout << ans;
    return 0;
}