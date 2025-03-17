#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>>g(n);
    vector<int>c(n);
    for (int i = 0;i<n;i++){
        int a;
        cin >> a;
        c[i] = a;
        for (int  j = 0;j<a;j++){
            int x;
            cin >> x;
            g[x].push_back(i);
        }
    }
    queue<int>q;
    for (int i = 0;i<n;i++){
        if (c[i] == 0)q.push(i);
    }
    vector<int>ans(n);
    int idx = 0;
    while (!q.empty()){
        int a = q.front();
        q.pop();
        ans[idx++] = a;
        for(auto & e:g[a]){
            c[e]--;
            if (c[e] == 0)q.push(e);
        }
    }
    for (auto & e:ans)cout << e << " ";
    return 0;
}