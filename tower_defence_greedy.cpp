#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m,k,w;
    cin >> n >> m >> k >> w;
    vector<pair<int,int>>monster(m+1);
    vector<int>sel(n+1);
    map<int,int>m_h;
    vector<pair<int,int>>health;
    int total = 0;
    for (int i = 1;i<=m;i++)cin >> monster[i].first;
    for (int i = 1;i<=m;i++){
        cin >> monster[i].second;
        m_h[monster[i].first]+=monster[i].second;
        total+=monster[i].second;
    }
    for (auto & e:m_h){
        health.push_back(make_pair(e.first,e.second));        
    }
    sort(health.begin(),health.end());
    int idx = 0;
    int left = health[idx].first-w <= 0 ? 1: health[idx].first-w;
    int right = health[idx].first+w >= n ? n:health[idx].first+w;
    for (int i = 1;i<=k && i <= n ;i++){
        while (left <= n && left <= right && sel[left] == 1)left++;
        if (left > right || left > n ||  health[idx].second == 0){
            idx++;
            if (idx > health.size()-1)break;
            left = health[idx].first-w <= 0 ? 1: health[idx].first-w;
            while (left <= n && left <= right && sel[left] == 1)left++;
            right = health[idx].first+w >= n ? n:health[idx].first+w;
            while(right >= 0 && left <= right && sel[right] == 1)right--;   
        }
        total--;
        // cout << "total now: " << total << " now i " << i << " now left and right: " << left << " " << right << endl;
        sel[left++] = 1;
        health[idx].second--;
    }
    cout << total;
    return 0;
}