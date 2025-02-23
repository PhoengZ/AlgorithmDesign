#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int>v(n);
    for (int i =0;i<n;i++){
        cin>>v[i];
    }
    for (int i =0;i<m;i++){
        int k;
        cin >> k;
        int count = 0;
        int idx = 0;
        while (v[idx] != k){
            if (v[idx] > k)count++;
            idx++;
        }
        cout << count <<endl;
    }
    

    return 0;
}