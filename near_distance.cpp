#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    int r,c,k;
    cin >> r >> c >> k;
    vector<vector<int>>g(r,vector<int>(c));
    vector<pair<int,int>>start;
    for (int i = 0;i<r;i++){
        for (int j = 0;j<c;j++){
            cin >> g[i][j];
            if (g[i][j] == 2){
                start.push_back({i,j});
            }
        }
    }
    vector<vector<int>>dir = {{1,0},{-1,0},{0,1},{0,-1}};
    vector<vector<vector<bool>>>sel(start.size(),vector<vector<bool>>(r,vector<bool>(c)));
    vector<vector<vector<int>>>dis(start.size(),vector<vector<int>>(r,vector<int>(c,-1)));
    vector<vector<int>>dm(r,vector<int>(c,100000000));
    for (int i = 0;i<start.size();i++){
        int x = start[i].first;
        int y = start[i].second;
        queue<pair<int,int>>q;
        q.push({x,y});
        sel[i][x][y] = true;
        dis[i][x][y] = 0;
        dm[x][y] = min(dm[x][y],dis[i][x][y]);
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            for (auto & e:dir){
                int nx = p.first + e[0];
                int ny = p.second + e[1];
                if (nx < 0 || nx >= r || ny < 0 || ny >= c)continue;
                if (g[nx][ny] == 1)continue;
                if (sel[i][nx][ny])continue;
                sel[i][nx][ny] = true;
                dis[i][nx][ny] = dis[i][p.first][p.second] + 1;
                dm[nx][ny] = min(dm[nx][ny],dis[i][nx][ny]);
                q.push({nx,ny});
            }
        }   
    }
    int total = 0;
    for (int i = 0;i<r;i++){
        for (int j = 0;j<c;j++){
            bool c = true;
            for (int e = 0;e<start.size();e++){
                if (dis[e][i][j] == -1 || !sel[e][i][j] || abs(dm[i][j] - dis[e][i][j]) > k){
                    c = false;
                    break;
                }
            }
            if (c)total++;
        }
    }
    cout << total;
    return 0;
}