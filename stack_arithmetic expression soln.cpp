#include <iostream>
using namespace std;
#define n 100
class stack{
    int top;
    char *arr;
    int top1;
    char *arr1;
    public:
    stack(){
        top=-1;
        arr=new char[n];
        top1=-1;
        arr1=new char[n];
    }
    void push(char a){
        if(top==n-1){
            cout<<"Stack is full"<<endl;
            return;
        }
        top++;
        arr[top]=a;
    }
    char pop(){
        if(top==-1){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return arr[top--];
    }
    bool empty(){
        return top==-1;
    }
    char Top(){
        return arr[top];
    }
    void push1(char a){
        if(top1==n-1){
            cout<<"Stack is full"<<endl;
            return;
        }
        top1++;
        arr1[top1]=a;
    }
    char pop1(){
        if(top1==-1){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return arr1[top1--];
    }
    bool empty1(){
        return top1==-1;
    }
    char Top1(){
        return arr1[top1];
    }
};
int pref(char a){
    if(a=='*' || a=='/'){
        return 3;
    }
    else if(a=='+' ||a=='-'){
        return 2;
    }
    return 1;
}
int main(){
    string a="(A-B)*[C/(D+E)+F]";
    stack s;
    s.push1('#');
    for(int i=0;i<a.length();i++){
        if(isalpha(a[i])){
            s.push(a[i]);
        }
        else if(a[i]=='*' || a[i]=='-' || a[i]=='/' || a[i]=='+'){
            if(pref(s.Top1())<pref(a[i]) ||s.Top1()=='[' ||s.Top1()=='(' ||s.Top1()=='{'){
                s.push1(a[i]);
            }
            else{
                while(pref(s.Top1())>=pref(a[i])){
                    s.push(s.pop1());
                }
            }
        }
        else{
           if(a[i]=='[' ||a[i]=='(' ||a[i]=='{'){
               s.push1(a[i]);
           }
           else if(a[i]==']' ||a[i]==')' ||a[i]=='}'){
               while(s.Top1()!='[' && s.Top1()!='(' &&s.Top1()!='{'){
                   s.push(s.pop1());
               }
               char c=s.pop1();
           }
        }
    }
    while(s.Top1()!='#'){
        s.push(s.pop1());
    }
    while(s.empty()==false){
        s.push1(s.pop());
    }
    while(s.Top1()!='#'){
        cout<<s.pop1()<<" ";
    }
}
