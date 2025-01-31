#include <iostream>
#include <vector>

using namespace std;

void update_height(vector<vector<int>>&edge){

}

int main(){
    int n,k;
    cin  >> n >> k;
    vector<vector<int>> edge(n+1);
    vector<vector<bool>> tmp(n+1);
    vector<int> c(n+1);
    for (int i = 0;i<n-1;i++){
        int a,b;
        cin >> a>>b;
        edge[a].push_back(b);
        vector<bool> v(n+1);
        tmp[i+1] = v;
        c[b] = a;
    }
    int a;
    if (k == 1){
        a = n-1;
    }else{
        for (int i =0;i<edge[1].size();i++){

        } 
    }
    cout << a;
    return 0;
}