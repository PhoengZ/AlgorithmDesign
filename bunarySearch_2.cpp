#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i =0;i<n;i++)cin >> v[i];
    for (int i =0;i<m;i++){
        int value;
        cin >> value;
        int left = 0;
        int right = n-1;
        while (left < right){
            int mid = left + (right-left)/2;
            if (v[mid] >= value)right = mid;
            if (v[mid] < value)left = mid+1;
        }
        if (v[left] == value)while (left+1 < n && v[left] == v[left+1])left++;
        if (v[left] > value){
            if (left == 0)cout << -1 << endl;
            else cout << v[left-1] <<endl;
        }else{
            cout << v[left] <<endl;
        }
    }
}