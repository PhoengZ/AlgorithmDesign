#include <iostream>
#include <vector>
#include <map>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int>v(n+1);
    vector<int>p(n+1);
    map<int,pair<int,int>> m;
    for (int i = 1;i<=n;i++){
        cin >> v[i];
        p[i] += p[i-1] + v[i];
    }
    int now = v[1];
    int ans = v[1];
    m[v[1]] = make_pair(1,v[1]);
    for (int i = 2;i<=n;i++){
        now = max(now+v[i]+v[i],v[i]);
        if (m.count(v[i])){
            ans = max(ans,p[i]- p[m[v[i]].first - 1]);
            if (p[i] - p[m[v[i]].first] < 0){
                m[v[i]].first = i;
                m[v[i]].second = v[i];
            }else{
                m[v[i]].second += (p[i] - p[m[v[i]].first]);
            }
        }else{
            m[v[i]] = make_pair(i,v[i]);
            ans = max(v[i],ans);
        }
    }
    cout << ans;
    return 0;
}