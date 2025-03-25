#include <iostream>
#include <vector>
#include <set>
#include <climits>
using namespace std;

int main(){
    int R,C,a1,b1,a2,b2;
    cin >> R >> C;
    cin >> a1 >> b1 >> a2 >> b2;
    vector<vector<int>>table(R+1,vector<int>(C+1)),sel(R+1,vector<int>(C+1)),value(R+1,vector<int>(C+1,INT_MAX));
    set<vector<int>>s;
    vector<vector<int>>odd = {{0,-1},{0,1},{-1,0},{-1,1},{1,0},{1,1}};
    vector<vector<int>>even = {{0,-1},{0,1},{-1,0},{-1,-1},{1,0},{1,-1}};
    for (int i  =1 ;i<=R;i++){
        for (int j = 1;j<=C;j++){
            cin >> table[i][j];
        }
    }
    s.insert({table[a1][b1],a1,b1});
    value[a1][b1] = table[a1][b1];
    while(!s.empty()){
        auto it = s.begin();
        vector<int> v = *it;
        s.erase(it);
        sel[v[1]][v[2]] = true;
        for (int i = 0;i<6;i++){
            int row = v[1] + (v[1]%2 == 0 ? even[i][0]:odd[i][0]);
            int col = v[2] + (v[1]%2 == 0 ? even[i][1]:odd[i][1]);
            if (row <= 0 || col <= 0 || row > R || col > C)continue;
            if (!sel[row][col] && value[row][col] > v[0] + table[row][col]){
                s.erase({value[row][col],row,col});
                value[row][col] = v[0] + table[row][col];
                s.insert({value[row][col],row,col});
            }
        }
    }
    cout << value[a2][b2];
    return 0;
}