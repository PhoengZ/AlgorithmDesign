#include <iostream>
#include <queue>
using namespace std;


int main(){
    int n;
    cin >>n;
    queue<pair<int,int>>q;
    q.push({0,1});
    int ans = 0;
    while(!q.empty()){
        pair<int,int> p = q.front();
        q.pop();
        if (p.first == n){
            ans++;
            continue;
        }
        // cout << "value P.first: " << p.first << " p.second: " << p.second << endl;
        for (int i = p.second;i<=n;i++){
            if (p.first + i > n)break;
            q.push({p.first + i,i});
        }
    }
    cout << ans;
    return 0;
}