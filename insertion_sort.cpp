#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> v(5);
    for (int i = 0;i<5;i++)cin>>v[i];
    int pos = 3;
    while (pos >= 0){
        int i = pos+1;
        while (i<= 4&&v[pos] > v[i])i+=1;
        int j = pos;
        int tmp = v[pos];
        while (j < i-1){
            v[j] = v[j+1];
            j+=1;
        }
        v[i-1] = tmp;
        pos--;
    }
    for (auto & e:v)cout << e << " ";
    return 0;
}