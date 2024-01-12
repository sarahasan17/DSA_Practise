#include <iostream>
using namespace std;

int main(){
    int *pt1;
    int *pt2;
    int *pt3;
    int avg;
    
    pt1=new int;
    pt2=new int;
    pt3=new int;
    cout<<"Enter number 1:"<<endl;
    cin>>*pt1;
    cout<<"Enter number 2:"<<endl;
    cin>>*pt2;
    cout<<"Enter number 3:"<<endl;
    cin>>*pt3;
    avg=((*pt1)+(*pt2)+(*pt3))/3;
    cout<<"avg:"<<avg<<endl;
    delete pt1;
    delete pt2;
    delete pt3;
}
