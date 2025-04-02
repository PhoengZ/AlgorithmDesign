#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); 
    int r,c;
    cin >> r >> c ;
    vector<vector<int>>g(r,vector<int>(c));
    map<pair<int,int>,int>m;
    int start = 0;
    int ans = 0;
    vector<pair<int,int>>s;
    for (int i = 0;i<r;i++){
        for (int j = 0;j<c;j++){
            cin >> g[i][j];
            if (g[i][j] == 2){
                s.push_back({i,j});
                start++;
            }
        }
    }
    vector<vector<bool>>t(r,vector<bool>(c));
    vector<vector<vector<int>>>dist(start,vector<vector<int>>(r,vector<int>(c))),sel(start,vector<vector<int>>(r,vector<int>(c)));
    vector<vector<int>>v = {{1,0},{-1,0},{0,1},{0,-1}};
    for (int i = 0;i<start;i++){
        queue<vector<int>>q;
        q.push({0,s[i].first,s[i].second});
        sel[i][s[i].first][s[i].second] = true;
        while(!q.empty()){
            vector<int> p = q.front();
            q.pop();
            for (int k = 0;k<4;k++){
                int row = p[1]+v[k][0];
                int col = p[2]+v[k][1];
                if (row < 0 || col < 0 || row >= r ||  col >= c)continue;
                if (g[row][col] == 1)continue;
                if (!sel[i][row][col]){
                    dist[i][row][col] = p[0]+1;
                    sel[i][row][col] = true;
                    q.push({dist[i][row][col],row,col});
                }
            }
        }
    }
    for (int i = 0;i<r;i++){
        for (int j =0;j<c;j++){
            bool check = true;
            int c = dist[0][i][j];
            if (!sel[0][i][j])continue;
            for (int k = 0;k<start;k++)c = min(c,dist[k][i][j]);
            for (int k = 0;k<start;k++){
                if (!sel[k][i][j]){
                    check = false;
                    break;
                }
                if (abs(c-dist[k][i][j]) > 1 ){
                    check = false;
                    break;
                }
            }
            if (check){
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}