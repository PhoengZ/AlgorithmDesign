#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>>v(n);
    vector<int> c(m);
    for (int i =0;i<n;i++){
        int idx;
        cin>>idx;
        v[i] = {idx,0};
    }
    for (int i =0;i<m;i++){
        cin >> c[i];
    }
    int pos = v.size()-2;
    while (pos >= 0){
        int index = pos+1;
        pair<int,int> tmp = v[pos];
        while (index < v.size() && v[index].first < tmp.first){
            v[index].second++;
            v[index - 1] = v[index];
            index++;
        }
        v[index - 1] = tmp;
        pos--;
    }
    for (auto & e:c){
        auto low = lower_bound(v.begin(),v.end(),make_pair(e,0));
        cout << low->second << endl;
    }

    return 0;
}