#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    vector<int>start(k);
    vector<vector<int>>g(n+1),w(n+1,vector<int>(n+1));
    for (int i = 0;i<k;i++)cin >> start[i];
    for (int i = 0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        g[a].push_back(b);
        g[b].push_back(a);
        w[a][b] = w[b][a] = c;
    }
    for (auto & e:start){
        set<pair<int,int>>s;
    }
    return 0;
}