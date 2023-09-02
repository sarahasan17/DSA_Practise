#include <iostream>
using namespace std;
#define n 100
class stack{
    int top;
    int getmin;
    int *arr;
    public:
    stack(){
        top=-1;
        getmin=10000000;
        arr=new int[n];
    }
    void push(int a){
        if(getmin>a){
           top++;
           arr[top]=a;
           getmin=a;
        }
    }
    int pop(){
        if(top==-1){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        cout<<"Poped "<<arr[top]<<" from stack"<<endl;
        return arr[top--];
    }
    bool empty(){
        return top==-1;
    }
    int Top(){
        return top;
    }
    int Getmin(){
        return arr[top];
    }
};

int main(){
    stack s;
    int l[]={3,2,5,1,-6,7,2};
    int length = sizeof(l) / sizeof(l[0]);
    for(int i=0;i<length;i++){
        s.push(l[i]);
    }
    cout<<"Minimum element: "<<s.Getmin()<<endl;
}
