#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> & v,int start, int stop, int mid, vector<int>&temp, int & count){
    int ls = start;
    int ms = mid+1;
    int cou = 0;
    bool check = false;
    for (int i = start;i<=stop;i++){
        if (ls > mid){
            temp[i] = v[ms];
            ms++;
        }else if (ms > stop){
            count+=cou;
            temp[i] = v[ls];
            ls++;
        }else{
            if (v[ls] <= v[ms]){
                if (cou != 0)count+=cou;
                temp[i] = v[ls];
                ls++;
            }else{
                temp[i] = v[ms];
                ms++;
                cou++;
            }
        }
    }
    for (int i = start;i<=stop;i++)v[i] = temp[i];
}

void merge_sort(vector<int> &v,int start, int stop, vector<int> &temp, int &count){
    if(start < stop){
        int mid = start + (stop - start)/2;
        merge_sort(v,start,mid,temp,count);
        merge_sort(v,mid+1,stop,temp,count);
        merge(v,start,stop, mid, temp, count);
    }
}


int main(){
    int n;
    cin>> n;
    vector<int> vp(n);
    int count = 0;
    for (int i = 0;i<n;i++)cin >> vp[i];
    vector<int> temp(n);
    merge_sort(vp,0,n-1,temp,count);
    cout << count;
    return 0;
}