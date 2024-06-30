#include <iostream>
using namespace std;

void maxheapify(int a[],int i,int n){
    int temp=a[i];
    int j=2*i+1;
    while(j<n){
        if(j+1<n && a[j]<a[j+1]){
            j=j+1;
        }
        if(temp>a[j]){
            break;
        }
        a[(j-1)/2]=a[j];
        j=2*j+1;
    }
    a[(j-1)/2]=temp;
    return;
}
void maxheap(int a[],int n){
    for(int i=(n/2);i>=0;i--){
        maxheapify(a,i,n);
    }
}
int main(){
    int a[]={5,3,8,2,6,9,1};
    maxheap(a,7);
    for(int i=0;i<7;i++){
        cout<<a[i]<<" ";
    }
}
