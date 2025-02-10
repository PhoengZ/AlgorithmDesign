#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    vector <vector<int>>v(n);
    vector <vector<int>>p(n);
    for (int i = 0;i<n;i++){
        vector<int>b(m);
        v[i] = b;
        p[i] = b;
    }
    for (int i = 0;i<n;i++){
        for (int j = 0;j<m;j++){
            cin >> v[i][j];
        }
    }
    p[0][0] = v[0][0];
    for (int i = 1;i<m;i++){
        p[0][i] += p[0][i-1] + v[0][i];
    }
    for (int i = 1;i<n;i++){
        p[i][0]+=p[i-1][0] + v[i][0];
        for (int j = 1;j<m;j++){
            p[i][j] = v[i][j] + p[i-1][j] + p[i][j-1] - p[i-1][j-1];
        }
    }
    for (int i = 0;i<k;i++){
        int r1,c1,r2,c2;
        cin >> r1 >> c1 >>r2 >> c2;
        if (r1 == r2 && c1 == c2){
            cout << v[r1][c1] << endl;
        }else{
            int a1 = r2 >= 0 && c2 >= 0 ? p[r2][c2]:0;
            int a2 = r1-1 >= 0 && c2 >= 0 ?  p[r1-1][c2]:0; 
            int a3 = r2 >= 0 && c1-1 >=0 ? p[r2][c1-1]:0;
            int a4 = r1-1 >= 0 && c1-1 >= 0 ? p[r1-1][c1-1]:0;
            int total = a1 - a2 - a3 + a4;
            cout << total << endl;
        }
    }
    return 0;
}