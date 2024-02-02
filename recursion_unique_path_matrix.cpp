//n unique paths
//all possible ways
#include <iostream>
#include <vector>
using namespace std;
int unique_paths(vector<vector<int>> a,int i,int j){
    if(i==0||j==0){
        return 1;
    }
    if(i<0 || j<0){
        return 0;
    }
    int l=unique_paths(a,i-1,j);
    int r=unique_paths(a,i,j-1);
    return l+r;
}

int main()
{
    vector<vector<int>>a(4,vector<int>(4,1));
    cout<<unique_paths(a,1,1);
}
