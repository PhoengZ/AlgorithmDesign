#include <iostream>
#include <vector>
using namespace std;


int main(){
    int n,w;
    cin>>n;
    vector<int> v(n);
    for (int i =0;i<n;i++)cin>>v[i];
    cin>>w;
    int index = 0;
    int left = 0;
    int total = 0;
    for (int i  =0;i<w;i++){
        total+=v[i];
    }
    int best_total = total;
    for (int i = w;i<n;i++){
        total = total - v[left]+v[i];
        if (best_total < total){
            best_total = total;
            index = left;
        }
        left++;
    }
    cout << index;
    return 0;
}

// candidate solution      |         set of candidate solutions           |        satisfaction conditions        
//       x                 |              (1,2,3,.....,n)                 |  sum of value sigma_from y = 1 to y = n-w:(sigma)