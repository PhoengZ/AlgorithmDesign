#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >>n;
    vector<int>room1,room2;
    int girls_1,girls_2,boys_1,boys_2;
    girls_1 = girls_2 = boys_1 = boys_2 = 0;
    for (int i = 1;i<=n;i++){
        int a;
        cin >> a;
        if (a == 2)girls_1++;
        else boys_1++;
        room1.push_back(a);
    }
    for (int i = n+1;i<2*n;i++){
        int a;
        cin >> a;
        if (a == 2)girls_2++;
        else boys_2++;
        room2.push_back(a);
    }
    if (girls_1 + girls_2 != (n-1) && boys_1 + boys_2 != n){
        cout << -1;
        return 0;
    }
    vector<int>ans;
    while (girls_1 != 0 && boys_2 != 0){
        if (girls_1 != 0){
            while (room1.back() != 2){
                room1.pop_back();
                ans.push_back(1);
            }
            room1.pop_back();
            girls_1--;
        }
        if (boys_2 != 0){
            while (room2.back() != 1){
                room2.pop_back();
                ans.push_back(2);
            }
            room2.pop_back();
            ans.push_back(2);
            boys_2--;
        }
        if (girls_1 > 0){
            ans.push_back(1);
        }
    }
    cout << ans.size() << endl;
    for (auto &e:ans)cout << e << " ";
    return 0;
}