#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;




int main(){
    double W;
    int n;
    cin >> W >> n;
    double value = 0;
    vector<double>w(n);
    vector<double>v(n);
    vector<pair<double,pair<double,double>>>x(n);
    for (int i = 0;i<n;i++)cin >> v[i];
    for (int i = 0;i<n;i++)cin >> w[i];
    for (int i = 0;i<n;i++){
        x[i].first =  double(v[i])/w[i];
        cout << x[i].first << " ";
        x[i].second.first = v[i];
        x[i].second.second = w[i];
    }
    sort(x.begin(),x.end(),greater<>());
    for (int i = 0;i < n;i++){
        if (W >= x[i].second.second){
            W -= x[i].second.second;
            value += x[i].second.first;
        }else{
            value += (x[i].first * W);
            W = 0;
            break;
        }
    }
    // cout << fixed << setprecision(4) << value;
    return 0;
}