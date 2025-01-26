#include <iostream>
#include <vector>

using namespace std;

bool c(vector<int>&v, long long len, int left, int right){
    if (len == 2)return v[left] == 0 && v[right] == 1 ? true:false;
    int mid = left + (right-left)/2;
    bool normal_l = c(v,len/2,left,mid);
    bool r = c(v,len/2,mid+1,right);
    int idx = left;
    vector<int>vp(right);
    for (int i = mid;i>=left;i--)vp[idx++] = v[i];
    bool up_l = c(vp,len/2,left,mid);
    return (normal_l && r) || (up_l && r);
} 

int main(){
    int n,m;
    cin >> n >> m;
    long long length = 1LL << m;
    for (int i =0;i<n;i++){
        vector<int> v(length);
        for (long long j = 0;j<length;j++){
            cin >>v[j];
        }

        bool check = c(v,length,0,length-1);
        if (check)cout << "yes"<<endl;
        else cout << "no" <<endl;
    }
    return 0;
}