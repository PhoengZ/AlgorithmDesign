#include <iostream>
#include <vector>
using namespace  std;
int main(){
    int arr [] = {1,4,10,23,57,132,301,701};
    vector <int> v(20);
    for (int i = 0;i<20;i++)cin>>v[i];
    for (int i = 2;i>=0;i--){
        vector <vector<int>> gap(arr[i]);
        for (int j = 0;j<20;j++){
            gap[j%arr[i]].push_back(v[j]);
        }
        int max_size = v.size()/arr[i];
        if (v.size() % arr[i] != 0)max_size+=1;
        for (int j = 0;j<gap.size();j++){
            if (gap[j].size() == 0)break;
            int pos = gap[j].size()-1;
            while (pos > 0){
                int index = pos-1;
                int tmp = gap[j][index];
                while (index+1 < gap[j].size() && gap[j][index+1] < tmp){
                    gap[j][index] = gap[j][index+1];
                    index++;
                }
                gap[j][index] = tmp;
                pos-=1;
            }    
        }
        int count = 0;
        for (int k = 0;k<max_size;k++){
            for (int j = 0;j<arr[i];j++){
                v[count] = gap[j][k];
                count++;
            }
        }
        
    }
    for (auto & e:v)cout << e << " ";
    return 0;
}
