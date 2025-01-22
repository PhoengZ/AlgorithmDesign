#include <iostream>
#include <vector>

using namespace std;
int s = 0;
int l;
void count(vector<int>&test, int start, int stop, int mid,bool &check, vector<int>&temp, bool &up){
    int ls = start;
    int rs = mid+1;
    bool found = false;
    for (int i = start;i<=stop;i++){
        if (ls > mid){
            temp[i] = test[rs];
            rs++;
        }else if (rs > stop){
            up = true;
            temp[i] = test[ls];
            ls++;
        }else{
            if (test[ls] >= test[rs]){
                if (test[ls] == 1 && test[rs] == 1)found = true;
                temp[i] = test[rs];
                rs++;
            }else{
                temp[i] = test[ls];
                ls++;
            }
        }
        if (found){
            check = false;
            return ;
        }
    }
    for (int i = start;i<=stop;i++)test[i] = temp[i];
    if (found){
        check = false;
        return ;
    }
}

void check_virus(vector<int>&test, int start, int stop, bool &check, vector<int> &temp, bool &up){
    if (start < stop){
        int mid = start + (stop - start)/2;
        bool c = false;
        check_virus(test,mid+1,stop,check,temp,up);
        if (up){
            
        }
        check_virus(test,start,mid,check,temp,up);
        count(test,start,stop,mid,check,temp,up);
    }
    if (!check)return;
    if (up && start == s && stop == l && start == 0 && stop == 1){
        check = false;
        return;
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    int length = 2;
    for (int i = 2;i<=m;i++)length*=2;
    l = length -1;
    vector<int> v(length);
    for (int i = 0;i<n;i++){
        vector<int> test(length);
        vector<int> tmp(length);
        for (int j = 0;j<length;j++)cin >> test[j];
        bool check = true;
        bool up = false;
        check_virus(test,0,test.size()-1,check,tmp,up);
        if (check)cout << "yes"<<endl;
        else cout << "no" <<endl;
    }
    return 0;
}