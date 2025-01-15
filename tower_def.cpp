#include <iostream>
#include <vector>
using namespace std;

void tower_def(vector<int> & contain, vector<int> & p_monster, vector<int> & h_monster, vector<int> & turret, int health){
    for (int i = contain[4];i<turret.size();i++){
        
    }
}

int main(){
    int n,m,k,w;
    cin >> n >> m >> k >> w;
    vector<int> v(5);
    v[0] = n;
    v[1] = m;
    v[2] = k;
    v[3] = w;
    v[4] = 0;
    vector<int> p_monster(m);
    vector<int> h_monster(m);
    vector<int> turret(k);
    int health = 0;
    for (int i  = 0;i<m;i++){
        cin>>p_monster[i];
    }
    for (int i  = 0;i<m;i++){
        cin>> h_monster[i];
        h_monster[i] = h_monster[i]*p_monster[i];
        health+=h_monster[i];
    }
    for (int i = 0;i<k;i++)cin>>turret[i];
    tower_def(v,p_monster,h_monster,turret,health);
    return 0;
}