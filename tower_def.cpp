#include <iostream>
#include <vector>
using namespace std;

void tower_def(vector<int> &pos,vector<int> & contain, vector<int> & p_monster, vector<int> & h_monster, vector<int> & turret, int health, int & count){
    if (contain[4] == turret.size()){
        count = min(health,count);
        return ;
    }
    if (turret.size() - contain[4] < abs(count - health) && health > count){
        return;        
    }
    int start = max(turret[contain[4]]-contain[3],0);
    int end = min(turret[contain[4]]+contain[3],contain[0]);
    bool check = false;
    for (int i = start;i<=end;i++){
        if (pos[i] != 0 && h_monster[i] != 0){
            contain[4]++;
            h_monster[i]--;
            check = true;
            tower_def(pos,contain,p_monster,h_monster,turret,health-1,count);
            check =false;
            h_monster[i]++;
            contain[4]--;
        }
    }
    if (!check){
        contain[4]++;
        tower_def(pos,contain,p_monster,h_monster,turret,health,count);
        contain[4]--;
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
    vector<int> position(n);
    vector<int> p_monster(m);
    vector<int> h_monster(n);
    vector<int> turret(k);
    int health = 0;
    for (int i  = 0;i<m;i++){
        cin>>p_monster[i];
    }
    for (int i = 0;i<m;i++){
        position[p_monster[i]]++;
    }
    for (int i  = 0;i<m;i++){
        int hp;
        cin >> hp;
        h_monster[p_monster[i]]+= hp;
        health+= hp;
    }
    int count = health;
    for (int i = 0;i<k;i++)cin>>turret[i];
    tower_def(position,v,p_monster,h_monster,turret,health,count);
    cout << count;
    return 0;
}