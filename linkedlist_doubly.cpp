#include <iostream>
using namespace std;
#include <conio.h>
#include <malloc.h>
class node{
    public:
    int data;
    node *prev;
    node *next;
    node(){
        data=0;
        prev=NULL;
        next=NULL;
    }
    node(int a){
        data=a;
        prev=NULL;
        next=NULL;
    }
};
class LinkedList_D{
    public:
    node *head;
    void insert_beg(int a){
        node *temp=new node(a);
        if(head==NULL){
            head=temp;
            return;
        }
        else{
            node *curr=head;
            head->prev=temp;
            temp->next=head;
            head=temp;
        }
    }
    void insert_end(int a){
        node *temp=new node(a);
        if(head==NULL){
            head=temp;
            return;
        }
        node *curr=head;
        while(curr->next!=NULL){
            curr=curr->next;
        }
        curr->next=temp;
        temp->prev=curr;
    }
    void delete_beg(){
        node *temp=head;
        head=head->next;
        head->prev=NULL;
        free(temp);
    }
    void delete_end(){
        node *temp=head;
        node *temp1=head->next;
        while(temp1->next!=NULL){
            temp=temp->next;
            temp1=temp1->next;
        }
        temp->next=NULL;
        temp1->prev=NULL;
        free(temp1);
    }
    void display(){
        node *temp=head;
        while(temp->next!=NULL){
            cout<<temp->data<<"-->";
            temp=temp->next;
        }
        cout<<temp->data;
    }
};
int main(){
    LinkedList_D list;
    list.insert_end(1);
    list.insert_end(2);
    list.insert_end(3);
    list.insert_beg(4);
    list.delete_end();
    list.delete_beg();
    list.display();
}

