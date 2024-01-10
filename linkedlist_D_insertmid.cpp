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
 
   void insert_middle(int a){
       int c=0;
       node *curr=head;
       while(curr!=NULL){
           curr=curr->next;
           c+=1;
       }
       node *temp=head;
       node *temp1=head->next;
       int i=0;
       while(i!=int(c/2)-1){
           temp=temp->next;
           temp1=temp1->next;
           i+=1;
       }
       node *mid=new node(a);
       temp->next=mid;
       mid->prev=temp;
       mid->next=temp1;
       temp1->prev=mid;
       
       
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
    list.insert_middle(6);
    list.display();
}
