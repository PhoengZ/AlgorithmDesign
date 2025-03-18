#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,e,s;
    cin >> n >> e >>s;
    vector<vector<int>>g(n);
    vector<vector<int>>weight(n,vector<int>(n));
    vector<pair<int,int>>edge(e);
    for (int i = 0;i<e;i++){
        int a,b,c;
        cin >> a >> b >> c;
        weight[a][b] = c;
        g[a].push_back(b);
        edge[i] = {a,b};
    }
    vector<int>sol(n,1000000);
    sol[s] = 0;
    for (int i = 1;i<n;i++){
        for (auto & e:edge){
            sol[e.second] = min(sol[e.first] + weight[e.first][e.second],sol[e.second]);
        }
    }
    bool check = false;
    for (auto & e:edge){
        if (sol[e.second] > sol[e.first] + weight[e.first][e.second]){
            check = true;
            break;
        }
    }
    if (check){
        cout << -1;
    }else{
        for (int i = 0;i<n;i++){
            cout << sol[i] << " ";
        }
    }
    
    return 0;
}