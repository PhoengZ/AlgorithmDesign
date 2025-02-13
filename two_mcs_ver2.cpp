#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int>v(n);
    for (int i =0;i<n;i++)cin >> v[i];
    int current_sum1,ans_1,current_sum2,ans_2;
    current_sum1 = ans_1 = v[0];
    int left = 0;
    int right = 0;
    int real_l,real_r;
    real_l = real_r = 0;
    for (int i = 1;i<n;i++){
        if (current_sum1 + v[i] > v[i]){
            right = i;
            current_sum1 = current_sum1 + v[i];
        }else{
            left = i;
            right = i;
            current_sum1 = v[i];
        }
        if (ans_1 < current_sum1){
            real_l = left;
            real_r = right;
            ans_1 = current_sum1;
        }
    }
    current_sum2 = ans_2 = -1100;
    for (int i = 0;i<n;i++){
        if (i >= real_l && i <= real_r){
            current_sum2 = -1100;
        }else{
            current_sum2 = max(current_sum2 + v[i],v[i]);
            ans_2 = max(ans_2,current_sum2);
        }
    }
    if (ans_2 != -1100 && ans_2 + ans_1 > ans_1){
        cout << ans_2 + ans_1;
    }else cout << ans_1;
    
    return 0;
}