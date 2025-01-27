#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> v(4);
    v[1] = 1;
    v[2] = 3;
    v[3] = 5;
    int index = 3;
    int count = 3;
    while (v.back() < 2*1e9){
        if (count < v[index]){
            v.push_back(index + v.back());
            count++;
        }else{
            index++;
        }
    }
    for (int i =0;i<n;i++){
        int find;
        cin >> find;
        auto low = lower_bound(v.begin(),v.end(),find);
        int value = low - v.begin();
        cout << value <<endl;
    }
    return 0;
}

