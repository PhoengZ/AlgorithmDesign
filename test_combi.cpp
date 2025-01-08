#include <iostream>
#include <vector>

using namespace std;
void combi(int n,vector<int> &sol,int len){
    if (len < n){
        sol[len] = 0;
        combi(n,sol,len+1);
        sol[len] = 1;
        combi(n,sol,len+1);
    }else{
        for (int i =0;i<n;i++){
           cout << sol[i]<< " ";
        }
        cout << "." << endl;
    }
}
int main()
{
    vector <int> v(3);
    combi(3,v,0);
    return 0;
}
