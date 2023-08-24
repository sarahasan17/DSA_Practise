#include<iostream>
using namespace std;
int partition(int a[],int l,int h){
    int j=l-1;
    for(int i=l;i<h;i++){
        if(a[i]<a[h]){
            j=j+1;
            int t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }
    int t=a[j+1];
    a[j+1]=a[h];
    a[h]=t;
    return j+1;
}
void quick(int a[],int l,int h){
    if(l<h){
        int p=partition(a,l,h);
        quick(a,l,p-1);
        quick(a,p+1,h);
    }
}
int main(){
    int a[]={9,8,7,6,5,4,3,2};
    quick(a,0,7);
    cout<<"Quick Sort"<<endl;
    for(int i=0;i<8;i++){
        cout<<a[i]<<" ";
    }
}

