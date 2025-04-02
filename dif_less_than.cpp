#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n,d;
    cin >> n >> d;
    vector<int>A(n);
    for (int i =0;i<n;i++)cin >> A[i];
    sort(A.begin(),A.end());
    int i = 0;
    int j = 1;
    long long count = 0;
    while (i != j){
        if (j == A.size()-1){
            count += abs(A[j]-A[i]) <= d ? (j-i):(j-i-1);
            i++;
            continue;
        }
        if (abs(A[j]-A[i]) <= d)j++;
        else{
            count += abs(A[j]-A[i]) <= d ? (j-i):(j-i-1);
            i++;
            if (i == j)j++;
        }
    }
    cout << count;
    return 0;
}