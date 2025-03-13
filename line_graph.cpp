#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
    int v,e;
    cin >> v >> e;
    vector<vector<int>>g(v);
    vector<bool>sel(v);
    vector<int>from(v);
    int count = 0;
    for(int i = 0;i<e;i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    stack<int>s;
    for(int i = 0;i<v;i++){
        if(sel[i])continue;
        sel[i] = true;
        bool check = true;
        if (g[i].size() > 2)check = false;
        s.push(i);
        while(!s.empty()){
            int v = s.top();
            s.pop();
            for(auto & e:g[v]){
                if (sel[e] && from[v] != e){
                    check = false;
                }
                if (!sel[e]){
                    sel[e] = true;
                    from[e] = v; 
                    if (g[e].size() > 2)check = false;
                    s.push(e);
                }
            }
        }
        if (check)count++;
    }
    cout << count;
    return 0;
}