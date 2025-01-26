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
    int count = 2;
    int start = 3;
    while (true){
            for (int j = 0;j<count;j++){
                v.push_back(v.back() + start);
            }
            count++;
            start++;
        }
        cout << v.back() << endl;
    return 0;
}

