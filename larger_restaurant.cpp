#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

long long gcd(long long a, long long b){
    if (b == 0)return a;
    return gcd(b, a % b);
}

long long lcm(long long a, long long b){
    return abs(a*b)/gcd(a,b);
}

int main(){
    int n,a;
    cin >> n >> a;
    vector<int> v(n);
    unordered_map<int,int> up;
    priority_queue< pair<int,pair<int,int>> ,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    for (int i = 0 ;i<n;i++){
        cin >> v[i];
        pq.push({0,{i+1,i}});
    }
    int LCM = v[0];
    if (n != 1){
        for (int i =1;i<n;i++){
            LCM = lcm(LCM,v[i]);
        }
    }
    //cout << LCM;
    int num = n+1;
    int count = 0;
    while (!pq.empty()){
        auto p = pq.top();
        pq.pop();
        if (p.first != LCM){
            up[count++] = p.first;
            pq.push({p.first+v[p.second.second],{num,p.second.second}});
            num++;
        }
    }

    for (int i = 0;i<a;i++){
        int idx;
        cin >>idx;
        int time = LCM*(idx/count);
        if (idx%count == 0) time+= up[idx%count];
        else time += up[(idx%count)-1];
        cout << time <<endl;
    }
    return 0;
}