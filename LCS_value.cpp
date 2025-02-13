#include <iostream>

using namespace std;

int main(){
    string a,b;
    cin >> a >> b;
    int table[a.length()+1][b.length()+1];
    for (int i = 0;i<=b.length();i++)table[0][i] = 0;
    for(int i =0;i<=a.length();i++)table[i][0] = 0;
    for (int i = 1;i<=a.length();i++){
        for(int j = 1;j<=b.length();j++){
            if (a[i-1] == b[j-1])table[i][j] = table[i-1][j-1] +1;
            else table[i][j] = max(table[i-1][j],table[i][j-1]);
        }
    }
    cout << table[a.length()][b.length()];
    return 0;
}