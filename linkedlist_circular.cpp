#include <iostream>
using namespace std;
#include <conio.h>
#include <malloc.h>
class node{
    public:
    int data;
    node* next;
    node(){
        data=0;
        next=NULL;
    }
    node(int b){
        data=b;
        next=NULL;
    }
};
class LinkedList_C{
    public:
    node* head;
    void insert_beg(int a){
        node *temp=new node(a);
        node *curr=head;
        while(curr->next!=head){
            curr=curr->next;
        }
        curr->next=temp;
        temp->next=head;
        head=temp;
    }
    void insert_end(int a){
        if(head==NULL){
            node* temp=new node(a);
            head=temp;
            head->next=head;
        }
        else{
            node* temp=new node(a);
            node* curr=head;
            while(curr->next!=head){
                curr=curr->next;
            }
            curr->next=temp;
            temp->next=head;
        }
    }
    void delete_beg(){
        node* temp=head;
        node* curr=head;
        while(curr->next!=head){
            curr=curr->next;
        }
        curr->next=head->next;
        head=head->next;
        free(temp);
    }
    void delete_end(){
        node* curr=head;
        while(curr->next->next!=head){
            curr=curr->next;
        }
        curr->next=head;
        
    }
    void display(){
        node *curr=head;
        while(curr->next!=head){
            cout<<curr->data<<"-->";
            curr=curr->next;
        }
        cout<<curr->data<<endl;
    }
};
int main(){
    LinkedList_C list;
    list.insert_end(1);
    list.insert_end(2);
    list.insert_end(3);
    list.insert_beg(5);
    list.delete_end();
    list.delete_beg();
    list.display();
}
