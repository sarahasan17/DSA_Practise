#include <iostream>
using namespace std;
void bubble(int a[],int len){
    for(int i=0;i<len;i++){
        for(int j=0;j<len-i-1;j++){
            if(a[j]>a[j+1]){
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
}
int main(){
    int a[]={2,3,4,1,5,2,8,1};
    bubble(a,8);
    cout<<"Bubble sort:"<<endl;
    for(int i=0;i<8;i++){
        cout<<a[i]<<" ";
    }
}
