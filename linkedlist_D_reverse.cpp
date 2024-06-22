#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;
    node *prev;
    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};
class LinkedList{
    public:
    node* head;
    LinkedList(){
        head=NULL;
    }
    void insert(int a){
        node* temp=new node(a);
        if(head==NULL){
            head=temp;
        }
        else{
            node *t=head;
            while(t->next!=NULL){
                t=t->next;
            }
            t->next=temp;
            temp->prev=t;
        }
    }
    void reverse(){
        node *temp=head;
        node* prev=NULL;
        node* next=NULL;
        while(temp!=NULL){
            next=temp->next;
            temp->next=temp->prev;
            temp->prev=next;
            prev=temp;
            temp=next;
        }
        head=prev;
    }
    void display(){
        node *t=head;
        while(t!=NULL){
            cout<<t->data<<" ";
            t=t->next;
        }
        
    }
};
int main(){
    LinkedList l=LinkedList();
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(4);
    l.reverse();
    l.display();
}
