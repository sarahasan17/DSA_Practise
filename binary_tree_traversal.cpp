#include <iostream>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
};

node* newnode(int data){
    struct node* root=new node();
    root->data=data;
    root->left=root->right=NULL;
    return root;
}
void inorder(struct node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(struct node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main(){
    struct node* root=newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
    root->left->left=newnode(4);
    root->left->right=newnode(5);
    root->right->left=newnode(6);
    cout<<"Inorder Traversal"<<endl;
    inorder(root);
    cout<<endl;
    cout<<"Preorder traversal"<<endl;
    preorder(root);
    cout<<endl;
    cout<<"Postorder traversal"<<endl;
    postorder(root);
}
