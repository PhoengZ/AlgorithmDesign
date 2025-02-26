#include <iostream>
#include <vector>

using namespace std;

int target;

int f(int idx, int k, vector<int>&table, vector<int>&s, vector<int>&v){
    if (idx > target)return -100000;
    if (idx == target)return v[idx];
    if (table[idx] != 0)return table[idx];
    int total = -1000000;
    for (int i = 1;i<=k;i++){
        total = max(total,f(idx + i,k,table,s,v) - s[i] + v[idx]);
    }
    table[idx] = total;
    return total;
}

int main(){
    int n,k;
    cin >> n >> k;
    target = n;
    vector<int>v(n+1);
    vector<int>s(k+1);
    vector<int>table(n+1);
    for (int i = 1;i<=n;i++)cin >> v[i];
    for (int i = 1;i<=k;i++)cin >> s[i];
    int answer = f(1,k,table,s,v);
    cout << answer;
    return 0;
}