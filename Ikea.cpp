#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,e;
    cin >> n >> e;
    vector<vector<int>>g(n+1);
    vector<int>s(n+1);
    for (int i = 0;i<e;i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        s[b]++;
    }
    for (int i = 1;i<=5;i++){
        bool check = true;
        vector<int>t = s;
        for (int j = 1;j<=n;j++){
            int x;
            cin >> x;
            if (t[x] != 0)check = false;
            for (int k = 0;k<g[x].size();k++){
                t[g[x][k]]--;
            }
        }
        if (check)cout << "SUCCESS" << endl;
        else cout << "FAIL" << endl;
    }
    return 0;
}