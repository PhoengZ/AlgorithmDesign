#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n,l;
    cin >> n >> l;
    vector<int>p(n+1);
    for (int i = 1;i<=n;i++)cin >> p[i];
    int count = 0;
    pair<int,int>place = make_pair(0,0);
    sort(p.begin(),p.end());
    for (int i = 1;i<=n;i++){
        if (p[i] < place.first || p[i] > place.second){
            count++;
            place.first = p[i];
            place.second = p[i]+l-1;
        }
    }
    cout << count;
    return 0;
}