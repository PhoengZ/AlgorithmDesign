#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int f(vector<int>&table, int n, int a, int b, int c){
    if (n < 0)return INT_MIN;
    if (table[n] != 0)return table[n];
    if (n == 0)return 0;
    int first_1 = f(table,n-a,a,b,c);
    int second_1 = f(table,n-b,a,b,c);
    int third_1 = f(table,n-c,a,b,c);
    table[n] = max(first_1,max(second_1,third_1)) + 1;
    return table[n];
}

int main(){
    int n,a,b,c;
    cin >> n >> a >> b >> c;
    vector<int> table(n+1);
    int ans = f(table,n,a,b,c);
    cout << ans;
    return 0;
}