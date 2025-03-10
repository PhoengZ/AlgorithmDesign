#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int>v(n+1),e(n+1);
    for (int i = 1;i<=n;i++)cin >> v[i];
    for (int i = 1;i<=n;i++)cin >> e[i];
    return 0;
}