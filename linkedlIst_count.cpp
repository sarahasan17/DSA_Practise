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
 
   int count(){
       node *curr=head;
       int count=0;
       while(curr!=NULL){
           count+=1;
           curr=curr->next;
       }
       return count;
   }
};
int main(){
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    cout<<list.count()<<endl;
}

