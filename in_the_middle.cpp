#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int n;
    cin >> n;
    queue<vector<int>>q;
    vector<int>t(3);
    vector<int>m(3);
    vector<vector<int>>g(n+1);
    vector<bool>sel(n+1);
    m[0] = m[2] = 1;
    for(int i = 0;i<3;i++){
        cin >> t[i];
        q.push({t[i],0,i});
        sel[t[i]] = true;
    }
    for (int i = 1;i<=n;i++){
        int a;
        cin >> a;
        for (int j = 0;j<a;j++){
            int x;
            cin >> x;
            g[i].push_back(x);
        }
    }
    while(!q.empty()){
        vector<int>v = q.front();
        q.pop();
        for(auto & e:g[v[0]]){
            if (!sel[e]){
                m[v[2]]++;
                sel[e] = true;
                q.push({e,v[1]+1,v[2]});
            }
        }
    }
    int answer = max(m[0],max(m[1],m[2]));
    cout << answer;
    return 0;
}