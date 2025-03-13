#include <iostream>
#include <vector>
using namespace std;

int cal (int left, int right, int total, vector<int>&psum){
    if (left > right)swap(left,right);
    int result = min(psum[right]-psum[left],total - psum[right]+ psum[left]);
    return result;
}


int main(){
    int n,m;
    cin >> n >> m;
    vector<int>v(m+1),e(m+1),p(m+1);
    int total = 0;
    for (int i = 1;i<=m;i++)cin >> v[i];
    for (int i = 1;i<=m;i++){
        cin >> e[i];
        p[i]+=p[i-1]+e[i];
        total += e[i];
    }
    for (int j = 1;j<=n;j++){
        int a,b;
        cin >> a >> b;
        int answer = 0;
        int left,right;
        left = v[1];
        right = v[0];
        for (int i = 2;i<=m;i++){
            left = v[i-1];
            right = v[i];
            int result = cal(left,right,total,p);
            result = min(result,cal(left,a,total,p) + cal(b,right,total,p));
            result = min(result,cal(left,b,total,p) + cal(a,right,total,p));
            answer+=result;
        }
        left = v[m];
        right = v[1];
        int result = cal(left,right,total,p);
        result = min(result,cal(left,a,total,p) + cal(b,right,total,p));
        result = min(result,cal(left,b,total,p) + cal(a,right,total,p));
        answer+=result;
        cout <<answer << endl;
    }
    return 0;
}