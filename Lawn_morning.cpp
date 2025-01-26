#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> v(n+1);
    vector<int>sum(n+1);
    for (int i = 1;i<=n;i++){
        cin >> v[i];
        sum[i]+=sum[i-1]+v[i];
    }
    for (int i =0;i<m;i++){
        long long start,target;
        cin >> start >> target;
        start++;
        
    }
    return 0;
}