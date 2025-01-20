#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>&v, vector<int> & temp,int start, int stop,int mid){
    int vi = start;
    int ti = mid+1;
    for (int i = start;i<=stop;i++){
        if (vi > mid){
            temp[i] = v[ti];
            ti++;
        }else if (ti > stop){
            temp[i] = v[vi];
            vi++;
        }else{
            if (v[vi] < v[ti]){
                temp[i] = v[vi];
                vi++;
            }else{
                temp[i] = v[ti];
                ti++;
            }
        }
    }
    for (int i = start;i<=stop;i++)v[i] = temp[i];
}

void merge_sort(vector<int> &v, int start, int stop, vector <int>&temp){
    if (start < stop){
        int mid = start+ (stop-start)/2;
        merge_sort(v,start,mid,temp);
        merge_sort(v,mid+1,stop,temp);
        merge(v,temp,start,stop,mid);
    }
}


int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0;i<n;i++)cin >> v[i];
    vector <int> merge(n);
    merge_sort(v,0,v.size()-1,merge);
    for (auto & e:v)cout << e << " ";
    return 0;
}