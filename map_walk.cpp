#include <iostream>
#include <vector>
using namespace std;

void walk(vector <pair<string,pair<int,int>>>&contain, vector<vector<int>> & matrix, vector<vector<bool>>&check, string & sol,pair<int,int> & target, pair<int,int> & now){
    if (now.first+1 == target.first && now.second+1 == target.second){
        cout << sol <<endl;
        
    }
    else{
        for (int i = 0;i<3;i++){
            int row = now.first + contain[i].second.first;
            int col = now.second + contain[i].second.second;
            if (row < 0 || col < 0)continue;
            if (row < target.first && col < target.second && matrix[row][col] != 1 && !check[row][col]){
                int o_r = now.first;
                int oc = now.second;
                now.first = row;
                now.second = col;
                check[row][col] = true;
                sol += contain[i].first;
                walk(contain,matrix,check,sol,target,now);
                check[now.first][now.second] = false;
                sol.pop_back();
                now.first = o_r;
                now.second = oc;
            }
        }
    }
}


int main(){
    string sol = "";
    int n,m;
    cin >> n >> m;
    pair<int,int> p = {n,m};
    pair<int,int> now = {0,0};
    vector <pair<string,pair<int,int>>> contain(3);
    contain[0] = {"A",{0,1}};
    contain[1] = {"B",{1,0}};
    contain[2] = {"C",{-1,0}};
    vector<vector<bool>> check(n);
    vector <vector<int>> matrix(n);
    for (int i=0;i<n;i++){
        for (int j = 0;j<m;j++){
            int k ;
            cin>>k;
            matrix[i].push_back(k);
            check[i].push_back(false);
        }
    }
    check[0][0] = true;
    walk(contain,matrix,check,sol,p,now);
    cout << "DONE";
    return 0;
}