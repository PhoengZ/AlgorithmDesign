#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <queue>
using namespace std;

class item{
    public:
        double weight;
        double value;
        int n;
        item(double w, double v, int n){
            weight = w;
            value = v;
            this->n = n;
        }
};
class compareable{
    public:
        bool operator()(const item& i, const item&j){
            return i.value < j.value;
        }
};

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
    priority_queue<item,vector<item>,compareable>pq;
    item i(w,0,n);
    pq.push(i);
    double answer = 0;
    while(!pq.empty()){
        item p = pq.top();
        pq.pop();
        if (p.weight < 0)continue;
        if (p.n == 0){
            answer = max(p.value,answer);
            continue;
        }
        if (u(v,p.n,p.weight,p.value) <= answer)continue;
        if (p.weight - v[p.n][2] >= 0){
            item t1(p.weight-v[p.n][2],p.value+v[p.n][1],p.n-1);
            pq.push(t1);
        }
        item t1(p.weight,p.value,p.n-1);
        pq.push(t1);
    }
    cout << fixed <<setprecision(4) <<answer;
    return 0;
}
