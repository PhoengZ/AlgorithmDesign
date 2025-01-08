#include <iostream>
#include <vector>

using namespace std;

//รับตัวเลขมาสองตัวตั้งแต่ a จนถึง b โดย a,b เป็นช่วงตัวเลข ให้หาว่าในช่วงตัวเลขนั้นมีตัวเลขใดที่เป็น perfect number บ้าง เป็น CSP
//perfect number คือ ผลรวมของตัวประกอบของตัวเลขนั้นๆมีค่าเท่ากับ ตัวมันเอง
int main(){
    int a,b;
    cin>>a>>b;
    vector <int> v;
    for (int i = a;i<=b;i++){
        int sum = 0;
        for (int j = 1;j<=i/2;j++){
            if (i%j==0)sum+=j;
        }
        if (sum == i)v.push_back(i);
    }
    for (auto &e:v)cout<<e<<" ";
    return 0;
}