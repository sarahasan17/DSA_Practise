#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;
    node(){
        data=0;
        next=NULL;
    }
    node(int val){
        data=val;
        next=NULL;
    }
};
node* insert(node *head,int a){
    node* t=new node(a);
    if(head==NULL){
        head=t;
    }
    else{
        node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=t;
    }
    return head;
}
node* even_odd(node *head){
    node *t=head;
    node *even=new node();
    node *odd=new node();
    node *evenhead=NULL;
    node *oddhead=NULL;
    while(t!=NULL){
        node *t1=new node(t->data);
        if(t->data%2==0){
            if(evenhead==NULL){
                even=t1;
                evenhead=t1;
            }
            else{
                even->next=t1;
                even=even->next;
            }
        }
        else{
            if(oddhead==NULL){
                odd=t1;
                oddhead=t1;
            }
            else{
                odd->next=t1;
                odd=odd->next;
            }
        }
        t=t->next;
    }
    even->next=oddhead;
    head=evenhead;
    node *t4=evenhead;
    return head;
}
node* display(node* head){
    node *t=head;
    while(t!=NULL){
        cout<<t->data<<" ";
        t=t->next;
    }
    cout<<endl;
    return head;
}
int main(){
    node *head=NULL;
    head=insert(head,1);
    head=insert(head,2);
    head=insert(head,3);
    head=insert(head,4);
    head=even_odd(head);
    head=display(head);
}
