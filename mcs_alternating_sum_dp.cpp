#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int>v(n+1);
    for (int i = 1;i<=n;i++)cin >> v[i];
    int cur_1,cur_2,m1,m2;
    cur_1 = m1 = v[1];
    if (n == 1){
        cout << m1;
        return 0;
    }
    cur_2 = m2 = v[2];
    cur_1 = cur_1 - v[2];
    m1 = max(m1,cur_1);
    for (int i = 3;i<=n;i++){
        if (i%2 == 0){
            cur_1 = cur_1-v[i];
            m1 = max(cur_1,m1);
            cur_2 = max(cur_2+v[i],v[i]);
            m2 = max(m2,cur_2);
        }else{
            cur_1 = max(cur_1+v[i],v[i]);
            m1 = max(m1,cur_1);
            cur_2 = cur_2-v[i];
            m2 = max(m2,cur_2);
        }
    }
    cout << max(m2,m1);
    return 0;
}