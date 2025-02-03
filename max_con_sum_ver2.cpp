#include <iostream>
#include <vector>
using namespace std;

int m_suffix(vector<int>&v, vector<bool>&t, vector<int>&table, int stop){
    if (stop == 1)return v[1];
    if (t[stop])return table[stop];
    int p = m_suffix(v,t,table,stop-1);
    if (p + v[stop] > v[stop]){
        table[stop]= p+v[stop];
    }else{
        table[stop]= v[stop];
    }
    t[stop] = true;
    return table[stop];
}

int recur(vector<int>&v, vector<bool>&t, vector<int>&table, int stop){
    if (stop == 1)return v[1];
    int a = v[stop];
    int b = recur(v,t,table,stop-1);
    int c = m_suffix(v,t,table,stop-1)+v[stop];
    return max(a,max(b,c));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int>v(n+1);
    vector<bool> done_1(n+1);
    vector<int>table_1(n+1);
    int total = 0;
    for (int i = 1;i<=n;i++){
        cin >> v[i];
        total +=v[i];
    }
    int a = recur(v,done_1,table_1,n);
    for (int i = 1;i<=n;i++){v[i] = (-1) * v[i];done_1[i] = false;}
    int b = recur(v,done_1,table_1,n);
    total+=b;
    if (total == 0)cout << a;
    else cout << max(a,total);
    return 0;
}

