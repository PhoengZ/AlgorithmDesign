#include <iostream>
#include <queue>
#include <set>

using namespace std;

vector<vector<int>>goal_pos = {{3,3},{0,0},{0,1},{0,2},{0,3},{1,0},{1,1},{1,2},{1,3},{2,0},{2,1},{2,2},{2,3},{3,0},{3,1}
,{3,2},{3,3}};

vector<int>opp = {1,0,3,2};
vector<vector<int>>goal = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,0}};
class table{
    private:
        vector<vector<int>>b;
        int r,c;
    public:
        int value;
        vector<int>move;
        table(vector<vector<int>>g){
            b = g;
            for (int i = 0;i<4;i++){
                for (int j = 0;j<4;j++){
                    if (g[i][j] == 0){
                        r = i;
                        c = j;
                        break;
                    }
                }
            }
            value = check();
        }
        bool is_goal(){
            return b == goal;
        }
        bool do_move(int dir){
            if (dir == 0){
                if (r == 0)return false;
                b[r][c] = b[r-1][c];
                b[r-1][c] = 0;
                r--;
            }else if (dir == 1){
                if (r == 3)return false;
                b[r][c] = b[r+1][c];
                b[r+1][c] = 0;
                r++;
            }else if (dir == 2){
                if (c == 0)return false;
                b[r][c] = b[r][c-1];
                b[r][c-1] = 0;
                c--;
            }else{
                if (c == 3)return false;
                b[r][c] = b[r][c+1];
                b[r][c+1] = 0;
                c++;
            }
            move.push_back(dir);
            value = check();
            return true;
        }
        int check(){
            int sum = 0;
            for (int i = 0;i<4;i++){
                for (int j = 0;j<4;j++){
                    if (b[i][j] != 0){
                        int r_dif = abs(goal_pos[b[i][j]][0] - i);
                        int c_dif = abs(goal_pos[b[i][j]][1] - j);
                        sum+= (r_dif + c_dif);
                    }
                }
            }
            return move.size() + sum;
        }
        bool operator <(const table&other) const {
            return this->b < other.b;
        }
        void print(){
            for (int i = 0;i<4;i++){
                for (int j =0;j<4;j++){
                    cout << b[i][j] << " ";
                }
                cout << endl;
            }
            return ;
        }
};

class comparetable{
    public:
        bool operator()(const table&t1, const table&t2){
            return t1.value > t2.value;
        }
};

int main(){
    priority_queue<table,vector<table>,comparetable>p;
    set<table>s;
    vector<vector<int>>g(4,vector<int>(4));
    for (int i = 0;i<4;i++){
        for (int j = 0;j<4;j++)cin >> g[i][j];
    }
    table t1(g);
    p.push(t1);
    while(!p.empty()){
        table t = p.top();
        p.pop();
        if (t.is_goal()){
            cout << t.move.size();
            return 0;
        }
        for (int i =0;i<4;i++){
            table t2 = t;
            if (t2.move.size() == 0 || t2.move.back() != opp[i]){
                if (t2.do_move(i)){
                    if (!s.count(t2)){
                        s.insert(t2);
                        p.push(t2);
                    }
                }
            }
        }
    }
    return 0;
}