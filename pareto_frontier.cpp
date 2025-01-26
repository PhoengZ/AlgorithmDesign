#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<pair<int,int>> pareto(int l,int r,vector<pair<int,int>>&v){
    if(l == r){
        vector<pair<int,int>> r(1);
        r[0] = v[l];
        return r;
    }
    int mid = l + (r-l)/2;
    vector<pair<int,int>> left = pareto(l,mid,v);
    vector<pair<int,int>> right = pareto(mid+1,r,v);
    int m_y = right[0].second;
    vector<pair<int,int>> vp;
    for (int i = 1;i<right.size();i++){
        if (right[i].second > m_y){
            m_y = right[i].second;
        }
    }
    for (int i = 0;i<left.size();i++){
        if (left[i].second > m_y){
            vp.push_back(left[i]);
        }
    }
    for (int i =0 ;i<right.size();i++){
        vp.push_back(right[i]);
    }
    return vp;
}
int main(){
    int n;
    cin >>n;
    vector<pair<int,int>> vx(n+1);
    for (int i = 1;i<=n;i++){
        int x,y;
        cin >> x >> y;
        vx[i] = {x,y};
    }
    sort(vx.begin(),vx.end());
    vector<pair<int,int>> v = pareto(1,n,vx);
    cout << v.size();
    return 0;
}