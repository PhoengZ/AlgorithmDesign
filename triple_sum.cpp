#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector <int> v(n);
    for (int i = 0;i<n;i++)cin >> v[i];
    for (int i = 0;i<m;i++){
        int a;
        cin>> a;
        bool check = false;
        for (int j = 0;j<n;j++){
            int left = j+1;
            int right = v.size()-1;
            while (left < right){
                if (v[left] + v[right] + v[j] == a){
                    check = true;
                    break;
                }
                if (v[left] + v[right] + v[j] < a){
                    left++;
                }else{
                    right--;
                }
            }
            if (check)break;    
        }
        if (!check)cout << "NO"<<endl;
        else cout << "YES" <<endl;
    }
    return 0;
}