#include <iostream>
#include <vector>
using namespace std;

class dice{
    public:
        int top;
        int bottom;
        int left;
        int right;
        int front;
        int back;
        int x;
        int y;
        int value;
        
};

int main(){
    int R,C,p,q;
    cin >> R >> C >> p >> q;
    vector<int>dice(6);
    for (int i = 0;i<6;i++)cin >> dice[i];
    return 0;
}