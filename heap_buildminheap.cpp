#include<iostream>
#include <conio.h>
using namespace std;

void minheapify(int a[],int k,int n){
    int j,temp;
    temp=a[k];
    j=2*k;
    while(j<n){
        if(j<n && a[j]>a[j+1]){
            j=j+1;
        }
        if(temp<a[j]){
            break;
        }
        else if(temp>=a[j]){
            a[j/2]=a[j];
            j=j*2;
        }
    }
    a[j/2]=temp;
    return;
}

void buildminheap(int a[],int n){
    for(int i=n/2;i>=0;i--){
        minheapify(a,i,n);
    }
}

int main(){
    int a[7];
    cout<<"Enter the elements of the array"<<endl;
    for(int i=0;i<7;i++){
        cin>>a[i];
    }
    buildminheap(a,7);
    for(int i=1;i<=7;i++){
        cout<<a[i]<<" ";
    }
}
