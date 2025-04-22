#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class item{
    public:
        vector<int>sel;
        int total;
        int now;
        int bound;
        item(vector<int> sel,int total, int now,int bound){
            this->total = total;
            this->now = now;
            this->sel = sel;
            this->bound = bound;
        }
};

class comparable{
    public:
        bool operator()(const item & i,const item &j){
            return i.bound + i.total < j.bound + j.total;
        }
};

bool check(vector<int>&sel, int idx ,vector<vector<int>>&g){
    for (auto & e:sel){
        if (!g[idx][e] || !g[e][idx])return false;
    }
    return true;
}

int c(vector<int>&sel, vector<int>&b, int now, int t){
    int total = 0;
    for (auto &e:sel){
        total+=b[e];
    }
    return t-total;
}

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(0);
    int n;
    cin >>n;
    vector<int>b(n);
    int answer = 0;
    int t= 0;
    vector<vector<int>>g(n,vector<int>(n));
    for (int i = 0;i<n;i++){
        cin >> b[i];
        t+=b[i];
        answer =max(b[i],answer);
    }
    for(int i = 0;i<n;i++){
        for (int j = 0;j<n;j++){
            cin >> g[i][j];
        }
    }
    priority_queue<item,vector<item>,comparable>pq;
    vector<int>sel;
    item i(sel,0,0,t);
    pq.push(i);
    while(!pq.empty()){
        item p = pq.top();
        pq.pop();
        if (p.now == n){
            answer = max(answer,p.total);
            break;
        }
        if (check(p.sel,p.now,g)){
            p.sel.push_back(p.now);
            item i(p.sel,p.total + b[p.now],p.now+1,p.bound-b[p.now]);
            p.sel.pop_back();
            pq.push(i);
        }
        item i(p.sel,p.total,p.now+1,p.bound-b[p.now]);
        pq.push(i);
    }
    cout << answer;
    return 0;
}
