#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    int r,c,t;
    cin >> r >> c >> t;
    vector<vector<int>>g(r,vector<int>(c));
    vector<vector<bool>>n(r,vector<bool>(c,false));
    queue<pair<pair<int,int>,int>>q;
    int total = 0;
    for (int i = 0;i<r;i++){
        for (int j = 0;j<c;j++){
            cin >> g[i][j];
            if (g[i][j] == 1){
                q.push(make_pair(make_pair(i,j),0));
                n[i][j] = true;
                total++;
            }
            if (g[i][j] == 2)n[i][j] = true;
        }
    }
    while (!q.empty()){
        pair<pair<int,int>,int> p = q.front();
        q.pop();
        if (p.second + 1 > t)continue;
        if (p.first.first - 1>= 0 &&!n[p.first.first-1][p.first.second]){
            q.push(make_pair(make_pair(p.first.first-1,p.first.second),p.second+1));
            n[p.first.first-1][p.first.second] = true;
            total++;
        }
        if (p.first.second - 1>= 0 && !n[p.first.first][p.first.second-1]){
            q.push(make_pair(make_pair(p.first.first,p.first.second-1),p.second+1));
            n[p.first.first][p.first.second-1] = true;
            total++;
        }
        if (p.first.first + 1 < r &&!n[p.first.first+1][p.first.second]){
            q.push(make_pair(make_pair(p.first.first+1,p.first.second),p.second+1));
            n[p.first.first+1][p.first.second] = true;
            total++;
        }
        if (p.first.second + 1 < c &&!n[p.first.first][p.first.second+1]){
            q.push(make_pair(make_pair(p.first.first,p.first.second+1),p.second+1));
            n[p.first.first][p.first.second+1] = true;
            total++;
        }
    }
    cout << total;
    return 0;
}