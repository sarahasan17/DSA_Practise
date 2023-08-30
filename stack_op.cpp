#include <iostream>
using namespace std;
#define n 100
class stack{
    int top;
    int *arr;
    public:
    stack(){
        top=-1;
        arr=new int[n];
    }
    void push(int a){
        if(top==n-1){
            cout<<"Stack is full"<<endl;
            return;
        }
        top++;
        arr[top]=a;
        cout<<"Push "<<arr[top]<<" into stack"<<endl;
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
};

int main(){
    stack s;
    s.push(1);
    s.pop();
    s.pop();
    bool b=s.empty();
    cout<<b<<endl;
    s.push(2);
    s.push(3);
    s.Top();
    
}
