#include <iostream>
#include <conio.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node *prev;
    node(){
        data=0;
        next=NULL;
        prev=NULL;
    }
    node(int a){
        data=a;
        next=NULL;
        prev=NULL;
    }
};

class LinkedList{
   public:
   node *head;
   void insert(int a){
       if(head==NULL){
           node *temp=new node(a);
           head=temp;
           return;
       }
       node *curr=head;
       while(curr->next!=NULL){
           curr=curr->next;
       }
       node *temp=new node(a);
       curr->next=temp;
       temp->prev=curr;
   }
 
   void reverse(){
       node *temp=head;
       node *prev=NULL;
       while(temp!=NULL){
           prev=temp->prev;
           temp->prev=temp->next;
           temp->next=prev;
           temp=temp->prev;
       }
       head=prev->prev;
   }
    void display(){
       node *curr=head;
       while(curr!=NULL){
           cout<<curr->data<<"-->";
           curr=curr->next;
       }
   }
};
int main(){
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    list.insert(6);
    list.reverse();
    list.display();
}

