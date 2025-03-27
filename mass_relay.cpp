#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

pair<int,int> fr(int u, vector<int>&parent){
    int count = 0;
    while(parent[u] != -1){
        u = parent[u];
        count++;
    }
    return {u,count};
}

bool j(int u, int v, vector<int>&parent){
    pair<int,int> a = fr(u,parent);
    pair<int,int> b = fr(v,parent);
    if (a.first != b.first){
        if (a.second > b.second){
            parent[b.first] = a.first;
        }else{
            parent[a.first] = b.first;
        }
        return true;
    }else{
        return false;
    }
}


int main(){
    int n,m,q;
    cin >> n >> m >> q;
    vector<vector<int>>g(m,vector<int>(3));
    vector<int>parent(n,-1);
    vector<int>sol(n);
    int t = n-1;
    for (int i  =0;i<m;i++){
        cin >> g[i][1] >> g[i][2] >> g[i][0];
    }
    sort(g.begin(),g.end());
    for (auto & e:g){
        if (j(e[1],e[2],parent)){
            sol[t--] = e[0];
        }
    }
    for (int i = 0;i<q;i++){
        int e;
        cin >> e;
        cout << sol[e] << endl;
    }
    return 0;
}