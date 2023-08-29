#include <iostream>
using namespace std;
void counting(int a[],int len){
    int max=a[0];
    for(int i=0;i<len;i++){
        if(max<a[i]){
            max=a[i];
        }
    }
    int count[max+1];
    for(int i=0;i<=max;i++){
        count[i]=0;
    }
    for(int i=0;i<len;i++){
        count[a[i]]++;
    }
    for(int i=1;i<=max;i++){
        count[i]+=count[i-1];
    }
    int out[len];
    for(int i=len-1;i>=0;i--){
        out[count[a[i]]]=a[i];    
        count[a[i]]--;
    }
    for(int i=0;i<=len;i++){
        a[i]=out[i];
    }
}
int main(){
    int a[]={2,3,4,1,5,2,8,1};
    counting(a,8);
    cout<<"Counting sort:"<<endl;
    for(int i=1;i<=8;i++){
        cout<<a[i]<<" ";
    }
    //0 0 0 0 0 0 0 0 0
    //0 2 2 1 1 1 0 0 1 
    //0 2 4 5 6 7 7 7 8 
    //1 1 2 2 3 4 5 8
}
