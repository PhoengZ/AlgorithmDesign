#include <iostream>
#include <vector>
using namespace std;

int main(){
    int k,n;
    cin >> k >> n;
    vector<int>c(k);
    vector<int>a(n+1);
    for (int i =0;i<k;i++)cin >> c[i];
    for (int i = 0;i<k;i++)cin >> a[i];
    for (int i = k;i<=n;i++){
        int total = 0;
        for (int j = 1;j<=k;j++){
            total+= ((c[j-1]%32717)*(a[i-j]%32717))%32717;
        }
        a[i] = total%32717;
    }
    cout <<a[n];
    return 0;
}