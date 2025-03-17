#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int r,c,k;
    cin >> r >> c >>k;
    vector<vector<int>>g(r,vector<int>(c));
    vector<vector<int>>dis(r,vector<int>(c,-1000000));
    vector<vector<bool>>sel(r,vector<bool>(c));
    set<pair<int,pair<int,int>>,greater<>>s;
    for (int i = 0;i<r;i++){
        for (int j = 0;j<c;j++){
            cin >> g[i][j];
            if (g[i][j] == 1)s.insert({k,{i,j}});
        }
    }
    while(!s.empty()){
        auto it = s.begin();
        pair<int,pair<int,int>>p = *it;
        s.erase(it);
        sel[p.second.first][p.second.second] = true;
        g[p.second.first][p.second.second] = g[p.second.first][p.second.second] == 1 ? g[p.second.first][p.second.second]:2;
        if (p.first - 1 < 0)continue;
        pair<int,pair<int,int>>del;
        if (p.second.first+1 < r && dis[p.second.first+1][p.second.second] < p.first - 1 && !sel[p.second.first+1][p.second.second]){
            del = {dis[p.second.first+1][p.second.second],{p.second.first+1,p.second.second}};
            if(s.count(del))s.erase(del);
            dis[p.second.first+1][p.second.second] = p.first-1;
            del.first = p.first-1;
            s.insert(del);
        }
        if (p.second.first-1 >= 0 && dis[p.second.first-1][p.second.second] < p.first - 1 && !sel[p.second.first-1][p.second.second]){
            del = {dis[p.second.first-1][p.second.second],{p.second.first-1,p.second.second}};
            if(s.count(del))s.erase(del);
            dis[p.second.first-1][p.second.second] = p.first-1;
            del.first = p.first-1;
            s.insert(del);
        }
        if (p.second.second+1 < c && dis[p.second.first][p.second.second + 1] < p.first - 1 && !sel[p.second.first][p.second.second+1]){
            del = {dis[p.second.first][p.second.second+1],{p.second.first,p.second.second+1}};
            if(s.count(del))s.erase(del);
            dis[p.second.first][p.second.second+1] = p.first-1;
            del.first = p.first-1;
            s.insert(del);
        }
        if (p.second.second-1 >= 0 && dis[p.second.first][p.second.second - 1] < p.first - 1 && !sel[p.second.first][p.second.second-1]){
            del = {dis[p.second.first][p.second.second-1],{p.second.first,p.second.second-1}};
            if(s.count(del))s.erase(del);
            dis[p.second.first][p.second.second-1] = p.first-1;
            del.first = p.first-1;
            s.insert(del);
        }
    }
    for (int i = 0;i<r;i++){
        for (int j = 0;j<c;j++){
            cout << g[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}