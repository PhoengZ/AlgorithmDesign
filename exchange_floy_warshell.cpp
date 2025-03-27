#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin >> n;
    for (int i =0;i<n;i++){
        int v;
        cin >> v;
        vector<vector<double>>w(v,vector<double>(v));
        for (int j = 0;j<v;j++){
            for (int k = 0;k<v;k++){
                cin >> w[j][k];
                w[j][k] = -log(w[j][k]);
            }
        }
        for (int k = 0;k<v;k++){
            for (int p =0;p<v;p++){
                for (int e = 0;e<v;e++){
                    w[p][e] = min(w[p][e],w[p][k]+w[k][e]);
                }
            }
        }
        bool c = false;
        for (int p =0;p<v;p++){
            if (w[p][p] < 0){
                c = true;
                break;
            }
        }
        if (c)cout << "YES" <<endl;
        else cout << "NO" << endl;
    }
    return 0;
}
