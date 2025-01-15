#include <iostream>
#include <vector>
using namespace std;
void my_recur(vector<vector<int>> & graph, vector<vector<int>>&sol,vector<bool> & visit,vector<int> & check,int count){
    for (int i = 0;i<graph.size();i++){
        if (check.size() == 0){
            check.push_back(i);
            visit[i] = true;
            my_recur(graph,sol,visit,check,count+1);
            check.pop_back();
            visit[i] = false;
        }else{
            int row = check.back();
            if (!visit[i] && graph[row][i] != 0){
                visit[i] = true;
                check.push_back(i);
                //if (count+1 == graph.size()+1 && check.back() == check.front())sol.push_back(check);
                my_recur(graph,sol,visit,check,count+1);
                check.pop_back();
                visit[i] = false;
            }else if (visit[i] == true && count + 1 == graph.size()+1){
                check.push_back(i);
                if (count+1 == graph.size()+1 && check.back() == check.front())sol.push_back(check);
                check.pop_back();
            }
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> vp(n);
    vector<vector<int>> path;
    vector<bool> visit(n);
    vector<int> check;
    for (int i =0 ;i<n;i++){
        for (int j = 0;j<n;j++){
            int k;
            cin >>k;
            vp[i].push_back(k);
        }
    }
    my_recur(vp,path,visit,check,0);
    int count = 0;
    cout << "Output:"<<endl;
    for (auto & e:path){
        cout << "Path: ";
        for (auto & i:e){
            cout << i << " ";
        }
        cout << "Cost: " << e.size()<<endl;
    }
    return 0;
}


