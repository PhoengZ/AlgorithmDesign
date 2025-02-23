#include <iostream>
#include <vector>
using namespace std;

int s(int left, int right ,vector<int>&v, vector<int>&tmp){
    int r,l;
    int m = left + (right-left)/2;
    l = left;
    r = m + 1;
    int c = 0;;
    int count = 0;
    bool check = false;
    for (int i = left;i<=right;i++){
        if (l > m){
            tmp[i] = v[r++];
            continue;
        }
        if (r > right){
            count+=c;
            tmp[i] = v[l++];
            continue;
        }
        if (v[l] > v[r]){
            c++;
            tmp[i] = v[r++];
        }else{
            count+=c;
            tmp[i] = v[l++];
        }
    }
    // if (check)count+=c;
    for (int i = left;i<=right;i++)v[i] = tmp[i];
    return count;
}

int f(int left, int right ,vector<int>&v, vector<int>&tmp){
    if (left < right){
        int mid = left + (right-left)/2;
        int l = f(left,mid,v,tmp);
        int r = f(mid+1,right,v,tmp);
        int solve = s(left,right,v,tmp);
        return l+r+solve;
    }else return 0;
}

int main(){
    int n;
    cin >> n;
    vector<int>v(n+1);
    vector<int>tmp(n+1);
    for (int i =1;i<=n;i++)cin >> v[i];
    int answer = f(1,n,v,tmp);
    cout << answer;
    return 0;
}