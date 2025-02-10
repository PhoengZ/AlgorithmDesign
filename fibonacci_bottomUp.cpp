#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    if (n == 0){cout << 0;return 0;}
    if (n == 1 || n == 2){cout << 1;return 0;}
    int a1,a2;
    a1 = a2 = 1;
    int ans = 0;
    for (int i = 2;i<n;i++){
        ans = a1+a2;
        a2 = a1;
        a1 = ans;
    }
    cout << ans;
    return 0;
}