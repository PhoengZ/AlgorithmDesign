#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    int total = 0;
    vector<int>value(n),start(k);
    vector<bool>sel(n,false);
    stack<int>s;
    for (int i =0;i<n;i++){cin >> value[i];total+=value[i];}
    for (int i =0;i<k;i++)cin >> start[i];
    vector<vector<int>>g(n);
    for (int i = 0;i<m;i++){
        int p,q;
        cin >> p >> q;
        g[p].push_back(q);
    }
    for(int i =0;i<k;i++){
        if(sel[start[i]]){
            cout << total << " ";
            continue;
        }
        sel[start[i]] = true;
        total-=value[start[i]];
        s.push(start[i]);
        while(!s.empty()){
            int v = s.top();
            s.pop();
            for (auto & e:g[v]){
                if (!sel[e]){
                    sel[e] = true;
                    total-=value[e];
                    s.push(e);
                }
            }
        }
        cout << total << " ";
    }
    return 0;
}