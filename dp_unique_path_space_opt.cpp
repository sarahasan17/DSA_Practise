//n unique paths
//all possible ways
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> prev(4,0);
    vector<vector<int>> a(4,vector<int>(4,0));
    prev[0]=1;
    for(int i=0;i<3;i++){
        vector<int> temp(4,0);
        for(int j=0;j<3;j++){
            if(a[i][j]==-1){
                temp[j]=0;
            }
            else if(i==0 && j==0){
                temp[0]=1;
            }
            else{
                int l=0;
                int r=0;
                if(i>0){
                    l=prev[j];
                }
                if(j>0){
                    r=temp[j-1];
                }
                temp[j]=l+r;
            }
        }
        prev=temp;
    }
    cout<<prev[2];
}
