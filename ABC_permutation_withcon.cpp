#include <iostream>
#include <vector>
#include <set>
using namespace std;

void recur(set<string>&nt, vector<string>&sol, vector<int>&con, vector<int>&count,int n, int len, string s){
    if (n == len){
        sol.push_back(s);
        return ;
    }
    for (int i = 0;i<3;i++){
        if (count[i] >= con[i])continue;
        string c;
        if (s.length() == 0){
            c = "";
        }else{
            c = s.back();
        }
        string o = s;
        if (i == 0){
            if (nt.count(c+"A"))continue;
            o+= "A";
            count[i]++;
            recur(nt,sol,con,count,n,len+1,o);
            count[i]--;
        }else if (i == 1){
            if (nt.count(c+"B"))continue;
            o+="B";
            count[i]++;
            recur(nt,sol,con,count,n,len+1,o);
            count[i]--;
        }else{
            if (nt.count(c+"C"))continue;
            o+="C";
            count[i]++;
            recur(nt,sol,con,count,n,len+1,o);
            count[i]--;
        }
    }
}

int main(){
    int n,i,j,k;
    cin >> n >> i >> j >> k;
    int m;
    cin >> m;
    set<string> v;
    for (int i = 0;i<m;i++){
        string e;
        cin >>e;
        v.insert(e);
    }
    vector<string> sol;
    vector<int> con(3);
    vector<int> now(3);
    con[0] = i;
    con[1] = j;
    con[2] = k;
    recur(v,sol,con,now,n,0,"");
    cout << sol.size() <<endl;
    for (auto & e:sol)cout << e <<endl;
    return 0;
}