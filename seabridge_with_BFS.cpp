#include<iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int r,c;
    cin >> r >> c;
    vector<vector<int>>g(r,vector<int>(c));
    vector<vector<bool>>sel(r,vector<bool>(c));
    vector<vector<int>>dis(r,vector<int>(c,10000000));
    queue<pair<int,pair<int,int>>>s;
    for (int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            cin >> g[i][j];
            if (g[i][j] == 1){
                s.push({1,{i,j}});
            }
        }
    }
    while (!s.empty()){
        pair<int,pair<int,int>> p = s.front();
        s.pop();
        int a = p.second.first;
        int b = p.second.second;
        if (g[a][b] == 2){
            cout << p.first;
            break;
        }
        pair<int,pair<int,int>> del;
        if (a+1 < r && g[a+1][b] != 3 && !sel[a+1][b]){
            del = {p.first+1,{a+1,b}};
            sel[a+1][b] = true;
            s.push(del);
        }
        if (a-1 >= 0 && g[a-1][b] != 3 && !sel[a-1][b] && dis[a-1][b] > p.first+1){
            del = {p.first+1,{a-1,b}};
            sel[a-1][b] = true;
            s.push(del);
        }
        if (b+1 < c && g[a][b+1] != 3 && !sel[a][b+1] && dis[a][b+1] > p.first+1){
            del = {p.first+1,{a,b+1}};
            sel[a][b+1] = true;
            s.push(del);
        }
        if (b-1 >= 0 && g[a][b-1] != 3 && !sel[a][b-1] && dis[a][b-1] > p.first+1){
            del = {p.first+1,{a,b-1}};
            sel[a][b-1] = true;
            s.push(del);
        }
    }
    return 0;
} 