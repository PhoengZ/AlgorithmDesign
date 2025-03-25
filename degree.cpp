#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(0);
    map<int,int>u;
    int n;
    cin >> n;
    for (int i = 0;i<n;i++){
        int total = 0;
        for (int j = 0;j<n;j++){
            int a;
            cin >> a;
            total+=a;
        }
        u[total]++;
    }
    auto it = --u.end();
    for (int i = 0;i<=it->first;i++){
        cout << u[i] << " ";
    }
    return 0;
}