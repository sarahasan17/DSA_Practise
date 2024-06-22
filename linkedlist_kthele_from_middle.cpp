#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;
    node(int val){
        data=val;
        next=NULL;
    }
};
class LinkedList{
    public:
    node *head;
    LinkedList(){
        head=NULL;
    }
    void insert(int a){
        node *temp=new node(a);
        if(head==NULL){
            head=temp;
        }
        else{
            node *t=head;
            while(t->next!=NULL){
                t=t->next;
            }
            t->next=temp;
        }
    }
    void kth_midd(int b){
        node *t=head;
        int c=0;
        while(t!=NULL){
            t=t->next;
            c++;
        }
        int g=0;
        int k=c/2;
        t=head;
        while(g!=k-b){
            t=t->next;
            g++;
        }
        cout<<t->data;
    }
};
int main(){
    LinkedList l=LinkedList();
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(4);
    l.insert(5);
    l.kth_midd(2);
}
