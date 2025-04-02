#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,e;
    cin >> n >> e;
    vector<vector<int>>g(n+1);
    vector<int>c(n+1);
    for (int i = 0;i<e;i++){
        int a,b;
        cin >> a >> b;
        c[b]++;
        g[a].push_back(b);
    }
    for (int i = 0;i<5;i++){
        vector<int>c1 = c;
        bool check = true;
        for (int j=0;j<n;j++){
            int a;
            cin >> a;
            if (c1[a] != 0)check = false;                
            for (auto &e:g[a])c1[e]--;
        }
        if (check)cout << "SUCCESS" << endl;
        else cout << "FAIL" << endl;
    }
    return 0;
}