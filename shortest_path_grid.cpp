#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int r,c;
    cin >> r >> c;
    vector<string>v(r);
    vector<vector<bool>>sel(r,vector<bool>(c));
    for (int i = 0;i<r;i++){
        cin >> v[i];
    }
    queue<pair<pair<int,int>,int>>q;
    q.push(make_pair(make_pair(0,0),0));
    sel[0][0] = true;
    int ans = - 1;
    while(!q.empty()){
        pair<pair<int,int>,int> p = q.front();
        // cout << "Now: " << p.first.first << " " << p.first.second <<endl;
        q.pop();
        if (p.first.first == r-1 && p.first.second == c-1){
            ans = p.second;
            break;
        }
        if (p.first.first-1 >=0 && v[p.first.first-1][p.first.second] == '.' && !sel[p.first.first-1][p.first.second]){
            sel[p.first.first-1][p.first.second] = true;
            q.push(make_pair(make_pair(p.first.first-1,p.first.second),p.second+1));
        }
        if (p.first.second + 1 < c && v[p.first.first][p.first.second+1] == '.' && !sel[p.first.first][p.first.second+1]){
            sel[p.first.first][p.first.second+1] = true;
            q.push(make_pair(make_pair(p.first.first,p.first.second+1),p.second+1));
        }
        if (p.first.first+1 < r && v[p.first.first+1][p.first.second] == '.' && !sel[p.first.first+1][p.first.second]){
            sel[p.first.first+1][p.first.second] = true;
            q.push(make_pair(make_pair(p.first.first+1,p.first.second),p.second+1));
        }
        if (p.first.second-1 >= 0 && v[p.first.first][p.first.second-1] == '.' && !sel[p.first.first][p.first.second-1]){
            sel[p.first.first][p.first.second-1] = true;
            q.push(make_pair(make_pair(p.first.first,p.first.second-1),p.second+1));
        }
    }
    cout << ans;
    return 0;
}