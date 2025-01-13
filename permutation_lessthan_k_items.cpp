#include <iostream>
#include  <vector>
using namespace std;
void perm_kn(int n ,vector <int> & sol,int len, vector<bool> & used,int k){
    
    if (len < k){
        for (int i = 1;i<=n;i++){
            if (used[i] == false){
                used[i] =true;
                sol[len] = i;
                for (int j = 0;j<len+1;j++)cout << sol[j] << " ";
                cout << endl;
                perm_kn(n,sol,len+1,used,k);
                used[i] = false;
            }
        }
    }
}
int main(){
    vector <int> vp(4);
    vector <bool> used(4);
    for (int i = 0;i<4;i++){
        used[i] = false;
    }
    perm_kn(4,vp,0,used,3);
    return 0;
}