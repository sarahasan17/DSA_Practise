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
class LinkedList{
    public:
    node* head;
    void insert_beg(int a){
        node* temp=new node(a);
        temp->next=head;
        head=temp;
    }
    void insert_end(int a){
        if(head==NULL){
            node* temp=new node(a);
            head=temp;
        }
        else{
            node* temp=new node(a);
            node* curr=head;
            while(curr->next!=NULL){
                curr=curr->next;
            }
            curr->next=temp;
        }
    }
    void delete_beg(){
        node* temp=head;
        head=head->next;
        free(temp);
    }
    void delete_end(){
        node* curr=head;
        while(curr->next->next!=NULL){
            curr=curr->next;
        }
        curr->next=NULL;
        
    }
    void display(){
        node *curr=head;
        while(curr!=NULL){
            cout<<curr->data<<"-->";
            curr=curr->next;
        }    
        cout<<endl;
    }
};
int main(){
    LinkedList list;
    list.insert_end(1);
    list.insert_end(2);
    list.insert_end(3);
    list.insert_beg(5);
    list.delete_beg();
    list.delete_end();
    list.display();
}
