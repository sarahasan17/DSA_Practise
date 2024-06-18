#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node*next;
    node(int a){
        data=a;
        next=NULL;
    }
};

class LinkedList{
    public:
    node *head;
    LinkedList(){
        head=NULL;
    }
    void insert_beg(int a){
        node *temp=new node(a);
        temp->next=head;
        head=temp;
    }
    void insert_end(int a){
        node *temp=new node(a);
        if(head==NULL){
            head=temp;
        }
        else{
            node *t=head;
            while(t->next!=NULL){
                t=t->next;
            }
            t->next=temp;
        }
    }
    void delete_beg(){
        node *t=head;
        head=head->next;
        free(t);
    }
    void delete_end(){
        node *t=head;
        if(t->next==NULL){
            head=NULL;
        }
        else{
            while(t->next->next!=NULL){
                t=t->next;
            }
            t->next=NULL;
        }
    }
    void display(){
        node *t=head;
        while(t!=NULL){
            cout<<t->data<<" ";
            t=t->next;
        }
        cout<<" "<<endl;
    }
};
int main(){
    LinkedList l=LinkedList();
    l.insert_beg(1);
    l.insert_beg(2);
    l.insert_end(3);
    l.insert_end(4);
    l.delete_end();
    l.delete_beg();
    l.display();
}
