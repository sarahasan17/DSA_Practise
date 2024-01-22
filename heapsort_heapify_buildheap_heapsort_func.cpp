#include <iostream>
using namespace std;

void heapify(int a[],int i,int n){
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && a[l]>a[largest]){
        l=largest;
    }
    if(r<n && a[r]>a[largest]){
        r=largest;
    }
    if(largest!=i){
        int temp=a[largest];
        a[largest]=a[i];
        a[i]=temp;
        heapify(a,largest,n);
    }
}
void buildheap(int a[],int n){
    for(int i=n/2;i>=0;i--){
        heapify(a,i,n);
    }
}

void heapsort(int a[],int n){
    buildheap(a,n);
    for(int i=n-1;i>=0;i--){
        int temp=a[0];
        a[0]=a[i];
        a[i]=temp;
        heapify(a,0,i);
    }
}
int main(){
    int a[]={4,3,6,2,9,1,8};
    int len=sizeof(a)/sizeof(a[0]);
    heapsort(a,len);
    for(int i=0;i<len;i++){
        cout<<a[i]<<" ";
    }
}
