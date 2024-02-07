#include <iostream>
#include <vector>
using namespace std;
//cherry picky 3d dP 
//dp-13
int cherrypickup(int a[3][3], int i,int j1,int j2,int n){
    if(j1<0 || j1>n-1, j2<0 || j2>n-1){
        return -100000;
    }
    if(i==n-1){
        if(j1==j2){
            return a[i][j1];
        }
        else{
            return a[i][j1]+a[i][j2];
        }
    }
    int maxi=0;
    int val;
    for(int d=-1;d<=1;d++){
        for(int k=-1;k<=1;k++){
            if(j1==j2){
                val=a[i][j1]+cherrypickup(a,i+1,j1+d,j2+d,n);
            }
            else{
                val=a[i][j1]+a[i][j2]+cherrypickup(a,i+1,j1+d,j2+d,n);
            }
            if(val>maxi){
                maxi=val;
            }
        }
    }
    return maxi;
}
int main()
{
    int a[3][3]={{1,1,1},{1,1,1},{1,1,1}};
    cout<<cherrypickup(a,0,0,2,3);
    
}
