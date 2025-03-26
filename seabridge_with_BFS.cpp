#include<iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int r,c;
    cin >> r >> c;
    queue<pair<int,int>>q;
    vector<vector<int>>g(r,vector<int>(c)),sel(r,vector<int>(c)),dis(r,vector<int>(c,1));
    vector<vector<int>>d = {{1,0},{-1,0},{0,1},{0,-1}};
    for (int i =0;i<r;i++){
        for (int j = 0;j<c;j++){
            cin >> g[i][j];
            if (g[i][j] == 1){
                q.push({i,j});
                sel[i][j] = true;
            }
            if (g[i][j] == 3)sel[i][j] = true;
        }
    }
    while(!q.empty()){
        pair<int,int> p = q.front();
        q.pop();
        for (int i = 0;i<4;i++){
            int a = p.first+d[i][0];
            int b = p.second+d[i][1];
            if (a < 0 || b < 0 || a >= r || b >= c)continue;
            if (g[a][b] == 2){
                cout << (dis[p.first][p.second]+1);
                return 0;
            }
            if (!sel[a][b]){
                sel[a][b] = true;
                dis[a][b] = dis[p.first][p.second] + 1;
                q.push({a,b});
            }
        }
    }
    return 0;
} 