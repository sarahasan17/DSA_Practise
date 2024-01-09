#include<iostream>
#include <conio.h>
using namespace std;

class node{
    public:
    int data;
    node *next;
    node *prev;
    node(){
        data=0;
        next=prev=NULL;
    }
    node(int a){
        data=a;
        next=prev=NULL;
    }
};

class LinkedList_DC{
    public:
    node *head;
    void insert_beg(int a){
        node *temp=new node(a);
        if(head==NULL){
            head=temp;
            head->next=head->prev=head;
            return;
        }
        node *curr=head;
        while(curr->next!=head){
            curr=curr->next;
        }
        curr->next=temp;
        temp->prev=curr;
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
    void insert_end(int a){
        node *temp=new node(a);
        if(head==NULL){
            head=temp;
            head->next=head->prev=head;
            return;
        }
        node *curr=head;
        while(curr->next!=head){
            curr=curr->next;
        }
        curr->next=temp;
        temp->prev=curr;
        temp->next=head;
        head->prev=temp;
    }
    void delete_end(){
        node *curr=head;
        node *curr2=head->next;
        while(curr2->next!=head){
            curr=curr->next;
            curr2=curr2->next;
        }
        curr->next=head;
        curr2->prev=curr2->next=NULL;
        head->prev=curr;
        free(curr2);
    }
    void delete_beg(){
        node *curr=head;
        while(curr->next!=head){
            curr=curr->next;
        }
        curr->next=head->next;
        node *temp=head->next;
        temp->prev=head->prev;
        head=temp;
    }
    void display(){
        node *curr=head;
        while(curr->next!=head){
            cout<<curr->data<<"("<<curr->prev<<" "<<curr->next<<")-->"<<endl;
            curr=curr->next;
        }
        cout<<curr->data<<"("<<curr->prev<<" "<<curr->next<<")"<<endl;
    }
};
int main(){
    LinkedList_DC list;
    list.insert_end(1);
    list.insert_end(2);
    list.insert_end(3);
    list.insert_beg(4);
    list.delete_beg();
    list.delete_end();
    list.display();
}
