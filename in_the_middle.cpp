#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int>t(3);
    vector<vector<int>>g(n+1),dis(3,vector<int>(n+1));
    vector<vector<bool>>sel(3,vector<bool>(n+1));
    for(int i = 0;i<3;i++){
        cin >> t[i];
    }
    for (int i = 1;i<=n;i++){
        int a;
        cin >> a;
        for (int j = 0;j<a;j++){
            int x;
            cin >> x;
            g[i].push_back(x);
        }
    }
    queue<int>q;
    for (int i = 0;i<3;i++){
        q.push(t[i]);
        sel[i][t[i]] = true;
        while (!q.empty()){
            int c = q.front();
            q.pop();
            for (auto & e:g[c]){
                if(!sel[i][e]){
                    sel[i][e] = true;
                    dis[i][e] = dis[i][c]+1;
                    q.push(e);
                }
            }
        }
    }
    int answer = 10000000;
    for (int i = 1;i<=n;i++){
        if (sel[0][i] && sel[1][i] && sel[2][i]){
            int total = max(dis[0][i],max(dis[1][i],dis[2][i]));
            answer = min(answer,total);
        }
    }
    cout << answer;
    
    return 0;
}