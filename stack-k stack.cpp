#include<iostream>
using namespace std;
class kstack{
    int **a;
    int *top;
    public:
    kstack(){
        top=new int[100];
        a = new int *[100];
        for(int i=0;i<100;i++){
            top[i]=-1;
            a[i]=new int[100];
        }
    }
    void push(int a1,int t1){
        if(top[t1]==99){
            cout<<"Stack "<<t1<<" is full"<<endl;       
        }
        else{
            top[t1]++;
            a[t1][top[t1]]=a1;
        }
    }
    int pop(int t1){
        if(top[t1]==-1){
            cout<<"Stack "<<t1<<" is empty"<<endl;        
        }
        return a[t1][top[t1]--];
    }
    void display(int t1){
        cout<<"Elements of stack "<<t1<<endl;
        for(int i=top[t1];i>=0;i--){
            cout<<a[t1][i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    kstack s;
    s.push(1,1);
    s.push(2,1);
    s.push(3,1);
    s.push(4,3);
    s.push(5,3);
    s.display(1);
    s.display(3);
    s.pop(1);
    s.pop(1);
    s.pop(1);
    s.pop(1);
}

