#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int f(int idx, int helth,int range, vector<pair<int,int>>&monster, vector<int>&tower){
    if (idx == tower.size()){
        return helth;
    }
    auto low = lower_bound(monster.begin(),monster.end(),make_pair(tower[idx] - range,0));
    int a = helth;
    for (auto i = low;i != monster.end();i++){
        if (i->first > tower[idx] + range){
            a = max(f(idx+1,helth,range,monster,tower),a);
            break;
        }else{
            int index= i-monster.begin();
            if (i->second <= 0)continue;
            monster[index].second--;
            a = max(f(idx+1,helth+1,range,monster,tower),helth+1);
            monster[index].second++;
        }
        
    }
    return a;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m,k,w;
    cin >> n >> m >> k  >> w;
    vector<int> tower(k);
    vector<pair<int,int>> monster(m);
    int total = 0;
    for (int i =0;i<m;i++){
        int a;
        cin >> a;
        monster[i].first = a;
    }
    for (int i =0;i<m;i++){
        int h;
        cin >> h;
        monster[i].second = h;
        total+=h;
    }
    sort(monster.begin(),monster.end());
    for (int i =0;i<k;i++)cin >> tower[i];
    int a = f(0,0,w,monster,tower);
    cout << total - a;
    return 0;
}