#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int>g(n+1),b(n+1);
    vector<bool>sel(n+1);
    for (int i =1;i<=n;i++){
        cin >> g[i];
    }
    set<pair<int,int>,greater<>>s;
    s.insert({0,1});
    sel[1] = true;
    while(!s.empty()){
        auto it = s.begin();
        pair<int,int>p = *it;
        sel[p.second] = true;
        s.erase(it);
        for (int i = 1;i<=n;i++){
            if (i == p.second)continue;
            unsigned long long val = g[p.second] ^ g[i];
            if (!sel[i] && b[i] < val){
                s.erase({b[i],i});
                b[i] = val;
                s.insert({b[i],i});
            }
        }
    }
    unsigned long long answer = 0;
    for (int i =1;i<=n;i++){
        answer+=b[i];
    }
    cout << answer;
    return 0;
}