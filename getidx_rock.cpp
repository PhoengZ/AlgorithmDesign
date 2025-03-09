#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    int l = 1;
    int r = n;
    vector<int>v(n+1);
    for (int i = 1;i<=n;i++){
        int x;
        cin >> x;
        v[i]+=v[i-1]+x;
    }
    while (l < r){
        int mid = (r-l+1)/3;
        double l1 = (v[l+mid-1]-v[l-1])/(double)(mid);
        double r1 = (v[l+2*mid - 1]-v[l+mid-1])/(double)(mid);
        double r2 = (v[r]-v[l+2*mid-1])/(double)(mid);
        if (l1 == r1){
            l = l+(2*mid);
        }else if (l1 == r2){
            l = l+mid;
            r = l+2*mid;
        }else{
            r = l + mid;
        }
    }
    cout << l;
    return 0;
}