#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int>table(n+1,10000000);
    table[0] = 0;
    vector<int>v(n+1);
    for (int i = 1;i<=n;i++)cin >> v[i];
    for (int i = 1;i<=n;i++){
        int value = i-k-1 >= 0 ? table[i-k-1]:0;
        table[i] = min(table[i],value + v[i]);
        for (int j = 1;j<=k;j++){
            if (i-j >= 1){
                table[i-j] = min(table[i-j],value + v[i]);
            }
            if (i+j <= n){
                table[i+j] = min(table[i+j],value + v[i]);
            }
        }
    }
    cout << table[n];
    return 0;
}