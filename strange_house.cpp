#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int n;
class graph{
    public:
        vector<int>g;
        vector<int>sol;
        int value;
        int heurtistic;
        int now;
        graph(vector<int>&g,vector<int>&sol,int value,int now){
            this->g = g;
            this->value = value;
            this->now = now;
            this->sol = sol;
        }
        void determine(vector<int>&goal){
            int total = 0;
            for (int i =1;i<=2*n+1;i++){
                if (g[i] != goal[i]){
                    total++;
                }
            }
            this->heurtistic = total;
        }
        bool operator<(const graph& other)const{
            return g < other.g;
        }
};

class compare{
    public:
        bool operator()(const graph &a, const graph &b){
            return a.value + a.heurtistic > b.value + b.heurtistic;
        }
};

int main(){
    int m;
    cin >> n >> m;
    vector<int>goal(2*n + 2,0);
    vector<int>start(2*n + 2,0);
    vector<vector<int>>g(2*n + 2,vector<int>(2*n + 2,0));
    for (int i = 0;i<m;i++){
        int a,b;
        cin >> a >> b;
        g[a][b] = g[b][a] = 1;
    }
    for (int i =1;i<=n;i++)goal[i] = 1;
    for (int i = n+1;i<=2*n;i++)start[i] = 1;
    goal[2*n + 1] = start[2*n+1] = 2;
    set<graph>check;
    priority_queue<graph,vector<graph>,compare>pq;
    vector<int>sol;
    graph s(start,sol,0,2*n+1);
    s.determine(goal);
    pq.push(s);
    while(!pq.empty()){
        graph now = pq.top();
        check.insert(now);
        pq.pop();
        if (goal == now.g){
            cout << now.value << endl;
            for (auto &e:now.sol)cout << e << " ";
            return 0;
        }
        for (int i = 1;i<=2*n+1;i++){
            if (g[now.now][i] == 1){
                vector<int>next = now.g;
                vector<int>sl = now.sol;
                next[now.now] = next[i];
                next[i] = 2;
                sl.push_back(i);
                graph nextg(next,sl,now.value + 1,i);
                nextg.determine(goal);
                if (!check.count(nextg)){
                    pq.push(nextg);
                }
            }
        }
    }
    cout << -1 <<endl;
    return 0;
}