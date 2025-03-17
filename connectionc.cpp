#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    int n,e,k;
    cin >> n >> e >> k;
    vector<vector<int>>g(n);
    for (int i = 0;i<e;i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int answer = -1000000;
    for (int i = 0;i<n;i++){
        queue<pair<int,int>>q;
        q.push(make_pair(i,0));
        int total = 1;
        vector<bool>v(n);
        v[i] = true;
        while (!q.empty()){
            pair<int,int>p = q.front();
            q.pop();
            for (auto & e:g[p.first]){
                if (!v[e] && p.second+1 <= k){
                    v[e] = true;
                    total++;
                    q.push(make_pair(e,p.second+1));
                }
            }
        }
        answer = max(total,answer);
    }    
    cout << answer;

    return 0;
}
