#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int c(vector<pair<int,int>>&x, int left, int right){
    if (right - left  <= 2){
        int dif = (x[right].first-x[left].first)*(x[right].first-x[left].first) + (x[right].second-x[left].second)*(x[right].second-x[left].second);
        if (right - left == 1)return dif;
        int dif_1 = (x[right-1].first-x[left].first)*(x[right-1].first-x[left].first) + (x[right-1].second-x[left].second)*(x[right-1].second-x[left].second); 
        int dif_2 = (x[right].first-x[left+1].first)*(x[right].first-x[left+1].first) + (x[right].second-x[left+1].second)*(x[right].second-x[left+1].second);
        dif = dif_1 < dif ? dif_1:dif;
        dif = dif_2 < dif ? dif_2:dif;
        return dif;
    }
    int mid = left + (right-left)/2;
    int l = c(x,left,mid);
    int r = c(x,mid+1,right);
    int MIN = l < r ? l:r;
    vector<pair<int,int>> vx;
    vector<pair<int,int>> vy;
    for (int i = left;i<=mid;i++){
        if (x[mid].first - MIN <= x[i].first)vx.push_back({x[i].second,x[i].first});
    }
    for (int i = mid+1;i<=right;i++){
        if (x[mid].first + MIN >= x[i].first)vy.push_back({x[i].second,x[i].first});
    }
    sort(vx.begin(),vx.end());
    sort(vy.begin(),vy.end());
    int start = 0;
    int stop = vy.size();
    for (int i = 0;i < vx.size();i++){
        for (int j = start;j<stop;j++){
            if (vx[i].second - MIN > vy[j].second){
                start = j;
            }
            if (vx[i].second + MIN < vy[j].second){
                break;
            }
            int dif = (vx[i].first-vy[j].first)*(vx[i].first-vy[j].first) + (vx[i].second-vy[j].second)*(vx[i].second-vy[j].second);
            MIN = dif < MIN ? dif : MIN;
        }
    }
    return MIN;
}

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> vp(n+1);
    for (int i =0;i<n;i++){
        int x,y;
        cin >> x >> y;
        vp[i].first = x;
        vp[i].second = y;
    }
    sort(vp.begin(),vp.end());
    int ans = c(vp,1,n);
    cout << ans ;
    return 0;
}