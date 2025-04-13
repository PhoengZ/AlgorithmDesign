#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int r,c;


class item{
    public:
        int r;
        int c;
        int total;
        int q;
        item(int r, int c, int total, int q){
            this->r = r;
            this->c = c;
            this->total = total;
            this->q = q;
        }
};
class comparable{
    public:
        bool operator()(const item &i1, const item &i2){
            return i1.total > i2.total;
        }
};



int main(){
    cin >> r >> c;
    vector<vector<int>>g(r,vector<int>(c));
    vector<vector<vector<bool>>>sel(r,vector<vector<bool>>(c,vector<bool>(3)));
    vector<vector<vector<int>>>sol(r,vector<vector<int>>(c,vector<int>(3,10000000)));
    for (int i = 0;i<r;i++){
        for (int j = 0;j<c;j++){
            cin >> g[i][j];
        }
    }
    vector<vector<int>>d1 = {{1,0},{-1,0},{0,1},{0,-1}};
    vector<vector<int>>d2 = {{2,0},{1,0},{1,-1},{1,1},{-2,0},{-1,0},{-1,-1},{-1,1},{0,1},{0,2},{0,-1},{0,-2}};
    priority_queue<item,vector<item>,comparable>q;
    item t(0,0,0,0);
    sol[0][0][0] = 0;
    q.push(t);
    while(!q.empty()){
        item i = q.top();
        q.pop();
        if (sel[i.r][i.c][i.q])continue;
        sel[i.r][i.c][i.q] = true;
        if (i.q < 2){
            for (auto &e:d2){
                int r1 = i.r + e[1];
                int c1 = i.c + e[0];
                if (r1 < 0 || r1 >= r || c1 < 0 || c1 >= c)continue;
                if (i.total < sol[r1][c1][i.q+1]){
                    sol[r1][c1][i.q+1] = min(i.total,sol[r1][c1][i.q+1]);
                    item d(r1,c1,i.total,i.q+1);
                    q.push(d);
                }
            }
        }
        for (auto &e :d1){
            int r1 = i.r + e[1];
            int c1 = i.c + e[0];
            if (r1 < 0 || r1 >= r || c1 < 0 || c1 >= c)continue;
            if (i.total+g[r1][c1] < sol[r1][c1][i.q]){
                sol[r1][c1][i.q] = min(i.total+g[r1][c1],sol[r1][c1][i.q]);
                item d(r1,c1,i.total+g[r1][c1],i.q);
                q.push(d);
            }
        }
    }
    for (int i = 0;i<r;i++){
        for (int j = 0;j<c;j++){
            int value = min(sol[i][j][0],min(sol[i][j][1],sol[i][j][2]));
            cout << value<< " ";
        }
        cout << endl;
    }
    return 0;
}