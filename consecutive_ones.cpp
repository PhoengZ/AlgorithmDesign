#include <iostream>
#include <vector>
using namespace std;
void con_one(vector<char> & contain,string & sol, int n, int m, int len, int count,int c_max){
    if (len < n){
        for (auto & e:contain){
            if (e == '1' && (n-len) < (m-count) && c_max < m)return;
            sol+=e;
            if (e == '1'){
                if (count < c_max){
                    con_one(contain,sol,n,m,len+1,count+1,c_max);
                }else{
                    con_one(contain,sol,n,m,len+1,count+1,c_max+1);
                }
                
            }else{
                con_one(contain,sol,n,m,len+1,0,c_max);
            }
            sol.pop_back();
        }
    }else {
        if (m <= c_max)cout << sol <<endl;
    }
}
int main(){
    int n,m;
    vector<char> character(2);
    character[0] = '0';
    character[1] = '1';
    cin  >> n >> m;
    string sol = "";
    con_one(character,sol, n, m, 0, 0,0);
    return 0;
}