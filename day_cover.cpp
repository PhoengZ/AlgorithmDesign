#include <iostream>
#include <set>
#include <vector>
#include<map>
#include <climits>

using namespace std;

void cover(int target, int now, int day ,int t_day, vector<vector<bool>> & canuse, int & MIN, set<int> & sel,vector<pair<int,set<int>>> & mp){
    if (MIN != 21)return;
    if (now > target && day != t_day){
        mp.push_back({day,sel});
        return;
    }
    if (day == t_day && now == target){
        MIN = now;
        return ;
    }
    bool found = false;
    for (auto & e:sel){
        if (canuse[e][day]){
            cover(target,now,day+1,t_day,canuse,MIN,sel,mp);
            found = true;
            return;
        }
    }
    if (!found){
        for (int i =0;i<canuse.size();i++){
            if (canuse[i][day] && !sel.count(i)){
                sel.insert(i);
                cover(target,now+1,day+1,t_day,canuse,MIN,sel,mp);
                sel.erase(i);
            }
        }
    }
    
}

int main(){
    int MIN = 21;
    int n,m;
    cin >> n >> m;
    vector<vector<bool>> vp(m);
    for (int i = 0;i<m;i++){
        vector<bool> c(n);
        int k;
        cin>>k;
        vp[i] = c;
        for (int j =0;j<k;j++){
            int idx;
            cin>> idx;
            vp[i][idx-1] = true;
        }
    }
    int target = 1;
    set<int> s;
    int d = 0;
    int now = 0;
    vector<pair<int,set<int>>> temp;
    cover(target,now,d,n,vp,MIN,s,temp);
    for (int i =0;i<m;i++){
        vector<pair<int,set<int>>> mp;
        for (auto & e:temp){
            now = e.second.size();
            d = e.first;
            s = e.second;
            cover(target,now,d,n,vp,MIN,s,mp);
            if (MIN!=21)break;
        }
        if (MIN != 21)break;
        temp = mp;
        set<int> p;
        
        target++;
    }
    cout << MIN;
    return 0;
}