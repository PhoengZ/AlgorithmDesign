#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int r,c,k;
    cin >> r >> c >> k;
    vector<vector<int>>N(r+1,vector<int>(c+1));
    vector<vector<int>>S(r+1,vector<int>(c+1));
    int answer = 1;
    queue<vector<int>>q;
    vector<vector<bool>>sel1(r+1,vector<bool>(c+1));
    vector<vector<int>>dir = {{1,0},{-1,0},{0,1},{0,-1}};
    for (int i = 1;i<=r;i++){
        for (int j = 1;j<=c;j++){
            cin >> N[i][j];
        }
    }
    q.push({1,1});
    sel1[1][1] = true;
    while(!q.empty()){
        vector<int>p = q.front();
        q.pop();
        for (int i = 0;i<4;i++){
            int a = p[0]+dir[i][0];
            int b = p[1]+dir[i][1];
            if (a > 0 && a <=r && b > 0 && b <= c && !sel1[a][b] && N[a][b] != 1){
                answer++;
                sel1[a][b] = true;
                q.push({a,b});
            }
        }
    }
    for (int i = 1;i<=r;i++){
        for (int j = 1;j<=c;j++)cin >> S[i][j];
    }
    
    vector<vector<bool>>sel2(r+1,vector<bool>(c+1));
    int total = answer;
    for (int i = 1;i<=k;i++){
        int a,b;
        cin >> a >> b;
        if (!sel1[a][b])continue;
        q.push({a,b});
        sel2[a][b] = true;
        int ans = total+1;
        while (!q.empty()){
            vector<int> p = q.front();
            q.pop();
            for (int i = 0;i<4;i++){
                int a = p[0]+dir[i][0];
                int b = p[1]+dir[i][1];
                if (a > 0 && a <=r && b > 0 && b <= c && !sel2[a][b] && S[a][b] != 1){
                    ans++;
                    sel2[a][b] = true;
                    q.push({a,b});
                }
            }
        }
        answer = max(answer,ans);
    }
    cout << answer;
    return 0;
}