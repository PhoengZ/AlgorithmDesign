#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int n,a,b;
    cin >> n >> a >> b;
    queue<pair<int,int>>q;
    vector<vector<int>>g(1001,vector<int>(1001));
    vector<vector<int>>sel(1001,vector<int>(1001)),total(1001,vector<int>(1001));
    for (int i =0;i<n;i++){
        int x,y;
        cin >> x >> y;
        g[x][y] = 1;
    }
    vector<vector<int>>d = {{1,0},{-1,0},{0,1},{0,-1}};
    q.push({a,b});
    sel[a][b] = 1;
    while(!q.empty()){
        pair<int,int>p = q.front();
        q.pop();
        for (int i = 0;i<4;i++){
            int x = p.first+d[i][0];
            int y=  p.second+d[i][1];
            if (x <= 0 || x > 1000 || y <= 0 || y > 1000)continue;
            if (sel[x][y] == 1)continue;
            if (g[x][y] == 1){
                total[x][y] = total[p.first][p.second]+1;
            }else{
                total[x][y] = total[p.first][p.second];
            }
            sel[x][y] = 1;
            q.push({x,y});
        }
    }
    int answer = 1000000;
    for (int i = 1;i<=1000;i++){
        answer = min(answer,total[1][i]);
        answer = min(answer,total[i][1000]);
        answer = min(answer,total[1000][i]);
        answer = min(answer,total[i][1]);
    }
    cout << answer;
    return 0;
}