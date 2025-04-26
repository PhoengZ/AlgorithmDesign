#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class item{
    public:
        string sel;
        int total;
        int now;
        int bound;
        item(string sel,int total, int now,int bound){
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

bool check(string &sel, int idx ,vector<vector<int>>&g){
    for (int i = 0;i<sel.length();i++){
        int s = sel[i] - '0'; 
        if (!g[s][idx] || !g[idx][s])return false;
    }
    return true;
}

int c(string&sel, vector<int>&b, int now, int t){
    int total = 0;
    for (int i = 0;i<sel.length();i++){
        int e = sel[i] - '0'; 
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
    string sel = "";
    item i(sel,0,0,t);
    pq.push(i);
    while(!pq.empty()){
        item p = pq.top();
        pq.pop();
        if (p.bound + p.total < answer)continue;
        if (p.now == n){
            answer = max(answer,p.total);
            break;
        }
        if (check(p.sel,p.now,g)){
            char c = p.now + '0';
            string s = p.sel+c;
            item i(s,p.total + b[p.now],p.now+1,p.bound-b[p.now]);
            pq.push(i);
        }
        item i(p.sel,p.total,p.now+1,p.bound-b[p.now]);
        pq.push(i);
    }
    cout << answer;
    return 0;
}
