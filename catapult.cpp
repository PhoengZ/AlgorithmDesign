#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>>g(n),rev(n);
    vector<int>count(n);
    queue<int>q;
    for (int i = 0;i<n;i++){
        int a;
        cin >> a;
        for (int j = 0;j<a;j++){
            int x;
            cin >> x;
            g[i].push_back(x);
            rev[x].push_back(i);
            count[x]++;
        }
    }
    vector<int>ans,sel(n),group(n);
    for (int i = 0;i<n;i++){
        if (count[i] == 0){
            ans.push_back(1);
            sel[i] = true;
            q.push(i);
        }
    }
    while(!q.empty()){
        int t = q.front();
        q.pop();
        for (auto & e:g[t]){
            if (!sel[e]){
                count[e]--;
                if (count[e] == 0){
                    sel[e] = true;
                    q.push(e);
                    ans.push_back(1);
                }
            }
        }
    }
    stack<int> finish_order;
    vector<bool> dfs_visited(n, false);
    
    for (int i = 0; i < n; i++) {
        if (!sel[i] && !dfs_visited[i]) {
            stack<int> s;
            s.push(i);
            dfs_visited[i] = true;
            
            while (!s.empty()) {
                int node = s.top();
                bool finished = true;

                for (int neighbor : g[node]) {
                    if (!dfs_visited[neighbor]) {
                        dfs_visited[neighbor] = true;
                        s.push(neighbor);
                        finished = false;
                    }
                }

                if (finished) {
                    finish_order.push(node);
                    s.pop();
                }
            }
        }
    }

    while (!finish_order.empty()) {
        int node = finish_order.top();
        finish_order.pop();
        
        if (!sel[node]) {
            stack<int> s;
            s.push(node);
            sel[node] = true;
            int size = 0;

            while (!s.empty()) {
                int curr = s.top();
                s.pop();
                size++;

                for (int neighbor : rev[curr]) {
                    if (!sel[neighbor]) {
                        sel[neighbor] = true;
                        s.push(neighbor);
                    }
                }
            }

            ans.push_back(size);
        }
    }
    sort(ans.begin(),ans.end());
    for(auto &e:ans)cout << e << " ";
    return 0;
}