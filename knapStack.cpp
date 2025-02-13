#include <iostream>
#include <vector>
using namespace std;


int main(){
    int n,m;
    cin >> n >> m;
    vector<int>v(n+1);
    vector<int>w(n+1);
    vector<vector<int>>table(n+1);
    vector<int>p(m+1);
    for (int i = 1;i<=n;i++){cin >> v[i];table[i] = p;}
    table[0] = p;
    for (int i =1;i<=n;i++)cin >> w[i];
    for (int i = 0;i<=n;i++){
        for (int j = 0;j<=m;j++)cin >> table[i][j];
    }
    vector<int>sol;
    int row,col;
    row = n;
    col = m;
    while (1){
        if (table[row][col] == 0)break;
        if (col - w[row] < 0)row--;
        else if (table[row][col] == table[row-1][col-w[row]] + v[row]){
            sol.push_back(row);
            col-= w[row];
            row--;
        }else{
            row--;
        }
    }
    cout << sol.size() << endl;
    for (auto &e:sol)cout << e << " ";
    return 0;
}