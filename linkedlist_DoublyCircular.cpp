#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* prev;
    node(int a){
        data=a;
        next=NULL;
        prev=NULL;
    }
};
class LinkedList{
    public:
    node *head;
    LinkedList(){
        head=NULL;
    }
    void insert_beg(int a){
        node *temp=new node(a);
        if(head==NULL){
            head=temp;
            head->next=head;
            head->prev=head;
        }
        else{
            node *t=head;
        while(t->next!=head){
            t=t->next;
        }
        t->next=temp;
        temp->prev=t;
        temp->next=head;
        head->prev=temp;
        head=temp;
        }
        
    }
    void insert_end(int a){
        node *temp=new node(a);
        if(head==NULL){
            head=temp;
            head->next=head;
            head->prev=head;
        }
        else{
            node *t=head;
            while(t->next!=head){
                t=t->next;
            }
            t->next=temp;
            temp->next=head;
            head->prev=temp;
            temp->prev=t;
        }
    }
    void delete_beg(){
        node *t=head;
        while(t->next!=head){
            t=t->next;
        }
        t->next=head->next;
        head=head->next;
        head->prev=t;
    }
    void delete_end(){
        node *t=head;
        if(t->next==head){
            head=NULL;
        }
        else{
            while(t->next->next!=head){
                t=t->next;
            }
            t->next=head;
            head->prev=t;
        }
    }
    void display(){
        node *t=head;
        while(t->next!=head){
            cout<<t->prev<<" "<<t<<" "<<t->next<<endl;
            t=t->next;
        }
        cout<<t->prev<<" "<<t<<" "<<t->next<<endl;  
    }
};
int main(){
    LinkedList l=LinkedList();
    l.insert_beg(1);
    l.insert_beg(2);
    l.insert_end(3);
    l.insert_end(4);
    l.delete_end();
    l.delete_beg();
    l.display();
}
