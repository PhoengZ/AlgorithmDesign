#include <iostream>
#include <set>
#include <vector>
#include <climits>

using namespace std;

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