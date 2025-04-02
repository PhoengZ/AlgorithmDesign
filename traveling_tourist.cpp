#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    priority_queue<vector<int>,vector<vector<int>>,greater<>>p;
    vector<vector<int>>g(n+1),w(n+1,vector<int>(n+1));
    vector<int>found(k);
    for (int i = 0;i<k;i++){
        cin >> found[i];
        vector<int>g = {0,found[i]};
        p.push(g);
    }
        
    for(int i = 0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        g[a].push_back(b);
        g[b].push_back(a);
        w[a][b] = w[b][a] = c;
    }
    int answer = INT_MAX;
    while(!p.empty()){
        vector<int>t = p.top();
        p.pop();
    }
    return 0;
}