#include <iostream>
#include <vector>
using namespace std;

bool Scheck(vector<vector<int>>&v, int n,int tc, int tr,int bc,int br){
    if (n == 2){
        if (v[tr][tc] == 0 && v[tr][tc+1] == 0 && v[tr+1][tc] == 0 && v[tr+1][tc+1] == 0)return true;
        return false;
    }
    bool t1 = Scheck(v,n/2,tc,tr,tr + (n/2) -1, tc + (n/2) - 1);
    bool t2 = Scheck(v,n/2,tc, tr + (n/2), tc + (n/2) - 1,br);
    bool t3 = Scheck(v,n/2,tc+(n/2), tr, bc,tr + (n/2)-1);
    bool t4 = Scheck(v,n/2,tc+(n/2), tr + (n/2), bc,br);
    if (t1 && t2 && t3 && t4)return true;
    return false;
}

int check(vector<vector<int>>&v, int n, int tc, int tr, int bc, int br){
    if (n == 2){
        if (v[br][bc] != 0 )return 0;
        if (v[tr][tc] == 0 || v[tr][tc+1] == 0 || v[tr+1][tc] == 0)return 0;
        if (v[tr][tc] == v[tr][tc+1] || v[tr][tc] == v[tr+1][tc])return v[tr][tc];
        if (v[tr][tc+1] == v[tr+1][tc])return v[tr][tc+1];
        return 0;
    }else{
        int t1 = check(v,n/2,tc,tr,tc+(n/2) - 1, tr + (n/2) - 1);
        int t2 = check(v,n/2,tc, tr + (n/2), tc + (n/2) - 1,br);
        int t3 = check(v,n/2,tc+(n/2), tr, bc,tr + (n/2)-1);
        bool t4 = Scheck(v,n/2,tc+(n/2), tr + (n/2), bc,br);
        if (t1 == 0 || t2 == 0 || t3 == 0)return 0;
        if (!t4)return 0;
        if (t1 == t2 || t1 == t3)return t1;
        if (t2 == t3)return t2;
        return 0;
    }
}

int main(){
    for (int i = 0;i<3;i++){
        int n;
        cin >> n;
        vector<vector<int>> v(n);
        for (int j = 0;j<n;j++){
            for (int k = 0;k<n;k++){
                int idx;
                cin >> idx;
                v[j].push_back(idx);
            }
        }
        int type = check(v,n,0,0,n-1,n-1);
        cout << type <<endl;
    }
    return 0;
}