#include <iostream>
#include <vector>
#include <climits>

using namespace std;
int f(vector<int>&v,vector<int>&p_1, vector<int>&p_2, int start, int stop){
    if (start == stop)return v[start];
    int mid = start + (stop - start)/2;
    int left = f(v,p_1,p_2,start,mid);
    int right = f(v,p_1,p_2,mid+1,stop);
    int max_l_1,max_l_2,max_r_1,max_r_2;
    if (start % 2 == 0){
        max_l_2 = p_2[mid]-p_2[start-1];
        max_l_1 = start >= mid ? 0: p_1[mid] - p_1[start];
    }else{
        max_l_1 = p_1[mid]-p_1[start-1];
        max_l_2 = start >= mid ? 0: p_2[mid] - p_2[start];
    }
    max_r_1 = p_1[mid+1] - p_1[mid];
    max_r_2 = p_2[mid+1] - p_2[mid];
    for (int i = start;i<=mid;i++){
        int m;
        if (i%2 == 0){
            m = p_2[mid] - p_2[i-1];
            max_l_2 = max(max_l_2,m);
        }else{
            m = p_1[mid] - p_1[i-1];
            max_l_1 = max(max_l_1,m);
        }
    }
    for (int i = mid+1;i<=stop;i++){
        int m,n;
        m = p_2[i]-p_2[mid];
        n = p_1[i] - p_1[mid];
        max_r_1 = max(max_r_1,n);
        max_r_2 = max(max_r_2,m);
    }
    int real = max_r_1 + max_l_1 > max_r_2 + max_l_2 ?max_r_1 + max_l_1:max_r_2 + max_l_2;
    return max(real,max(left,right));
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n+1);
    vector<int>p_1(n+1);
    vector<int>p_2(n+1);
    for (int i =1;i <= n;i++){
        cin >> v[i];
        if (i%2 == 1){
            p_1[i] = p_1[i-1] + v[i];
            if (i > 1)p_2[i] = p_2[i-1] - v[i];
        }else{
            p_1[i] = p_1[i-1] - v[i];
            p_2[i] = p_2[i-1] + v[i];
        }
        
    }

    int ans = f(v,p_1,p_2,1,n);
    cout << ans;
    return 0;
}
