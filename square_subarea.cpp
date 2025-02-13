#include <iostream>
#include <vector>
using namespace std;

int main(){
    return 0;
    int n,m;
    cin >> n >> m;
    vector<vector<int>>matrix(n+1);
    vector<int>row(m+1);
    for(int i = 0;i<=n;i++)matrix[i] = row;
    for (int i = 1;i<=n;i++){
        for (int j = 1;j<=m;j++)cin >> matrix[i][j];
    }
    for (int i = 1;i<=n;i++){
    }
}
    
