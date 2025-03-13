#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int v,e;
    cin >> v >>e;
    vector<vector<int>>g(v+1);
    vector<bool>sel(v+1);
    stack<int>s;
    for (int i = 0;i<e;i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }    
    int count = 0;    
    for (int i = 1;i<=v;i++){
        if (sel[i])continue;
        count++;
        sel[i] = true;
        s.push(i);
        while(!s.empty()){
            int vertex = s.top();
            s.pop();
            for(auto &e:g[vertex]){
                if (!sel[e]){
                    sel[e] = true;
                    s.push(e);
                }
            }
        }
    }
    cout << count;
    return 0;
}