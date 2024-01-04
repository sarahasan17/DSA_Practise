#include <iostream>
using namespace std;
int binary(int a[],int l,int h,int x){
    while(l<=h){
        int mid=(h+l)/2;
        if(a[mid]==x){
            return mid;
        }
        else if(a[mid]<x){
            l=mid+1;
        }
        else if(a[mid]>x){
            h=mid-1;        
            
        }
    }
    return -1;
    
}
int main(){
    int a[]={1,2,3,6,8,9};
    int m=binary(a,0,5,9);
    cout<<m<<endl;
}
