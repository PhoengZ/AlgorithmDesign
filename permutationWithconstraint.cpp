#include <iostream>
#include <vector>

using namespace std;

void my_recur(vector<int>& constraint_1, int target, int len, vector<int> &sol, vector<bool>&used){
    if (len == target){
        for (auto & e:sol)cout << e << " ";
        cout << "\n";
    }
    else{
        for (int i =0;i<target;i++){
            if (!used[i] && (constraint_1[i] == -1 || used[constraint_1[i]])){
                sol.push_back(i);
                used[i] = true;
                my_recur(constraint_1,target,len+1,sol,used);
                sol.pop_back();
                used[i] = false;
            }
            
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> con(n,-1);
    for (int i =0 ;i<m;i++){
        int a,b;
        cin >> a >> b;
        con[b] = a;
    }
    vector<bool> used(n);
    vector<int> sol;
    my_recur(con,n,0,sol,used);
    return 0;
}