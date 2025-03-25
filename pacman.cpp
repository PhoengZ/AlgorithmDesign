#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    int k;
    cin >>k;
    for (int i =0;i<k;i++){
        int R,N,n,T,r,c;
        cin >> R >> N >> n >> T >> r >>c;
        vector<vector<int>>d = {{1,0},{-1,0},{0,1},{0,-1}};
        vector<vector<int>>tableP(R,vector<int>(N)),tableM(R,vector<int>(N));
        vector<vector<pair<int,int>>>selP(R,vector<pair<int,int>>(N)),selM(R,vector<pair<int,int>>(N));
        queue<pair<int,int>>q;
        vector<vector<int>>spawn(n,vector<int>(3));
        for (int j = 0;j<n;j++){
            cin >> spawn[i][1] >> spawn[i][2] >> spawn[i][0];
        }
        sort(spawn.begin(),spawn.end());
        for (int j = 0;j<R;j++){
            string a;
            cin >> a;
            if (a == "")
        }
    }
    return 0;
}