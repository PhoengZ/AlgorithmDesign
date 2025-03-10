#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<pair<int,pair<int,int>>>v(k+1);
    for (int i = 1;i<=k;i++){
        cin >> v[i].first >> v[i].second.first >> v[i].second.second;
    }
    sort(v.begin(),v.end());
    queue<pair<int,pair<int,int>>>qp;
    queue<pair<int,pair<int,int>>>qs;
    int stock = 0;
    for (int i = 1;i<=k;i++){
        if (v[i].second.first == 0){
            qp.push(v[i]);
            if (!qs.empty()){
                int t = qs.front().second.second;
                cout << t << endl;
                qs.pop();
                qp.pop();
            }else cout << 0 << endl;
        }else{
            qs.push(v[i]);
            if (!qp.empty()){
                int t = qp.front().second.second;
                cout << t << endl;
                qp.pop();
                qs.pop();
            }else cout << 0 << endl;
        }
    }
    return 0;
}