#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;    
    vector<vector<int>>g(n,vector<int>(n,1000000000));
    for (int i = 0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = c;
    }
    for (int i = 0;i<n;i++){
        g[i][i] = 0;
    }
    for (int k = 0;k<n;k++){
        for (int i = 0;i<n;i++){
            for (int  j = 0;j<n;j++){
                g[i][j] = min(g[i][j],g[i][k] + g[k][j]);
            }
        }
    }
    int sol = 0;
    for (int i = 0;i<n;i++){
        for (int j =0;j<n;j++){
            if (g[i][j] != 1000000000){
                sol = max(sol,g[i][j]);
            }
        }
    }
    cout << sol;
    return 0;
}