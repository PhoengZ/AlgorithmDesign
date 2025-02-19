#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int>table(n+1,10000000);
    table[0] = 0;
    for (int i = 1;i<=n;i++){
        int val;
        cin >> val;
        int value = i-k-1 >= 0 ? table[i-k-1]:0;
        table[i] = min(table[i],value + val);
        for (int j = 1;j<=k;j++){
            if (i-j >= 1){
                table[i-j] = min(table[i-j],value + val);
            }
            if (i+j <= n){
                table[i+j] = min(table[i+j],value + val);
            }
        }
    }
    cout << table[n];
    return 0;
}