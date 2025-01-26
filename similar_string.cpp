#include <iostream>

using namespace std;
bool f(string &a,string &b,int len){
    if (len == 2){
        if (a[0] == b[0] && a[1] == b[1])return true;
        return a[0] == b[1] && a[1] == b[0] ? true:false;
    }
    string a1,a2,b1,b2;
    a1 = a2  = b1 =b2;
    bool sel = true;
    for (int i = 0;i<len;i++){
        if (a[i] != b[i])sel = false;
        if (i < len/2){
            a1+=a[i];
            b1+=b[i];
        }
        else{
            a2 += a[i];
            b2 += b[i];
        }
    }
    return f(a1,b1,len/2) && f(a2,b2,len/2) || f(a1,b2,len/2) && f(a2,b1,len/2);
}

int main(){
    string a;
    string b;
    cin >> a >>b;
    bool check = f(a,b,b.length());
    if (check)cout << "YES";
    else cout << "NO";
    return 0;
}