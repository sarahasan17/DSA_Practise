#include<iostream>
using namespace std;
void merge(int a[],int l,int h,int mid){
    int n=mid-l+1;
    int m=h-mid;
    int n1[n+1];
    int n2[m+1];
    for(int i=0;i<n;i++){
        n1[i]=a[l+i];
    }
    for(int j=0;j<m;j++){
        n2[j]=a[mid+j+1];
    }
    n1[n]=100000000;
    n2[m]=100000000;
    int j=0;
    int k=0;
    for(int i=l;i<=h;i++){
        if(n1[j]<=n2[k]){
            a[i]=n1[j];
            j+=1;
        }
        else{
            a[i]=n2[k];
            k+=1;
        }
    }
}
void mergesort(int a[],int l,int h){
    if(l<h){
        int mid=(l+h)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,h);
        merge(a,l,h,mid);
    }
}
int main(){
    int a[]={9,8,7,6,6,5,8,1};
    cout<<"Merge sort"<<endl;
    mergesort(a,0,7);
    for(int i=0;i<8;i++){
        cout<<a[i]<<" ";
    }
}
