#include <iostream>
#include <set>
#include <vector>
#include <climits>

using namespace std;
/*
void cover(vector<vector<bool>> & day_off, int n, int m, int count, int day, vector<int> & used,int & MIN){
    if (day > n){
        MIN = min(MIN, count);
        return;
    }
    if (count >= MIN)return;
    else{
        for (int i = 0;i<m;i++){
            if (day_off[i][day-1]){
                if (used[i] == 0){
                    used[i]++;
                    cover(day_off,n,m,count+1,day+1,used,MIN);
                    used[i]--;
                }else{
                    used[i]++;
                    cover(day_off,n,m,count,day+1,used,MIN);
                    used[i]--;
                }
            }
        }
    }
}

    

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    int MIN = 20;
    vector<int> used(m);
    vector<vector<bool>> day_off(m);
    for (int i =0;i<m;i++){
        vector<bool> vp(n);
        day_off[i] = vp;
    }
    for (int i =0;i<m;i++){
        int k;
        cin>>k;
        for (int j = 0;j<k;j++){
            int off;
            cin>> off;
            day_off[i][off-1] = true;
        }
    }
    cover(day_off,n,m,0,1,used,MIN);
    cout << MIN;
    return 0;
}
First solutions: score 50 */

void cover(int target, int now, int day ,int t_day, vector<int> & use_coub, vector<vector<bool>> & canuse, int & MIN){
    if (MIN != 21)return;
    if (now > target && day != t_day-1)return;
    if (day == t_day && now <= target){
        MIN = now;
        return ;
    }
    for (int i =0;i<use_coub.size();i++){
        if (canuse[i][day]){
            if (use_coub[i] == 0){
                use_coub[i]++;
                cover(target,now+1,day+1,t_day,use_coub,canuse,MIN);
                use_coub[i]--;
            }else{
                use_coub[i]++;
                cover(target,now,day+1,t_day,use_coub,canuse,MIN);
                use_coub[i]--;
            }
        }
    }
}

int main(){
    int MIN = 21;
    int n,m;
    cin >> n >> m;
    vector<vector<bool>> vp(m);
    vector<int> check(m);
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
    for (int i =0;i<m;i++){
        cover(target,0,0,n,check,vp,MIN);
        if (MIN != 21)break;
        target++;
    }
    cout << MIN;
    return 0;
}