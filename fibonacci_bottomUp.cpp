#include <iostream>

using namespace std;

int main(){
    int n;
    int a1,a2;
    a1 = a2 = 1;
    int ans = 0;
    for (int i = 2;i<=n;i++){
        ans = a1+a2;
        a2 = a1;
        a1 = ans;
    }
    cout << ans;
    return 0;
}