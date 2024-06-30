#include <iostream>
using namespace std;

void minheapify(int a[],int i,int n){
    int temp=a[i];
    int j=2*i+1;
    while(j<n){
        if(j+1<n && a[j]>a[j+1]){
            j=j+1;
        }
        if(temp<a[j]){
            break;
        }
        a[(j-1)/2]=a[j];
        j=2*j+1;
    }
    a[(j-1)/2]=temp;
    return;
}
void minheap(int a[],int n){
    for(int i=(n/2);i>=0;i--){
        minheapify(a,i,n);
    }
}
int main(){
    int a[]={5,3,8,2,6,9,1};
    minheap(a,7);
    for(int i=0;i<7;i++){
        cout<<a[i]<<" ";
    }
}
