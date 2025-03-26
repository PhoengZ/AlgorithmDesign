#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int r,c,k;
    cin >> r >> c  >>k;
    queue<vector<int>>s;
    vector<vector<bool>>sel(r,vector<bool>(c));
    vector<vector<int>>d = {{1,0},{-1,0},{0,1},{0,-1}},g(r,vector<int>(c));
    for (int i = 0;i<r;i++){
        for (int j = 0;j<c;j++){
            cin >> g[i][j];
            if (g[i][j] == 1){
                s.push({k,i,j});
            }
        }
    }
    while(!s.empty()){
        vector<int>v = s.front();
        s.pop();
        sel[v[1]][v[2]] = true;
        if (v[0] == 0){
            continue;
        }
        for (int i =0;i<4;i++){
            int a = v[1] + d[i][0];
            int b= v[2]+d[i][1];
            if (a < 0 || b < 0 || a >=r || b >= c)continue;
            if (g[a][b] != 1 && g[a][b] != 2){
                g[a][b] = 2;
                s.push({v[0]-1,a,b});
            }
        }
    }
    for (int i = 0;i<r;i++){
        for (int j =0;j<c;j++){
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}