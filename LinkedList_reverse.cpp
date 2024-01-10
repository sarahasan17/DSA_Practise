#include <iostream>
#include <conio.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(){
        data=0;
        next=NULL;
    }
    node(int a){
        data=a;
        next=NULL;
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
   }
   
   void reverse(){
       node *curr=head;
       node *next=NULL;
       node *prev=NULL;
       while(curr!=NULL){
           next=curr->next;
           curr->next=prev;
           prev=curr;
           curr=next;
       }
       head=prev;
   }
   void display(){
       node *curr=head;
       while(curr!=NULL){
           cout<<curr->data<<"-->";
           curr=curr->next;
       }
   }
};
