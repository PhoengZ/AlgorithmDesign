#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m; 
    vector<int>v(n+1);
    vector<int>tmp(n+1);
    for (int i = 1;i<=n;i++){
        cin >> v[i];
        tmp[i] = v[i];
    }
    map<int,pair<int,int>>me;
    sort(tmp.begin(),tmp.end());
    for (int i = 1;i<=n;i++){
        if (!me.count(tmp[i]))me[tmp[i]] = make_pair(i,0);
        else me[tmp[i]].second = i;
    }
    for (int i  =0;i<m;i++){
        vector<int>x(n+1);
        vector<int>temp(n+1);
        bool c1,c2;
        c1 = c2 = true;
        for (int j = 1;j<=n;j++){
            cin >> x[j];
            temp[j] = v[x[j]];
            if (temp[j] != tmp[j]){
                c1 = false;
                c2 = false;
            }
        }
        for (auto e = me.begin();e!=me.end();e++){
            vector<int>p;
            for (int j =e->second.first;j<=e->second.second;j++){
                p.push_back(x[j]);
            }
            sort(p.begin(),p.end());
            int o = 0;
            for (int j =e->second.first;j<=e->second.second;j++){
                if (p[o] != x[j]){
                    c2 = false;
                    break;
                }
                o++;
            }
        }
        if (c1 && c2)cout << 1 << " " << 1 <<endl;
        else if (c1 && !c2)cout << 1 << " " << 0 << endl;
        else if (!c1 && c2)cout << 0 << " " << 1 << endl;
        else cout << 0 << " " << 0 <<endl;
    }
    return 0;
}