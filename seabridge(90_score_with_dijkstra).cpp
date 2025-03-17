#include<iostream>
#include <set>
#include <vector>

using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int r,c;
    cin >> r >> c;
    vector<vector<int>>g(r,vector<int>(c));
    vector<vector<bool>>sel(r,vector<bool>(c));
    vector<vector<int>>dis(r,vector<int>(c,10000000));
    set<pair<int,pair<int,int>>>s;
    for (int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            cin >> g[i][j];
            if (g[i][j] == 1){
                s.insert({1,{i,j}});
            }
        }
    }
    int ans = 10000000;
    while(!s.empty()){
        if (ans == 1)break;
        auto it = s.begin();
        pair<int,pair<int,int>>p = *it;
        sel[p.second.first][p.second.second] = true;
        s.erase(it);
        if (p.first > ans)continue;
        if (g[p.second.first][p.second.second] == 2){
            // cout << "Now node at: " << p.second.first << " " << p.second.second << endl;
            // cout << "Now distance: " << p.first << endl;
            ans = min(ans,p.first);
            continue;
        }
        int a = p.second.first;
        int b = p.second.second;
        pair<int,pair<int,int>> del;
        if (a+1 < r && g[a+1][b] != 3 && !sel[a+1][b] && dis[a+1][b] > p.first+1){
            del = {dis[a+1][b],{a+1,b}};
            s.erase(del);
            del.first = p.first+1;
            s.insert(del);
        }
        if (a-1 >= 0 && g[a-1][b] != 3 && !sel[a-1][b] && dis[a-1][b] > p.first+1){
            del = {dis[a-1][b],{a-1,b}};
            s.erase(del);
            del.first = p.first+1;
            s.insert(del);
        }
        if (b+1 < c && g[a][b+1] != 3 && !sel[a][b+1] && dis[a][b+1] > p.first+1){
            del = {dis[a][b+1],{a,b+1}};
            s.erase(del);
            del.first = p.first+1;
            s.insert(del);
        }
        if (b-1 >= 0 && g[a][b-1] != 3 && !sel[a][b-1] && dis[a][b-1] > p.first+1){
            del = {dis[a][b-1],{a,b-1}};
            s.erase(del);
            del.first = p.first+1;
            s.insert(del);
        }
    }
    cout << ans;
    return 0;
}