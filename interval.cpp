#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int count = 0;
    pair<int,int> p = make_pair(0,0);
    vector<int>s(n+1);
    vector<int>e(n+1);
    vector<pair<int,int>>v(n+1);
    for (int i = 1;i<=n;i++)cin >> s[i];
    for (int i = 1;i<=n;i++)cin >> e[i];
    for (int i = 1;i<=n;i++){v[i].first = e[i];v[i].second = s[i];}
    sort(v.begin(),v.end());
    for (int i = 1;i<=n;i++){
        if (v[i].second < p.first)continue;
        count++;
        p.first = v[i].first;
        p.second = v[i].second;
    }
    cout << count;
    return 0;
}