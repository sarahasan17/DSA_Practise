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
 
   int middle_ele(){
       node *curr=head;
       int count=0;
       while(curr!=NULL){
           count+=1;
           curr=curr->next;
       }
       node *temp=head;
       int i=0;
       while(i!=int(count/2)){
           i++;
           temp=temp->next;
       }
       return temp->data;
   }
};
int main(){
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    cout<<list.middle_ele()<<endl;
}
