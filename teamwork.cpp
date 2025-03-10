#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int>people(n+1);
    vector<int>task(m+1);
    for (int i = 1;i<=m;i++)cin >> task[i];
    sort(task.begin(),task.end());
    double total = 0;
    int c = 0;
    for (int i  = 0;i<m/n;i++){
        for (int j = 1;j<=n;j++){
            people[j]+=task[i*n + j];
            total += people[j];
        }
        c++;
    }
    if (m%n != 0){
        int idx = 1;
        for (int i = 1;i<=m%n;i++){
            people[idx++] += task[c*n + i];
            total+= people[idx-1];
        }
    }
    double result =total/m;
    cout << fixed << setprecision(3) << result;
    return 0;
}