#include<iostream>
#include <vector>

using namespace std;

int mt(vector<vector<int>>&base, long long n, int minus, long long row, long long col){
    if (n == 2){
        return minus == -1 ? base[row-1][col-1] * -1: base[row-1][col-1];
    }
    long long val = n/2;
    if (row <= val && col <= val){
        return mt(base,val,minus,row,col);
    }else if (row <= val && col > val){
        return mt(base,val,minus,col-val,row);
    }else if (row > val && col <= val){
        return mt(base,val,minus*-1,row-val,col);
    }
    return mt(base,val,minus *-1,col-val,row-val);
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> base(2);
    for (int i = 0;i<2;i++){
        for (int j =0;j<2;j++){
            int d;
            cin >> d;
            base[i].push_back(d);
        }
    }
    long long row = 1LL << n;    
    for (int i = 0;i<m;i++){
        long long r,c;
        cin >> r >> c;
        int a = mt(base,row,1,r,c);
        cout << a << endl;
    }
    return 0;
}
