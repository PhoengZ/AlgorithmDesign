#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    int r,c;
    cin >> r >> c;
    vector<vector<int>>g(r,vector<int>(c)),sel(r,vector<int>(c)),cost(r,vector<int>(c,1000000));
    for (int i = 0;i<r;i++){
        for (int j  =0;j<c;j++)cin >> g[i][j];
    }
    vector<vector<int>>d = {{1,0},{-1,0},{0,1},{0,-1}};
    set<vector<int>>s;
    s.insert({0,0,0});
    cost[0][0] = 0;
    while (!s.empty()){
        auto it = s.begin();
        vector<int>t = *it;
        sel[t[1]][t[2]] = true;
        s.erase(it);
        for (int i = 0;i<4;i++){
            int row = t[1] + d[i][0];
            int col = t[2] + d[i][1];
            if (row < 0 || row >= r || col < 0 || col >= c)continue;
            if (!sel[row][col] && cost[row][col] > t[0] + g[row][col]){
                s.erase({cost[row][col],row,col});
                cost[row][col] = t[0] + g[row][col];
                s.insert({cost[row][col],row,col});
            }
        }
    }
    for (int i  =0;i<r;i++){
        for (int j = 0;j<c;j++){
            cout << cost[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}