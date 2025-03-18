#include <iostream>
#include <vector>
using namespace std;

int main(){
    int k;
    cin >> k;
    for (int i =0;i<k;i++){
        int n;
        cin >> n;
        vector<vector<float>>g(n,vector<float>(n));
        vector<pair<int,int>>e;
        for (int j = 0;j<n;j++){
            for (int k = 0;k<n;k++){
                cin >> g[j][k];
                e.push_back({j,k});
            }
        }
        vector<float>sol(n,-1000000);
        sol[0] = 1;
        for (int t = 1;t<n;t++){
            for (auto & j:e){
                sol[j.second] = max(sol[j.second],sol[j.first]*g[j.first][j.second]);
            }
        }
        bool check = false;
        for (auto & t:e){
            if (sol[t.second] < sol[t.first]*g[t.first][t.second]){
                check = true;
                break;
            }
        }
        if (!check)cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}