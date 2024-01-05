#include <iostream>
using namespace std;
class stack{
    int getmax;
    int top;
    int *arr;
    public:
    stack(){
        getmax=-10000;
        top=-1;
        arr=new int[10];
    }
    void push(int a){
        if(top==9){
            cout<<"no more elements can be inserted"<<endl;
            return;
        }
        if(a>getmax){
            top+=1;
            arr[top]=a;
            getmax=a;
        }
    }
    int pop(){
        return arr[top--];
    }
    int getmax1(){
        return arr[top];
    }
};
int main(){
    stack a;
    a.push(5);
    a.push(4);
    a.push(3);
    a.push(7);
    a.push(3);
    cout<<a.pop()<<endl;
    cout<<a.getmax1()<<endl;
    
}
