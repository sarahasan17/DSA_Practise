//Binary tree:Has at max 2 children node
//Binary search tree:First root, if the value is smaller add it to the left subtree and if the value is more add it to the right sub tree

#include <iostream>
using namespace std;
struct node{
    int data;
    node *left;
    node *right;
};
node* getnewnode(int a){
    node* newnode=new node();
    newnode->data=a;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
node* insert(node* root,int a){
        if(root==NULL){
            root=getnewnode(a);
        }
        else if(a<=root->data){
            root->left=insert(root->left,a);
        }
        else{
            root->right=insert(root->right,a);
        }
        return root;
    }
    
bool search(node *root,int a){
        if(root==NULL){
            return false;
        }
        else if(root->data==a){
            return true;
        }
        else if(a<=root->data){
            return search(root->left,a);
        }
        else{
            return search(root->right,a);
        }
}
node* findmin(struct node* root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}
struct node *deletenode(struct node* root,int data){
    if(root==NULL){
        return root;
    }
    else if(data<root->data){
        root->left=deletenode(root->left,data);
    }
    else if(data>root->data){
        root->right=deletenode(root->right,data);
    }
    else{
        if(root->left==NULL && root->right==NULL){
            delete root;
            root=NULL;
        }
        else if(root->right==NULL){
            struct node* temp=root;
            root=root->left;
            delete temp;
        }
        else if(root->left==NULL){
            struct node* temp=root;
            root=root->right;
            delete temp;
        }
        else{
            struct node* temp=findmin(root->right);
            root->data=temp->data;
            root->right=deletenode(root->right,temp->data);
        }
        
    }
    return root;
    
}
void preorder(struct node *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node *root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void inorder(struct node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    node* root=NULL;
    root=insert(root,2);
    root=insert(root,1);
    root=insert(root,4);
    root=insert(root,5);
    //inorder is increasing order for binary search tree
    cout<<"Inorder traversal"<<endl;
    inorder(root);
    cout<<endl;
    //postorder
    cout<<"Postorder traversal"<<endl;
    postorder(root);
    cout<<endl;
    //preorder
    cout<<"Preorder traversal"<<endl;
    preorder(root);
}
