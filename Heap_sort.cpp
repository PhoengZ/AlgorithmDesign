#include <iostream>
#include <vector>

using namespace std;

void fixdown(vector<int> & A, int index,int size){
    int tmp = A[index];
    int c = 2*index+1;
    while (c < size){
        if (c+1 < size && A[c+1] > A[c])c++;
        if (tmp >= A[c])break;
        A[index] = A[c];
        index = c;
        c = 2*index+1;
    }
    A[index] = tmp;
}

void heap_sort(vector<int> & A){
    for (int i = (A.size()/2) - 1;i >= 0;i--){
        fixdown(A,i,A.size());
    }
    int pos = A.size()-1;
    while (pos > 0){
        swap(A[0],A[pos]);
        pos--;
        fixdown(A,0,pos);
    }
}

int main(){
    int n;
    cin >> n;
    vector <int> vp(n);
    for (int i = 0;i< n;i++)cin >> vp[i];
    heap_sort(vp);
    for (auto & e:vp)cout << e << " ";
    return 0;
}