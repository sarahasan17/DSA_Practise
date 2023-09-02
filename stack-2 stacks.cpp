#include<iostream>
#define n 1000
using namespace std;
class stack{
    int top1;
    int top2;
    int *a1;
    int *a2;
    public:
    stack(){
        top1=-1;
        top2=-1;
        a1=new int[n];
        a2=new int[n];
    }
    void push1(int a){
        if(top1==n-1){
            cout<<"stack 1 is full"<<endl;
        }
        else{
            top1++;
            a1[top1]=a;
        }
        
    }
    void push2(int a){
        if(top2==n-1){
            cout<<"stack 2 is full"<<endl;
        }
        else{
            top2++;
            a2[top2]=a;
        }
        
    }
    int pop1(){
        if(top1==-1){
            cout<<"stack 1 is empty"<<endl;
            return -1;
        }
        return a1[top1--];
    }
    int pop2(){
        if(top2==-1){
            cout<<"stack 2 is empty"<<endl;
            return -1;
        }
        return a2[top2--];
    }
    int Top1(){
        return a1[top1];
    }
    int Top2(){
        return a2[top2];
    }
    void display1(){
        cout<<"Elements of stack 1"<<endl;
        for(int i=top1;i>=0;i--){
            cout<<a1[i]<<" ";
        }
        cout<<endl;
    }
    void display2(){
        cout<<"Elements of stack 2"<<endl;
        for(int i=top2;i>=0;i--){
            cout<<a2[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    stack s;
    s.push1(1);
    s.push1(2);
    s.display1();
    s.push2(3);
    s.push2(4);
    s.display2();
    int b=s.pop1();
    int c=s.pop1();
    int d=s.pop1();
}

