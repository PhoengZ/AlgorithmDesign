#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int m;
void my_recur(vector<vector<int>>&cover, vector<int>&day, int target, int & now, int start,int & MIN, int count){
    if (target == now){
        MIN = min(MIN,count);
        return;
    }
    if (start >=m)return;
    if (count >= MIN)return;
    for (auto & e:cover[start]){
        if (day[e-1] == 0)now++;
        day[e-1]++;
    }
    my_recur(cover,day,target,now,start+1,MIN,count+1);
    for (auto & e:cover[start]){
        day[e-1]--;
        if (day[e-1] == 0)now--;
    }
    my_recur(cover,day,target,now,start+1,MIN,count);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int day;
    cin >> day >> m;
    vector<vector<int>> v(m);
    for (int i= 0;i< m;i++){
        int idx;
        cin >> idx;
        vector<int> vp(idx);
        for (int j = 0;j<idx;j++){
            int t;
            cin >> t;
            vp[j] = t;
        }
        v[i] = vp;
    }
    vector<int> d(day);
    int MIN = INT_MAX;
    int now = 0;
    my_recur(v,d,day,now,0,MIN,0);
    cout << MIN;
    return 0;
}