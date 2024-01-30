#include <iostream>
using namespace std;

int sum_of_no_adj(int n,int a[]){
    if(n==0){
        return a[n];
    }
    if(n<0){
        return 0;
    }
    int pick=a[n]+sum_of_no_adj(n-2,a);
    int pick2=0+sum_of_no_adj(n-1,a);
    return max(pick,pick2);
}
int main(){
    int a[]={2,4,2,-2};
    cout<<"sum of non adjacent values:"<<sum_of_no_adj(4,a)<<endl;
}
