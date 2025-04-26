#include <iostream>
#include <vector>
using namespace std;

#define INF 1000000000

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>>sol(n,vector<int>(n,INF));
    for (int i = 0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        a--;
        b--;
        sol[a][b] = c;
    }
    for (int i = 0;i<n;i++){
        sol[i][i] = 0;
    }
    for (int k = 0;k<n;k++){
        for (int i = 0;i<n;i++){
            for (int j = 0;j<n;j++){
                if (sol[i][k] == -1 || sol[k][j] == -1)continue;
                sol[i][j] = min(sol[i][j],sol[i][k] + sol[k][j]);
            }
        }
    }
    int answer = 0;
    for (int i = 0;i<n;i++){
        for (int j = 0;j<n;j++){
            if (sol[i][j] == INF)continue;
            answer = max(answer,sol[i][j]);
        }
    }
    cout << answer;
    return 0;
}