#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main(){
    int n;
    cin >> n;
    int target = n-1;
    int mpath = 0;
    vector<vector<int>>w(n,vector<int>(n)),g(n);
    vector<bool>s(n);
    s[0] = true;
    for (int i = 0;i<n;i++){
        for (int j =0;j<n;j++){
            cin >> w[i][j];
            if (w[i][j] != 0)g[i].push_back(j);
            mpath = max(mpath,w[i][j]);
        }
    }
    priority_queue<pair<int,pair<int,vector<bool>>>>p;
    p.push(make_pair(0,make_pair(0,s)));
    int ans = 0;
    while(!p.empty()){
        auto t = p.top();
        p.pop();
        int count = 0;
        for (int i =0;i<n;i++){
            if (!t.second.second[i])count++;
        }
        if (t.second.first == target && count == 0){
            cout << t.first;
            return 0;
        }
        if (t.second.first == target && count >= 1){
            continue;
        }
        if (t.first + count*mpath < ans)continue;
        for (auto & e:g[t.second.first]){
            if (!t.second.second[e]){
                t.second.second[e] = true;
                p.push(make_pair(t.first + w[t.second.first][e],make_pair(e,t.second.second)));
                t.second.second[e] = false;
            }
        }
    }
    cout << ans;
    return 0;
}