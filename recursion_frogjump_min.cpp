#include <iostream>
using namespace std;
//recursion->take all possible steps
int frog_jump(int n,int a[]){
    if(n==0){
        return 0;
    }
    int left=frog_jump(n-1,a)+abs(a[n]-a[n-1]);
    int right=10000000;
    if(n>1){
        right=frog_jump(n-2,a)+abs(a[n]-a[n-2]);
    }
    return min(left,right);
}
int main(){
    int a[]={10,20,30,10};
    int n=frog_jump(4,a);
    cout<<"The minimum no. of distance covered by the from during jump:"<<n<<endl;
}
