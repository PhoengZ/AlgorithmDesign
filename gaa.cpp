#include<iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> v;
    v.push_back(3);
    int n;
    cin >> n;
    int i = 1;
    if (n <=3){
        if (n == 1)cout << "g";
        else cout << "a";
    }else{
        while (v.back() < n){
            v.push_back(2*v.back() + 1 + i + 2);
            i++;
        }
        //for (auto & e:v)cout << e << " ";
        bool found = false;
        int idx = v.size()-2;
        while (n > 3){
            while (n <= v[idx]){
                i--;
                idx--;
            }
            long long middle = (i-1)+3;
            long long des = v[idx];
            n-= des;
            if (n<=middle){
                if (n == 1)cout << "g";
                else cout <<"a";
                found = true;
                break;
            }
            n-=middle;
            i--;
            idx--;
        }
        if (!found){
            if (n == 1)cout << "g";
            else cout << "a";
        }
    }
    
    return 0;
}