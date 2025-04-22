#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class item{
    public:
        vector<bool>sel;
        int total;
        int now;
        int bound;
        int node;
        item(vector<bool> sel,int total, int now,int bound,int node){
            this->total = total;
            this->now = now;
            this->sel = sel;
            this->bound = bound;
            this->node = node;
        }
};
class comparable{
    public:
        bool operator()(const item & i,const item &j){
            return i.bound + i.total < j.bound + j.total;
        }
};


int main(){
    int n,m;
    cin >> n >> m;
    vector<int>ki(8);
    vector<vector<int>>g(n);
    vector<vector<int>>value(n,vector<int>(n,-1));
    for (int i = 0;i<8;i++)cin >> ki[i];
    vector<int>branch(n);
    for (int i = 0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        g[a].push_back(b);
        g[b].push_back(a);
        value[a][b] = value[b][a] = c;
        branch[a] = max(branch[a],c);
        branch[b] = max(branch[b],c);
    }
    int upper = 0;
    for (int i =0;i<n;i++){
        upper+=branch[i];
    }
    vector<bool>correct(8);
    for (int i = 0;i<8;i++){
        vector<bool>sel(n);
        priority_queue<item,vector<item>,comparable>pq;
        for (int i = 0;i<n;i++){
            sel[i] = true;
            item it(sel,0,0,upper - branch[i],i);
            pq.push(it);
            sel[i] = false;
        }
        while(!pq.empty()){
            item it = pq.top();
            pq.pop();
            if (it.total == ki[i]){
                correct[i] = true;
                break;
            }
            if (it.now == n)continue;
            if (it.total + it.bound < ki[i])continue;
            if (it.total > ki[i])continue;
            for (auto &e:g[it.node]){
                if (!it.sel[e]){
                    it.sel[e] = true;
                    item it2(it.sel,it.total+value[it.node][e],it.now+1,it.bound - value[it.node][e],e);
                    it.sel[e] = false;
                    pq.push(it2);
                }
            }
        }
    }
    for (int i = 0;i<8;i++){
        if (correct[i])cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}