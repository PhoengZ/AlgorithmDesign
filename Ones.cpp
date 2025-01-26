#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> v(10);
    v[0] = 1;
    for (int i =1;i<10;i++){
        v[i] = (v[i-1]*10) + 1;
    }
    int step = 0;
    while (n > 11){
        int idx = -1;
        for (int i = 9; i >= 0; i--) {
            if (v[i] <= n) {
                idx = i;
                break;
            }
        }
        if (idx < 9 && n > (v[idx] + v[idx + 1]) / 2) {
            step += idx + 2;
            n = v[idx + 1] - n; 
        } else {
            step += idx + 1;
            n -= v[idx];
        }

    }
    if (n >= 7){
        int real = step + 6 - (n-7);
        cout << real;
    }else{
        cout << step + n;
    }
    return 0;
}