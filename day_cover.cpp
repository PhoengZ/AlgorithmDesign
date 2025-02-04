//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <climits>
#include <bits/stdc++.h>
using namespace std;

int n, m;                  
vector<vector<int>> s;  
vector<int> cv;        
int mn = 21;        

void fm(int index, int cnt, int c) {
    if (cnt== n) {
        mn = min(mn, c);
        return;
    }
    if (index== m||c>= mn) return;
    
    int newc = cnt;  
    for (int day : s[index]) {
        if (cv[day] == 0)
            newc++;          
        cv[day]++;
    }
    fm(index+1, newc, c + 1);

    for (int day : s[index]) {
        cv[day]--;
        if (cv[day] == 0)
            newc--;
    }
    fm(index +1, cnt, c);

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >>n >> m;
    s.resize(m);
    cv.assign(n+1,0);

    for (int i = 0; i < m; ++i) {
        int k;
        cin >>k;
        s[i].resize(k);
        for (int j= 0; j < k; ++j) {
            cin >>s[i][j];
        }
    }
    fm(0,0, 0);
    cout <<mn << "\n";
    
    return 0;
}