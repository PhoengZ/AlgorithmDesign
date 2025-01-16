#include <iostream>
#include<vector>
#include <algorithm>
#include<map>

using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n,q;
    cin >> n >> q;
    map<int,int> mp;
    vector<pair<int,int>> stroage;
    for (int i = 0 ;i<n;i++){
        int number,quantity;
        cin >> number >> quantity;
        mp[number]+= quantity;
    }
    int count = 0;
    for (auto & e:mp){
        count += e.second;
        stroage.push_back({count,e.first});
    }
    for (int i =0;i<q;i++){
        int j;
        cin>> j;
        auto low = lower_bound(stroage.begin(),stroage.end(),make_pair(j,0));
        cout << low->second << endl;
    }
    return 0;
}