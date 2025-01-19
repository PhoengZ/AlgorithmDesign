#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin>> n;
    map <int,int> m;
    map <int,bool> found;
    vector<int> s;
    for (int i =0;i<n;i++){
        int a,b;
        cin >> a >>b;
        if (m.count(a)){
            if (m[a] < b){
                m[a] = b;
                s.push_back(a);
                s.push_back(b);
            }
        }else{
            m[a] =b;
            s.push_back(a);
            s.push_back(b);
        }
        
    }
    sort(s.begin(),s.end());
    bool first = true;
    int left = 0;
    int right = 0;
    bool reset = false;
    for (auto it = s.begin();it!=s.end();it++){
        if (first){
            left = *it;
            right = m[*it];
            first = false;
        }else{
            if (reset){
                if (( *it == right || *it == right+1) && m.count(*it)){
                    reset =false;
                    right = m[*it];
                }else if (found.count(*it) && found[*it]){
                    continue;
                }else{
                    cout << left << " " << right << " ";
                    left = *it;
                    right = m[*it];
                    reset = false;
                }
            }else{
                if (m.count(*it) && *it != m[*it]){
                    if (m[*it] > right){
                        right = m[*it];
                    }
                }else{
                    if (right == *it){
                        found[*it] = true;
                        reset = true;
                    }
                }
            }
        }
    }
    if (reset)cout << left << " " << right << " ";
    return 0;
}

