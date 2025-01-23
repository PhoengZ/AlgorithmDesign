#include <iostream>
#include <vector>

using namespace std;


int main(){
    int n;
    cin >> n;
    int x;
    cin >> x;
    int current_sum_1,current_sum_2,a,b;
    current_sum_1 = a = current_sum_2 = b= x;
    for (int i = 1;i<n;i++){
        int y;
        cin >> y;
        current_sum_2 = max(current_sum_2+y,a + y);
        b = max(b,current_sum_2);
        current_sum_1 = max(current_sum_1+y,y);
        a = max(a,current_sum_1);
    }
    cout << b;
    return 0;
}