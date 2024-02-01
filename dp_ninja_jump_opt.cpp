#include<iostream>
#include <vector>
using namespace std;

int main(){
    int a[3][3]={{5,3,3},{3,7,2},{10,2,1}};
    vector<int> prev(4,0);
    prev[0]=max(a[0][1],a[0][2]);
    prev[1]=max(a[0][0],a[0][2]);
    prev[2]=max(a[0][1],a[0][0]);
    prev[3]=max(prev[0],a[0][0]);
    for(int day=1;day<3;day++){
        vector<int> temp(4,0);
        for(int last=0;last<4;last++){
            for(int i=0;i<3;i++){
                if(i!=last){
                    int price=a[day][i]+prev[i];
                    temp[last]=max(price,temp[last]);
                }
            }
        }
        prev=temp;
    }
    cout<<prev[3];
}
