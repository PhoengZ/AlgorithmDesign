#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int seq(vector<int>&v, vector<int>&s,int start, int stop){
    if (start == stop)return v[start];
    int mid = start + (stop-start)/2;
    int left = seq(v,s,start,mid);
    int right= seq(v,s,mid+1,stop);
    unordered_map<int,pair<int,int>> up;
    for (int i = mid;i<=stop;i++){
        if (up[v[i]].first != 0){
            int dif = s[i] - s[up[v[i]].first];
            up[v[i]] = dif > 0 ? make_pair(i,up[v[i]].second + dif): up[v[i]];
        }else{
            up[v[i]] = {i,v[i]};
        }
    }
    int sum = 0;
    bool first = true;
    for (int i = start;i<=mid;i++){
         if (!up.count(v[i]))continue;
         if (first){
            sum = s[up[v[i]].first] - s[i-1];
            first = false;
         }else{
            sum = max(sum,s[up[v[i]].first] - s[i-1]);
         }
    }
    int c = left > right? left:right;
    return max(c,sum);
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n+1);
    vector<int> sum(n+1);
    for (int i =1;i<=n;i++){
        cin >> v[i];
        sum[i]+= sum[i-1] + v[i];
    }
    int a = seq(v,sum,1,n);
    cout << a;
    return 0;
}