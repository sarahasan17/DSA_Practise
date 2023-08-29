#include <iostream>
using namespace std;
void selection(int a[],int len){
    for(int i=0;i<len;i++){
        int min=i;
        for(int j=i+1;j<len;j++){
            if(a[j]<a[min]){
                min=j;
            }
        }
        int t=a[i];
        a[i]=a[min];
        a[min]=t;
        
    }
}
int main(){
    int a[]={2,3,4,1,5,2,8,1};
    selection(a,8);
    cout<<"Selection sort:"<<endl;
    for(int i=0;i<8;i++){
        cout<<a[i]<<" ";
    }
}
