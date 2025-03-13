#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int r,c;
    cin >> r >> c;
    int constant = r*c;
    vector<vector<int>>g(constant);
    vector<vector<int>>table(r,vector<int>(c));
    vector<bool>sel(constant);
    vector<int>dis(constant,-1);
    int node = 0;
    for(int i = 0;i<r;i++){
        int t = i == 0 ? 0:1;
        for (int j = 0;j<c;j++){
            cin >> table[i][j];
        }
    }
    for(int i = 0;i<r;i++){
        for (int j = 0;j<c;j++){
            if (table[i][j] == 1){
                if ( j-1 >= 0 && (table[i][j-1] == 1 || table[i][j-1] == 3 || table[i][j-1] == 4))g[node].push_back(node-1);
                if ( j+1 < c && (table[i][j+1] == 1 || table[i][j+1] == 6 || table[i][j+1] == 5))g[node].push_back(node+1);
            }else if (table[i][j] == 2){
                if ( node - c >= 0 && (table[i-1][j] == 2 || table[i-1][j] == 4 || table[i-1][j] == 5))g[node].push_back(node-c);
                if (node + c < constant && (table[i+1][j] == 2 || table[i+1][j] == 3 || table[i+1][j] == 6))g[node].push_back(node+c);
            }else if (table[i][j] == 3){
                if ( node - c >= 0 && (table[i-1][j] == 2 || table[i-1][j] == 4 || table[i-1][j] == 5))g[node].push_back(node-c);
                if ( j+1 < c && (table[i][j+1] == 1 || table[i][j+1] == 5 || table[i][j+1] == 6))g[node].push_back(node+1);
            }else if (table[i][j] == 4){
                if ( node+c < constant && (table[i+1][j] == 2 || table[i+1][j] == 3 || table[i+1][j] == 6))g[node].push_back(node+c);
                if ( j+1 < c && (table[i][j+1] == 1 || table[i][j+1] == 5 || table[i][j+1] == 6))g[node].push_back(node+1);
            }else if (table[i][j] == 5){
                if ( j-1 >= 0 && (table[i][j-1] == 1 || table[i][j-1] == 3 || table[i][j-1] == 4))g[node].push_back(node-1);
                if ( node+c < constant && (table[i+1][j] == 2 || table[i+1][j] == 3 || table[i+1][j] == 6))g[node].push_back(node+c);
            }else{
                if ( j-1 >= 0 && (table[i][j-1] == 1 || table[i][j-1] == 3 || table[i][j-1] == 4))g[node].push_back(node-1);
                if ( node - c >= 0 && (table[i-1][j] == 2 || table[i-1][j] == 4 || table[i-1][j] == 5))g[node].push_back(node-c);
            }
            node++;
        }
    }
    int total = 0;
    int answer = 1;
    stack<pair<int,int>>s;
    for (int i =0;i<r*c;i++){
        if (sel[i])continue;
        sel[i] = true;
        dis[i] = 1;
        s.push(make_pair(i,-1));
        int count = -1;
        while(!s.empty()){
            pair<int,int> v = s.top();
            s.pop();
            for(auto&e:g[v.first]){
                if (sel[e] && v.second != e){
                    count = max(dis[v.first]+1,count);
                }
                if (!sel[e]){
                    dis[e] = dis[v.first] + 1;
                    sel[e] = true;
                    s.push(make_pair(e,v.first));
                }
            }
        }
        if (count!= -1)total++;
        answer=max(answer,count);
    }
    if (total == 0){
        cout << 0 << " " << 0;
    }else{
        cout << total << " " << answer;
    }
    return 0;
}