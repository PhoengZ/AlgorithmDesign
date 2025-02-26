#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int target;
vector<string>v;

void f(int n, int w, int b, string a){
    if (b > w || b < 1)return ;
    if (n == target){
        v.push_back(a);
        return ;
    }
    f(n+1,w,b+1,a+"U"); //U
    f(n+1,w,b-1,a+"D"); //D
    f(n+1,w,b,a+"S");
}

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(0);
    int n,w,b;
    cin >> n >> w >> b;
    target = n;
    f(0,w,b,"");
    sort(v.begin(),v.end());
    for (auto & e:v)cout << e << "\n";
    return 0;
}
