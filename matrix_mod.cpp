#include <iostream>
#include <vector>
using namespace std;

//int mod(int a, int n,int k){
//    if (n == 1)return a%k;
//    int temp = mod(a,n/2,k);
//    temp = (temp*temp)%k;
//    if (n%2 == 0)return temp;
//    return (temp * a%k)%k;
//}

vector<int> matrix_multiply(const vector<int> &M,const vector<int> &N,int k){
    vector <int> t(4);
    t[0] = (M[0]*N[0] + M[1]*N[2])%k;
    t[1] = (M[0]*N[1] + M[1]*N[3])%k;
    t[2] = (M[2]*N[0] + M[3]*N[2])%k;
    t[3] = (M[2]*N[1] + M[3]*N[3])%k;
    return t;
}

vector<int> mod(vector <int> & vp, int k, int n){
    if (n == 1){
        vector<int>v(4);
        for (int i =0;i<4;i++)v[i] = vp[i]%k;
        return v;
    }
    vector<int> v = mod(vp,k,n/2);
    vector<int> t  = matrix_multiply(v,v,k);
    if (n%2 == 0)return t;
    vector<int> temp(4);
    for (int i = 0;i<4;i++)temp[i] = vp[i]%k;
    vector <int> real = matrix_multiply(t,temp,k);
    return real;
}


int main(){
    long long n;
    int k;
    vector<int> arr(4);
    cin >> n >> k;
    for (int i =0;i<4;i++)cin >> arr[i];
    vector <int> out = mod(arr,k,n);
    for (auto & e:out)cout << e << " ";
    return 0;
}