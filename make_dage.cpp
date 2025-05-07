#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<pair<int,int>>>g(n);
    vector<int>sol(m,-1);
    map<pair<int,int>,int>mp;
    for (int i = 0;i<m;i++){
        int a,b;
        cin >>a >>b;
        a--;b--;
        g[a].push_back({b,i});
        g[b].push_back({a,i});
        mp[{a,i}] = 1;
        mp[{b,i}] = 2;
    }
    stack<int>s;
    vector<bool>sel(n);
    sel[0] = true;
    s.push(0);
    while(!s.empty()){
        int t = s.top();
        s.pop();
        for (auto &e:g[t]){
            if (sol[e.second] != -1)continue;
            if (sel[e.first]){
                if (mp[e] == 1){
                    sol[e.second] = 1;
                }else if (mp[e] == 2){
                    sol[e.second] = 0;
                }
            }else{
                if (mp[e] == 1){
                    sol[e.second] = 1;
                }else if (mp[e] == 2){
                    sol[e.second] = 0;
                }
                sel[e.first] = true;
                s.push(e.first);
            }
        }
    }
    for (auto & e:sol){
        cout << e << " ";
    }
    return 0;
}