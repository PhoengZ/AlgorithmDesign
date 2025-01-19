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
        int f;
        cin >> f;
        int count = 0,index = 0;
        while (v[index] != f){
            if (f < v[index])count++;
            index++;
        }
        cout << count <<endl;
    }
    

    return 0;
}