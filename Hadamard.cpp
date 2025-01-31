#include <iostream>
#include <vector>
using namespace std;

void f(vector<int>&v, int start, int stop, int n, vector<int>&t){
    if (n == 1 && start == stop){
        t.push_back(v[start]);
        return ;
    }
    int mid = start + (stop-start)/2;
    vector<int>left,right;
    f(v,start,mid,n/2,left);
    f(v,mid+1,stop,n/2,right);
    for (int i = 0;i<left.size();i++){
        t.push_back(left[i] + right[i]);
    }
    for (int i = 0;i<left.size();i++){
        t.push_back(left[i] - right[i]);
    }
}

int main(){
    int n; 
    cin >> n;
    vector<int> v(n);
    vector<int> tmp;
    for (int i = 1;i<=n;i++)cin >> v[i];
    f(v,1,n,n,tmp);
    for (auto & e:tmp)cout << e << " ";
    return 0;
}