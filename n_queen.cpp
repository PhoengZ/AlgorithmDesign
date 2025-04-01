#include <iostream>
#include <vector>
using namespace std;

bool c(vector<int>&sol, int t){
    for (int i = 0; i < t; i++) {
        for (int j = i + 1; j < t; j++) {
            if (sol[i] == sol[j] || abs(sol[i] - sol[j]) == abs(i - j)) {
                return false;
            }
        }
    }
    return true;
}

int f(vector<int>&sol, vector<bool>&sel, int target, int now ){
    if (now == target){
        if (c(sol,target))return 1;
        return 0;
    }
    int ans = 0;
    for (int i = 0;i<target;i++){
        if (!sel[i]){
            sel[i] = true;
            sol[now] = i;
            ans+= f(sol,sel,target,now+1);
            sel[i] = false;
            sol[now] = -1;
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int>g(n,-1);
    vector<bool>sel(n);
    int ans = f(g,sel,n,0);
    cout << ans;
    return 0;
}