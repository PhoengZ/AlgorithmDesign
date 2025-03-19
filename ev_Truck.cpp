#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>>g(n),w(n,vector<int>(n,10000000));
    for (int i =0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        g[a].push_back(b);
        g[b].push_back(a);
        w[a][b] = w[b][a] = c;
    }
    vector<vector<int>>sol(n,vector<int>(n));
    for (int i  =0;i<n;i++){
        for (int j = 0;j<n;j++){
            if (i == j)sol[i][j] = 0;
            else sol[i][j] = w[i][j];
        }
    }
    for (int k = 0;k<n;k++){
        for (int i  =0;i<n;i++){
            for (int j = 0;j<n;j++){
                sol[i][j] = min(sol[i][j],sol[i][k] + sol[k][j]);
            }
        }
    }
    int answer = 0;
    for (int i =0;i<n;i++){
        for (int j =0;j<n;j++){
            answer = max(answer,sol[i][j]);
        }
    }
    cout << answer;
    return 0;
}