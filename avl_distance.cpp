#include <iostream>
#include <vector>

using namespace std;




int d(vector<vector<int>>&e, vector<vector<bool>>&tmp, int target, int len, pair<int,int> p)  {
    
    return ;
}

int main(){
    int n,k;
    cin  >> n >> k;
    vector<vector<int>> edge(n+1);
    vector<vector<bool>> tmp(n+1);
    for (int i = 0;i<n-1;i++){
        int a,b;
        cin >> a>>b;
        edge[a].push_back(b);
        vector<bool> v(n+1);
        tmp[i+1] = v;
    }
    int a;
    if (k == 1){
        a = n-1;
    }else{
        a = d(edge,cp,k,0,{1,0},false);
    }
    cout << a;
    return 0;
}