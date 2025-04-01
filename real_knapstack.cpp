#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

double u(vector<vector<double>>&ratio, int idx, double w, double total){
    double t = total;
    double we = w;
    for (int i = idx;i>0;i--){
        if (we -ratio[i][2] >= 0){
            we-=ratio[i][2];
            t+=ratio[i][1];
        }else{
            t+=(ratio[i][0]*we);
            break;
        }
    }
    return t;
}

void f(vector<vector<double>>&ratio, double &ans, int idx, double w, double total){
    if (w < 0)return;
    if (idx == 0){
        ans = max(total,ans);
        return ;
    }
    if (u(ratio,idx,w,total) < ans)return ;
    f(ratio,ans,idx-1,w-ratio[idx][2],total+ratio[idx][1]);
    f(ratio,ans,idx-1,w,total);
    return ;
}

int main(){
    int n;
    double w;
    cin >> w >> n;
    vector<vector<double>>v(n+1,vector<double>(3));
    for (int i = 1;i<=n;i++){
        cin >> v[i][1];
    }
    for (int i = 1;i<=n;i++){
        cin >> v[i][2];
        v[i][0] = v[i][1]/v[i][2];
    }
    sort(v.begin(),v.end());
    double answer = 0;
    f(v,answer,n,w,0);
    cout << fixed <<setprecision(4) <<answer;
    return 0;
}
