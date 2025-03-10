#include <iostream>
#include <vector>
using namespace std;



bool check(int target, int now, int t_day, int d,vector<int>&v, int use, int&num){
    if (now == target)return d <= t_day;
    int n_now = now;
    for (int i = now+1;i<=target;i++){
        if (v[now] + use >= v[i])n_now = i;
        else {
            if (n_now == now)return false;
            break;
        }
    }
    return check(target,n_now,t_day,d+1,v,use,++num);
}

int main(){
    int n,d;
    cin >> n >> d;
    vector<int>v(n+1);
    for (int i = 1;i<=n;i++)cin >> v[i];
    int left = 0;
    int right = v[n];
    while (left < right){
        int mid = left + (right-left)/2;
        int num = 0;
        bool c = check(n,0,d,0,v,mid,num);
        if (c){
            right = mid;
        }else{
            left = mid+1;
        }
    }
    int num = 0;
    bool c = check(n,0,d,0,v,left,num);
    cout << left << " " << num;
    return 0;
}