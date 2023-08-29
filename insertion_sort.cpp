#include <iostream>
using namespace std;
void insertion(int a[],int len){
    for(int i=1;i<len;i++){
        int j=i-1;
        int key=a[i];
        while(j>=0 and a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}
int main(){
    int a[]={2,3,4,1,5,2,8,1};
    insertion(a,8);
    cout<<"Insertion sort:"<<endl;
    for(int i=0;i<8;i++){
        cout<<a[i]<<" ";
    }
}
