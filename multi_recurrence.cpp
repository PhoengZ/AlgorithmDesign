#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    vector<long long>a(n+1);
    for (int i = 1;i<=k;i++)cin >> a[i];
    for (int i = k+1;i<=n;i++){
        int p;
        cin >> p;
        long long total = 0;
        for (int j = 1;j<=p;j++){
            int idx;
            cin >> idx;
            total += ((i-idx <= 0 ? 0:a[i-idx])%32717);
        }
        total %= 32717;
        a[i] = total;
    }
    for (int i = 1;i<=n;i++)cout << a[i] << " ";
    return 0;
}