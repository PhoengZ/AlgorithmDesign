#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int f,n,w;
    cin >> f >> w >> n;
    vector<int>table(f+1);
    for (int i = 1;i<=f;i++){
        cin >> table[i];
    }
    sort(table.begin(),table.end());
    int count = 0;
    pair<int,int>interval = make_pair(0,0);
    for (int i = 1;i<=f;i++){
        if (table[i] < interval.first || table[i] > interval.second){
            count++;
            interval.first = table[i];
            interval.second = table[i] + 2*w;
        }
    }
    cout << count;
    return 0;
}