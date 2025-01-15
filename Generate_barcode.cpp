#include <iostream>
#include <vector>
using namespace std;

void generate_tif(vector<char> & contain,string & sol,int n, int m,int len, int count){
    if (len < m){
        for (auto & e:contain){
            if ((m-len) < n-count)return;
            if (e == '0'){
                sol+='0';
                generate_tif(contain,sol,n,m,len+1,count);
            }else{
                sol+='1';
                generate_tif(contain,sol,n,m,len+1,count+1);
            }
            sol.pop_back();
        }
    }else if (count == n) cout << sol <<endl;
}
int main(){
    int n,m;
    cin>> n>>m;
    string sol = "";
    vector<char>vp(2);
    vp[0] = '0';
    vp[1] = '1';
    generate_tif(vp,sol,n,m,0,0);
    return 0;
}