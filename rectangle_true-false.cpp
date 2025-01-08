#include <iostream>
#include <vector>
using namespace std;

//รับ input  เป็น array 2 มิติ n ช่องและแต่ละช่อง จะ contain ค่า true หรือ false ให้ output 
//ออกมาเป็น row-col ที่ top-leftและ row-col ที่ bottom-right ที่ทุกช่องในช่วงนั้นประกอบไปด้วยค่า true ทุกค่าใน array 2มิติ n ช่อง smallestด้วย

int main(){
    int n;
    cin>> n;
    int tc = 0;
    vector<vector<bool>> v(n);
    for (int i = 0;i<n;i++){
        for (int j = 0;j<n;j++){
            int k;
            cin>>k;
            if (k == 1)tc+=1;
            v[i].push_back(k);
        }
    }
    int r_1,c_1,r_2,c_2;
    int total = 0;
    int best_total = n*n;
    for (int i = 0;i<n;i++){
        for (int j = 0;j<n;j++){
            for (int k = n-1;k>i;k--){
                for (int l = n-1;l>j;l--){
                    int cou = 0;
                    for (int row = i;row<=k;row++){
                        for (int col = j;col<=l;col++){
                            if (v[row][col] == 1)cou+=1;
                            total+=1;
                        }
                    }
                    if (cou == tc &&total < best_total){
                        r_1 = i+1;
                        c_1 = j+1;
                        r_2 = k+1;
                        c_2 = l+1;
                    }
                }
            }
        }
    }
    cout << "top-left are: (" << r_1 << "," <<c_1 <<") bottom-right are: ("<< r_2 << "," <<c_2 <<")";
    return 0;
}

// Candidate solution:      |     Set of candidate solutions       |
// (a,b),(c,d)              |     (