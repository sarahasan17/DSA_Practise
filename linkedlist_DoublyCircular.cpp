#include <bits/stdc++.h>
using namespace std; 

class node{
    public:
    int val;
    node* next;
    node* prev;
    node(int data){
        val=data;
        next=prev=NULL;
    }
};
class LinkedList{
    public:
    node* head;
    LinkedList(){
        head=NULL;
    }
    void insert_beg(int data){
        node* temp=new node(data);
        if(head==NULL){
            head=temp;
            head->next=head;
            head->prev=head;
            return;
        }
        node* t=head;
        while(t->next!=head){
            t=t->next;
        }
        t->next=temp;
        temp->next=head;
        head->prev=temp;
        temp->prev=t;
        head=temp;
    }
    void insert_end(int data){
        node* temp=new node(data);
        if(head==NULL){
            head=temp;
            head->next=head;
            head->prev=head;
            return;
        }
        node* t=head;
        while(t->next!=head){
            t=t->next;
        }
        t->next=temp;
        temp->next=head;
        head->prev=temp;
        temp->prev=t;
    }
    void delete_beg(){
        node* t=head;
        if(head==NULL) return;
        if(t->next==head){
            head=NULL;
            return;
        }
        node* n=head->next;
        while(t->next!=head){
            t=t->next;
        }
        t->next=head->next;
        head->next->prev=t;
        head=head->next;
        
    }
    void delete_end(){
        node* t=head;
        if(head==NULL) return;
        if(t->next==head){
            head=NULL;
            return;
        }
        node* n=head->next;
        while(n->next!=head){
            t=t->next;
            n=n->next;
        }
        t->next=head;
        head->prev=t;
        n->prev=NULL;
        n->next=NULL;
    }
    void display(){
        node* t=head;
        while(t->next!=head){
            cout<<t->val<<" ";
            t=t->next;
        }
        cout<<t->val;
        cout<<endl;
    }
};
int main(){
    LinkedList l;
    l.insert_end(1);
    l.insert_end(2);
    l.insert_end(3);
    l.insert_beg(4);
    l.delete_end();
    l.delete_beg();
    l.display();
    
}
