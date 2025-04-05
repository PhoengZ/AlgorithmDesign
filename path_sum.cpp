#include <iostream>
#include <vector>


using namespace std;

int n;



bool f(int node, int total , int check, vector<vector<int>>&g, vector<vector<int>>&w,vector<bool>&sel, int count,int u,vector<int>&t){
    if (count == 0)return false;
    if (total == check)return true;
    if (total > check)return false;
    if (u+total < check)return false;
    for (int i = 0;i<n;i++){
        if (!sel[i] && w[node][i] != 0){
            sel[i] = true;
            bool c = f(i,total + w[node][i],check,g,w,sel,count-1,u-t[i],t);
            sel[i] = false;
            if (c)return true;
        }
    }
    return false;
}


int main(){
    int m;
    cin >> n >> m;
    vector<int>k(8),t(n);
    vector<vector<int>>g(n);
    vector<bool>sel(n);
    vector<vector<int>>w(n,vector<int>(n));
    for (int i = 0;i<8;i++)cin >> k[i];
    for (int i = 0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        g[a].push_back(b);
        g[b].push_back(a);
        w[b][a] = w[a][b] = c;
        t[a] = max(t[a],c);
        t[b] = max(t[b],c);
    }
    int e = 0;
    for (int i = 0;i<n;i++){
        e+=t[i];
    }
    for (int i = 0;i<8;i++){
        bool check =false;
        for (int j = 0;j<n;j++){
            sel[j] = true;
            bool c = f(j,0,k[i],g,w,sel,n,e-t[j],t);
            if (c){
                check = true;
                break;
            }
            sel[j] = false;
        }
        if (check)cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}