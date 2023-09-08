#include <iostream>
#define n 5
using namespace std;

class queue{
    int front;
    int rear;
    int *arr;
    public:
    queue(){
        front=rear=-1;
        arr=new int[n];
    }
    void insertion(int a){
        if(front==0 && rear==n-1){
            cout<<"Queue overflow"<<endl;
            return;
        }
        if (front==-1){
            front=0;
        }
        rear=(rear+1)%n;
        arr[rear]=a;
    }
    void deletion(){
        if(front==-1){
            cout<<"Queue underflow"<<endl;
            return;
        }
        if(front==rear){
            rear=-1;
            front=-1;
            return;
        }
        front=(front+1)%n;
    }
    void display(){
        cout<<"The elements of the queue are:"<<endl;
        for(int i=front;i<=rear;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main()
{
    queue q;
    q.insertion(1);
    q.deletion();
    q.deletion();
    q.insertion(2);
    q.insertion(3);
    q.insertion(4);
    q.insertion(5);
    q.insertion(6);
    q.insertion(4);
    q.display();
}
