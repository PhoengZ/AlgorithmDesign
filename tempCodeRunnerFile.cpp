#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0;i<n;i++)cin >> v[i];
    for (int i = 0;i<m;i++){
        int sol;
        cin >> sol;
        int left = 0;
        int right = v.size()-1;
        bool found = false;
        while (left < right){
            int mid = left + (right - left)/2;
            //if (v[mid] == sol){
            //    left = mid;
            //    right = mid;
            //    while (left + 1 < v.size() && v[left] == v[left+1])left++;
            //    break;
            //}
            if (v[mid] >= sol)right = mid;
            else left = mid+1;
        }
        if (v[left] == sol)while (left+1 < n && v[left] == v[left+1])left++;
        if (v[left] > sol){
            if (left == 0)cout << -1 <<endl;
            else{
                cout << left-1 <<endl;
            }
        }else{
            cout << left <<endl;
        }
        
    }
    return 0;
}