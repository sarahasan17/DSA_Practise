#include<iostream>
#include <conio.h>
using namespace std;

void heapify(int a[],int i,int n){
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && a[l]>a[largest]){
        largest=l;
    }
    if(r<n && a[r]>a[largest]){
        largest=r;
    }
    if(largest!=i){
        int temp=a[i];
        a[i]=a[largest];
        a[largest]=temp;
        heapify(a,largest,n);
    }
}
void heapsort(int a[],int n){
    for(int i=(n/2);i>=0;i--){
        heapify(a,i,n);
    }
    for(int i=n-1;i>=0;i--){
        int temp=a[i];
        a[i]=a[0];
        a[0]=temp;
        heapify(a,0,i);
    }
}

int main(){
    int a[7];
    cout<<"Enter the elements of the array"<<endl;
    for(int i=0;i<7;i++){
        cin>>a[i];
    }
    heapsort(a,7);
    for(int i=0;i<7;i++){
        cout<<a[i]<<" ";
    }
}
