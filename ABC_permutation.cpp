#include <iostream>
#include <vector>
using namespace std;

void my_recur(string & sol, int a, int count_a, int j, int count_j, int k, int count_k, int n, int len, vector<string> & vp){
    if (len < n){
        if (count_a < a){
            sol+= 'A';
            my_recur(sol,a,count_a+1,j,count_j,k,count_k,n,len+1,vp);
            sol.pop_back();
        }
        if (count_j < j){
            sol+='B';
            my_recur(sol,a,count_a,j,count_j+1,k,count_k,n,len+1,vp);
            sol.pop_back();
        }
        if (count_k < k){
            sol+='C';
            my_recur(sol,a,count_a,j,count_j,k,count_k+1,n,len+1,vp);
            sol.pop_back();
        }
    }else{
        vp.push_back(sol);
    }
}
int main(){
    int n,i,j,k,count;
    string sol = "";
    vector<string> vp;
    cin >> n >> i >> j >> k;
    my_recur(sol,i,0,j,0,k,0,n,0,vp);
    cout << vp.size()<<endl;
    for (auto & e:vp){
        cout << e<<endl;
    }
    return 0;
}