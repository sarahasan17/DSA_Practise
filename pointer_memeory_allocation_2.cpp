#include <iostream>
using namespace std;

int main(){
    int *pt1;
    pt1=new int[5];
    cout<<"Enter elements of pointer 1:"<<endl;
    for(int i=0;i<5;i++){
        cin>>pt1[i];
    }
    for(int i=0;i<5;i++){
        cout<<pt1[i]<<' ';
    }
    delete pt1;
}
