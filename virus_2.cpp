#include <iostream>
#include <vector>
using namespace std;

void count(vector<int>&v, vector<int>&temp, int start, int stop, int mid, bool &check){
    int ls = start;
    int rs = mid+1;
    int cl = 0,cr = 0;
    for (int i = start;i<=stop;i++){
        if (ls > mid){
            if (v[rs] == 1)cr++;
            temp[i] = v[rs];
            rs++;
        }else if (rs > stop){
            if (v[ls] == 1)cl++;
            temp[i] = v[ls];
            ls++;
        }else{
            if (v[ls] >= v[rs]){
                if (v[rs] == 1)cr++;
                temp[i] = v[rs];
                rs++;
            }else{
                temp[i] = v[ls];
                ls++;
            }
        }
    }
    for (int i = start;i<=stop;i++)v[i] = temp[i];
    if (abs(cl-cr) > 1 && stop - start >= 3)check = false;
}

void spilt(vector<int>&v, int start, int stop, bool & check, vector<int> &temp){
    if (start < stop){
        int mid = start + (stop-start)/2;
        spilt(v,start,mid,check,temp);
        spilt(v,mid+1,stop,check,temp);
        count(v,temp,start,stop,mid,check);
    }
    if (!check)return;
}

int main(){
    int m,n;
    cin >> m >> n;
    int length = 2;
    for (int i = 2; i<=n;i++)length*=2;
    for (int i = 0;i<m;i++){
        vector<int> v(length);
        vector<int> temp(length);
        for (int j = 0;j<length;j++)cin >> v[j];
        bool check = true;
        spilt(v,0,v.size()-1,check,temp);
        if (check)cout << "yes" <<endl;
        else cout << "no" <<endl;
    }
    return 0;
}