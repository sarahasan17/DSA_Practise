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
        if(rear==n-1){
            cout<<"Queue overflow"<<endl;
            return;
        }
        if (front==-1){
            front=0;
        }
        rear++;
        arr[rear]=a;
    }
    int deletion(){
        if(front==-1 || front>rear){
            cout<<"Queue underflow"<<endl;
            return -1;
        }
        return arr[front++];
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
    int a=q.deletion();
    int b=q.deletion();
    q.insertion(2);
    q.insertion(3);
    q.insertion(4);
    q.display();
}
