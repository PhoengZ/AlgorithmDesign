#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// O(nlog(n)) time complexity, O(n) space complexity
int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(0);
    int n;
    cin >> n;
    vector<int>oil(n);
    for (int i = 0;i<n;i++)cin >> oil[i];
    sort(oil.begin(),oil.end());
    int ans = 0;
    auto it = oil.begin();
    auto target = oil.end() - 1;
    int present = 0;
    while (it != target){
        auto next = lower_bound(oil.begin(),oil.end(),present + 100);
        if (*next == present + 100){
            present = *next;
            it = next;
        }
        else{
            next--;
            if (next == it){
                cout << -1 <<endl;
                return 0;
            }
            it = next;
            present = *it;
        }
        ans++;

    }
    ans++;
    cout << ans << endl;
    return 0;
}