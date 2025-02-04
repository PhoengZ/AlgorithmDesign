#include <iostream>
#include <vector>
using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin >> n >> k;
    vector<int> v(n+1);
    for (int i =1;i<=n;i++)cin >> v[i];
    int now,ans,now_1;
    now = ans = now_1 = v[1];
    int count = 1;
    int count_1 = 1;
    bool c = false;
    for (int i = 2;i<=n;i++){
        if (count_1 == k && count != k){
            count_1 = 1;
            now_1 = v[i];
            now = max(now+v[i],v[i]);
            if (v[i] == now)count = 1;
            else count++;
        }
        else if (count == k && count_1 != k){
            count = 1;
            now = v[i];
            if (c){
                now_1 = v[i];
                count_1 = 1;
                c= false;
            }else{
                now_1 = max(now_1 + v[i],v[i]);
                count_1++;
            }
            if (v[i] < 0)c = true;
        }else if (count_1 == k && count == k){
            count_1 = 1;
            now_1 = v[i];
            count = 1;
            now = v[i];
        }
        else{
            now = max(now+v[i],v[i]);
            if (c){
                now_1 = v[i];
                count_1 = 1;
                c= false;
            }else{
                now_1 = max(now_1 + v[i],v[i]);
                count_1++;
            }
            if (v[i] < 0)c = true;
            if (v[i] == now)count = 1;
            else count++;
        }
        now = max(now,now_1);
        ans = max(now,ans);
    }
    cout << ans;
    return 0;
}

