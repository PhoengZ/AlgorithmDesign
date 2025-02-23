#include <iostream>
#include<vector>
#include <algorithm>

using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n,q;
    cin >> n >> q;
    vector<pair<int,int>>v(n+1);
    vector<int>p(n+1);
    for (int i = 1;i<=n;i++){
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(),v.end());
    for (int i = 1;i<=n;i++){
        p[i] += p[i-1] + v[i].second;
    }
    for (int i = 1;i<=q;i++){
        int c;
        cin >> c;
        int idx = lower_bound(p.begin(),p.end(),c) - p.begin();
        cout << v[idx].first <<endl;
    }
    return 0;
}