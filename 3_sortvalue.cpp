#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int>v(n+1);
    int o1,o2,o3;
    o1 = o2 = o3 = 0;    
    for (int i = 1;i<=n;i++){
        cin >> v[i];
        if (v[i] == 1)o1++;
        if (v[i] == 2)o2++;
        if (v[i] == 3)o3++;
    }
    int one_2,one_3,second_1,second_3,third_1,third_2;
    one_2 = one_3 = second_1 = second_3 = third_1 = third_2 = 0;
    int count = 0;
    for (int i = 1;i<=n;i++){
        if (i <= o1){
            if (v[i] == 2)one_2++;
            if (v[i] == 3)one_3++;
        }
        else if (i <= o1 + o2){
            if (v[i] == 1)second_1++;
            if (v[i] == 3)second_3++;
        }
        else{
            if (v[i] == 2)third_2++;
            if (v[i] == 1)third_1++;
        }
    }
    int c1 = min(one_2,second_1);
    count+=c1;
    one_2 -= c1;
    second_1-=c1;
    int c2 = min(one_3,third_1);
    count+=c2;
    one_3-= c2;
    third_1-=c2;
    int c3 = min(second_3,third_2);
    count+=c3;
    second_3-=c3;
    third_2-=c3;
    count+= (one_2+one_3+second_1+second_3+third_1+third_2)/3 * 2;
    cout << count;
    return 0;
}