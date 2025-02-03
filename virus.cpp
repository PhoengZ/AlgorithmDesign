#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

map<string,bool>u;

bool f(string now){
    if (now.length() == 2){
        return now[0] == '0' && now[1] == '1';
    }
    if (u.count(now))return u[now];
    int mid = now.length()/2;
    string left,right,r_left;
    for (int i = 0;i<now.length();i++){
        if (i < mid){
            left+=now[i];
            r_left += now[mid-1-i];
        }else right += now[i];
    }
    bool a = f(left);
    bool b = f(right);
    bool c = f(r_left);
    if (a&&b || c&&b){
        u[now] = true;
        return true;
    }
    u[now] = false;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,k;
    cin >> n >> k;
    int size = 1 << k;
    for (int i = 0;i<n;i++){
        string v;
        for (int i =0;i<size;i++){
            char a;
            cin >> a;
            v+=a;
        }
        bool check = f(v);
        if (check)cout << "yes" <<endl;
        else cout << "no" <<endl;
    }
}