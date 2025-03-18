#include <iostream>
#include <vector>
using namespace std;

int main(){
    int k;
    cin >> k;
    for (int i =0;i<k;i++){
        int n;
        cin >> n;
        vector<vector<float>>g(n,vector<float>(n));
        for (int j = 0;j<n;j++){
            for (int k = 0;k<n;k++){
                cin >> g[j][k];
            }
        }
        vector<float>sol(n,-10000000);
    }
    return 0;
}