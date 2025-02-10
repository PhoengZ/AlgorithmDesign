#include <iostream>
#include <vector>
using namespace std;

int f(int left, int right, int n, vector<int>&v, vector<int>&table){
    if (abs(right-left) == 1){
        return v[right] > v[left] ? v[right]:v[left];
    }
    if (table[n]!=0)return table[n];

}

int main(){
    int n;
    cin >>n;
    vector<int>v(n);
    vector<int>table(n);
    for (int i = 0;i<n;i++)cin >> v[i];
    return 0;
}