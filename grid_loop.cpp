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
    vector<int>from(constant);
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
                if ( j+1 < c && (table[i][j+1] == 1 || table[i][j+1] == 4 || table[i][j+1] == 5))g[node].push_back(node+1);
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
    for (int i =0;i<r*c;i++){
        if (sel[i])continue;
        stack<int>s;
        sel[i] = true;
        s.push(i);
        bool check = false;
        int start,end;
        start = end = -1;
        int old1,old2,old3;
        old1,old2 = -1;
        while(!s.empty() && !check){
            int v = s.top();
            s.pop();
            for(auto&e:g[v]){
                if (sel[e] && from[v] != e){
                    check = true;
                    start = v;
                    end = e;
                    old1 = from[from[end]];
                    old2 = from[end];
                    from[from[end]] = end;
                    from[end] = start;
                    break;
                }
                if (!sel[e]){
                    from[e] = v;
                    sel[e] = true;
                    s.push(e);
                }
            }
        }
        int count = 1;
        while (check && start != end){
            count++;
            start = from[start];
        }
        if (check){
            total++;
            from[old2] = old1;
            from[end] = old2;
        }
        answer=max(answer,count);
    }
    if (total == 0){
        cout << 0 << " " << 0;
    }else{
        cout << total << " " << answer;
    }
    return 0;
}