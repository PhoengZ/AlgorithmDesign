#include<iostream>
#include <vector>

using namespace std;

vector<int> mt(vector<int> & contain){

}

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> base(n);
    for (int i = 0;i<4;i++)cin >> base[i];
    vector <int> v = mt();
    long long value = 1<<n;
    for (int i = 0;i<m;i++){
        long long r,c;
        cin >> r >> c;
        long long index = (r-1)*value;
        index+= c;
        cout << v[index];
    }
    return 0;
}
